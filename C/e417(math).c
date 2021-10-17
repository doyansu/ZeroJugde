#include <stdio.h>//	AC (61ms, 144KB)
#define BUFSIZE 65536

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

static inline char readULLint(register unsigned long long int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int main(){
    unsigned long long int  n;
    while(readULLint(&n)){
        unsigned long long int sum = 0, prefix = 0,temp;
        for(int i = 0; i < n; i++){
            readULLint(&temp);
            sum += prefix * temp;
            prefix += temp;
        }
        printf("%llu\n", sum);
    }
}


/*#include <stdio.h>//	AC (1.8s, 80KB)

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        unsigned long long int sum = 0, prefix = 0,temp;
        for(int i = 0; i < n; i++){
            scanf("%llu", &temp);
            sum += prefix * temp;
            prefix += temp;
        }
        printf("%llu\n", sum);
    }
}*/

/*#include <stdio.h>//	AC (1.7s, 7.6MB)
#define MAXSIZE 1000001

unsigned long long int prefix[MAXSIZE] = {0};

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        unsigned long long int sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%llu", prefix + i);
            prefix[i] += prefix[i - 1];
        }
        for(int i = 1; i < n; i++)
            sum += (prefix[i] - prefix[i - 1]) * (prefix[n] - prefix[i]);
        printf("%llu\n", sum);
    }
}*/
