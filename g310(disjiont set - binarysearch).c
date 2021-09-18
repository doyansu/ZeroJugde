#include <stdio.h>//	AC (0.1s, 7.3MB)
#define MAXINPUT 1000000
#define BUFSIZE 65536 // 1MB -> AC (90ms, 8.3MB)

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int donutx[MAXINPUT];
int visited[MAXINPUT] = {0};

int binarySearch(int target, int left, int right){
    if(left > right)
        return right;
    int mid = (left + right) >> 1;
    if(donutx[mid] == target)
        return mid - 1;
    else if(donutx[mid] > target)
        return binarySearch(target, left, mid - 1);
    else
        return binarySearch(target, mid + 1, right);
}

int getMin(int index){
    if(index < 0)
        return -1;
    return index == visited[index] ? visited[index]-- : (visited[index] = getMin(visited[index]));
}

static inline void solve(){
    int n, ans = 0;
    readUint(&n);
    for(int i = 0; i < n; i++){
        readUint(donutx + i);
        visited[i] = i;
    }
    for(int i = 0, index; i < n; i++){
        readUint(&index);
        index = getMin(binarySearch(index, 0, n - 1));
        if(index >= 0)
            ans++;
    }
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>//	NA (score:95%)
#define MAXINPUT 1000001
#define BUFSIZE 1048576

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int donutx[MAXINPUT];
int visited[MAXINPUT] = {0};

int binarySearch(int target, int left, int right){
    if(left > right)
        return right;
    int mid = (left + right) >> 1;
    if(donutx[mid] == target)
        return mid - 1;
    else if(donutx[mid] > target)
        return binarySearch(target, left, mid - 1);
    else
        return binarySearch(target, mid + 1, right);
}

int getMin(int index){
    if(index < 0)return -1;
    return index == visited[index] ? visited[index]-- : (visited[index] = getMin(visited[index]));
}

static inline void solve(){
    int n, ans = 0;
    readUint(&n);
    for(int i = 0; i < n; i++){
        readUint(donutx + i);
        visited[i] = i;
    }
    for(int i = 0, left = 0, temp; i < n; i++){
        readUint(&temp);
        left = temp = binarySearch(temp, left, n - 1);
        temp = getMin(temp);
        if(temp >= 0)
            ans++;
    }
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}
*/

/*#include <stdio.h>//NA (score:80%)
#define MAXINPUT 1000001
#define BUFSIZE 1048576

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int donutx[MAXINPUT];
int visited[MAXINPUT] = {0};

int binarySearch(int target, int left, int right){
    if(left > right)
        return right;
    int mid = (left + right) >> 1;
    if(donutx[mid] == target)
        return mid - 1;
    else if(donutx[mid] > target)
        return binarySearch(target, left, mid - 1);
    else
        return binarySearch(target, mid + 1, right);
}

static inline void solve(){
    int n, ans = 0;
    readUint(&n);
    for(int i = 0; i < n; i++){
        readUint(donutx + i);
        //visited[i] = i
    }
    for(int i = 0, left = 0, temp; i < n; i++){
        readUint(&temp);
        left = temp = binarySearch(temp, left, n - 1);
        while(temp >= 0 && visited[temp])
            temp -= visited[temp];
        if(temp >= 0){
            ans++;
            if(temp == n - 1){
                ans += n - i - 1;
                break;
            }
            if(temp)
                visited[temp] = visited[temp - 1] + 1;
            else
                visited[temp] = 1;
        }
    }
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}
*/

/*#include <stdio.h>//NA (score:85%)
#define MAXINPUT 1000001
#define BUFSIZE 1048576

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int donutx[MAXINPUT];
int visited[MAXINPUT] = {0};

int binarySearch(int target, int left, int right){
    if(left > right)
        return right;
    int mid = (left + right) >> 1;
    if(donutx[mid] == target)
        return mid - 1;
    else if(donutx[mid] > target)
        return binarySearch(target, left, mid - 1);
    else
        return binarySearch(target, mid + 1, right);
}

static inline void solve(){
    int n, ans = 0;
    readUint(&n);
    for(int i = 0; i < n; i++){
        readUint(donutx + i);
    }
    for(int i = 0, right = n - 1, temp; i < n; i++){
        readUint(&temp);
        temp = binarySearch(temp, 0, right);
        while(temp >= 0 && visited[temp])
            temp -= visited[temp];
        if(temp >= 0){
            ans++;
            if(temp == right)
                right--;
            if(temp)
                visited[temp] = visited[temp - 1] + 1;
            else
                visited[temp] = 1;
        }
    }
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}*/


/*#include <stdio.h>//	NA (score:70%)
#define MAXINPUT 1000001

int donutx[MAXINPUT];
int visited[MAXINPUT] = {0};

int binarySearch(int target, int left, int right){
    if(left > right)
        return right;
    int mid = (left + right) >> 1;
    if(donutx[mid] == target)
        return mid - 1;
    else if(donutx[mid] > target)
        return binarySearch(target, left, mid - 1);
    else
        return binarySearch(target, mid + 1, right);
}

static inline void solve(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", donutx + i);
    }
    for(int i = 0, temp; i < n; i++){
        scanf("%d", &temp);
        temp = binarySearch(temp, 0, n - 1);
        while(temp >= 0 && visited[temp])
            temp -= visited[temp];
        if(temp >= 0){
            ans++;
            if(temp)
                visited[temp] = visited[temp - 1] + 1;
            else
                visited[temp] = 1;
        }
    }
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}*/
