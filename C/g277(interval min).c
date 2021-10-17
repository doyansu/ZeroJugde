/*
https://web.ntnu.edu.tw/~algo/Sequence2.html#6

Sparse Table

搭配前綴和找到幸運數字
*/

#include <stdio.h>//AC (29ms, 24.4MB)
#include <math.h>
#define SIZE 300001
#define BUFSIZE 1048576

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

int list[SIZE];
int RMQ[20][SIZE];
long long int prefix[SIZE] = {0};

int query(int left, int right){
    int power = log2(abs(right - left));
    int Lindex = RMQ[power][left];
    int Rindex = RMQ[power][++right - (1 << power)];
    return list[Lindex] > list[Rindex] ? Rindex : Lindex;
}

int searchLuckyNumber(int left, int right){
    if(left == right)return list[left];
    int index = query(left, right);
    if(prefix[right] - prefix[index] < prefix[index - 1] - prefix[left - 1])return searchLuckyNumber(left, --index);
    else return searchLuckyNumber(++index, right);
}

static inline void solve(){
    int n;
    readUint(&n);
    readUint(list);
    int *listp = list, *listend = list + n;
    long long int *prefixp = prefix;
    *prefixp++ = *listp++ ;
    while(listp < listend){
        readUint(listp);
        *prefixp++ = *(prefixp - 1) + *listp++;
    }
    for(int i = 0; i < n; i++)
        RMQ[0][i] = i;
    for(int power = 1; (1 << power) <= n; power++){
        for(int i = 0; i + (1 << power) <= n; i++){
            int left = RMQ[power - 1][i];
            int right = RMQ[power - 1][i + (1 << (power - 1))];
            RMQ[power][i] = (list[left] > list[right] ? right : left);
        }
    }
    printf("%d\n", searchLuckyNumber(0, n - 1));
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>//	AC (71ms, 23.4MB)
#include <math.h>
#define SIZE 300001

int list[SIZE];
int RMQ[20][SIZE];
long long int prefix[SIZE] = {0};

int query(int left, int right){
    int power = log2(abs(right - left));
    int Lindex = RMQ[power][left];
    int Rindex = RMQ[power][++right - (1 << power)];
    return list[Lindex] > list[Rindex] ? Rindex : Lindex;
}

int searchLuckyNumber(int left, int right){
    if(left == right)return list[left];
    int index = query(left, right);
    if(prefix[right] - prefix[index] < prefix[index - 1] - prefix[left - 1])return searchLuckyNumber(left, --index);
    else return searchLuckyNumber(++index, right);
}

static inline void solve(){
    int n;
    scanf("%d", &n);
    scanf("%d", list);
    int *listp = list, *listend = list + n;
    long long int *prefixp = prefix;
    *prefixp++ = *listp++ ;
    while(listp < listend){
        scanf("%d", listp);
        *prefixp++ = *(prefixp - 1) + *listp++;
    }
    for(int i = 0; i < n; i++)
        RMQ[0][i] = i;
    for(int power = 1; (1 << power) <= n; power++){
        for(int i = 0; i + (1 << power) <= n; i++){
            int left = RMQ[power - 1][i];
            int right = RMQ[power - 1][i + (1 << (power - 1))];
            RMQ[power][i] = (list[left] > list[right] ? right : left);
        }
    }
    printf("%d\n", searchLuckyNumber(0, n - 1));
}

int main(){
    solve();
    return 0;
}*/


/*#include <stdio.h>//	AC (63ms, 42.7MB)
#define SIZE 300001
#define MAXINPUT 10000001
#define BUFSIZE 1048576

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

int list[SIZE];
int Index[MAXINPUT];
long long int prefix[SIZE] = {0};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMid(int left, int right){
    swap(list + ((left + right) >> 1), list + right);
    int cmpvalue = list[right];
    for(int i = left; i < right; i++)
        if(list[i] < cmpvalue)
            swap(list + left++, list + i);
    swap(list + left, list + right);
    return left;
}

void myqsort(int left, int right){
    if(left < right){
        int mid = getMid(left, right);
        myqsort(left, mid - 1);
        myqsort(mid + 1, right);
    }
}

static inline void solve(){
    int n;
    readUint(&n);
    readUint(list);
    prefix[0] = list[0];
    Index[list[0]] = 0;
    for(int i = 1; i < n; i++){
        readUint(list + i);
        prefix[i] = prefix[i - 1] + list[i];
        Index[list[i]] = i;
    }
    myqsort(0, n - 1);
    int left = 0, right = n - 1;
    for(int i = 0; i < n; i++){
        int temp = Index[list[i]];
        if(temp >= left && temp <= right){
            if(prefix[right] - prefix[temp] < prefix[temp - 1] - prefix[left - 1])
                right = temp - 1;
            else
                left = temp + 1;
        }
        if(left == right){
            printf("%d", prefix[left] - prefix[left - 1]);
            break;
        }
    }

}

int main(){
    solve();
    return 0;
}*/



/*#include <stdio.h>//AC (0.1s, 42.8MB)
#include <stdlib.h>
#define SIZE 300001
#define MAXINPUT 10000001

int list[SIZE];
int index[MAXINPUT];
long long int prefix[SIZE] = {0};

int cmp(const int *a, const int *b){
    return *a - *b;
}

static inline void solve(){
    int n;
    scanf("%d", &n);
    scanf("%d", list);
    prefix[0] = list[0];
    index[list[0]] = 0;
    for(int i = 1; i < n; i++){
        scanf("%d", list + i);
        prefix[i] = prefix[i - 1] + list[i];
        index[list[i]] = i;
    }
    qsort(list, n, sizeof(int), cmp);
    int left = 0, right = n - 1;
    for(int i = 0; i < n; i++){
        int temp = index[list[i]];
        if(temp >= left && temp <= right){
            if(prefix[right] - prefix[temp] < prefix[temp - 1] - prefix[left - 1])
                right = temp - 1;
            else
                left = temp + 1;
        }
        if(left == right){
            printf("%d", prefix[left] - prefix[left - 1]);
            break;
        }
    }

}

int main(){
    solve();
    return 0;
}*/










/*#include <stdio.h>
#define SIZE 300001

int list[SIZE];
int RMQ[20][SIZE];
long long int prefix[SIZE] = {0};

int searchLuckyNumber(int left, int right){
    if(left == right)return list[left];
    int min = list[left], index = left;
    for(int i = left + 1; i <= right; i++)
        if(list[i] < min){
            min = list[i];
            index = i;
        }
    if(prefix[right] - prefix[index] < prefix[index - 1] - prefix[left - 1])return searchLuckyNumber(left, index - 1);
    else return searchLuckyNumber(index + 1, right);
}

static inline void solve(){
    int n;
    scanf("%d", &n);
    scanf("%d", list);
    prefix[0] = list[0];
    for(int i = 1; i < n; i++){
        scanf("%d", list + i);
        prefix[i] = prefix[i - 1] + list[i];
    }
    printf("%d\n", searchLuckyNumber(0, n - 1));
}

int main(){
    solve();
    return 0;
}
*/
