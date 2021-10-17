#include <stdio.h>//	AC (48ms, 19.2MB)
#define SIZE 2000010
#define BUFSIZE 2097152

int list[SIZE];
int alone[SIZE];
int behind[SIZE];


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

static inline char readint(int *n){
    register char ch ;
    while((ch = readChar()) < '-')
        if(ch == EOF)return 0;
    if(ch == '-'){
        *n = readChar() ^ '0';
        while((ch = readChar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
        *n = ~*n + 1;
    }
    else {
        *n = ch ^ '0';
        while((ch = readChar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
    }
    return 1;
}

static inline char readUint(unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int main(){
    int t;
    readUint(&t);
    while(t--){
        int n, k;
        long long int ans = 0, temp;
        readUint(&n);
        readUint(&k);
        behind[n] = 0;
        for(int i = 0; i < n; i++)
            readUint(list + i);
        for(int i = 0; i < n; i++)
            readint(alone + i);
        for(int i = n - 1; i > -1; i--)
            behind[i] = behind[i + 1] + alone[i];
        for(int i = 0, j = 1; i < n; i++){
            while((j < n + 1)  && list[j] - list[i] <= k)j++;
            if(j >= n)break;
            temp = alone[i];
            temp *= behind[j];
            ans += temp;
        }
        printf("%lld\n", ans);
    }
}


/*#include <stdio.h>
#define SIZE 2000010
#define BUFSIZE 2097152

int list[SIZE];
int alone[SIZE];
int behind[SIZE];


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

static inline char readint(int *n){
    register char ch ;
    while((ch = readChar()) < '-')
        if(ch == EOF)return 0;
    if(ch == '-'){
        *n = readChar() ^ '0';
        while((ch = readChar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
        *n = ~*n + 1;
    }
    else {
        *n = ch ^ '0';
        while((ch = readChar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
    }
    return 1;
}

static inline char readUint(unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int main(){
    int t;
    readUint(&t);
    while(t--){
        int n, k;
        long long int ans = 0, temp;
        readUint(&n);
        readUint(&k);
        behind[n] = 0;
        for(int i = 0; i < n; i++)
            readUint(list + i);
        for(int i = 0; i < n; i++)
            readint(alone + i);
        for(int i = n - 1; i > -1; i--)
            behind[i] = behind[i + 1] + alone[i];
        for(int i = 0, j = 1; i < n; i++){
            while(list[j] - list[i] <= k){
                j++;
                if(j >= n)break;
            }
            if(j >= n)break;
            temp = alone[i];
            temp *= behind[j];
            ans += temp;
        }
        printf("%lld\n", ans);
    }
}
*/
/*#include <stdio.h>//	AC (0.3s, 17.2MB)
#define SIZE 2000010

int list[SIZE];
int alone[SIZE];
int behind[SIZE];

static inline int get_int(register int *n){
    register char ch ;
    while((ch = getchar()) < '-')
        if(ch == EOF)return 0;
    if(ch == '-'){
        *n = getchar() ^ '0';
        while((ch = getchar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
        *n = ~*n + 1;
    }
    else {
        *n = ch ^ '0';
        while((ch = getchar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
    }
    return 1;
}

static inline int get_Uint(register int *n){
    register char ch ;
    while((ch = getchar()) < '0')
        if(ch == EOF)return 0;
    *n = ch ^ '0';
    while((ch = getchar()) >= '0')
        *n = (*n << 1) + (*n << 3) + (ch ^ '0');
    return 1;
}

int main(){
    int t;
    get_Uint(&t);
    while(t--){
        int n, k;
        long long int ans = 0, temp;
        get_Uint(&n);
        get_Uint(&k);
        behind[n] = 0;
        for(int i = 0; i < n; i++)
            get_Uint(list + i);
        for(int i = 0; i < n; i++)
            get_int(alone + i);
        for(int i = n - 1; i > -1; i--)
            behind[i] = behind[i + 1] + alone[i];
        for(int i = 0, j = 1; i < n; i++){
            while(list[j] - list[i] <= k){
                j++;
                if(j >= n)break;
            }
            if(j >= n)break;
            temp = alone[i];
            temp *= behind[j];
            ans += temp;
        }
        printf("%lld\n", ans);
    }
}*/
