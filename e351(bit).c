#include <stdio.h>//	AC (20ms, 1.1MB)
#define FIRST 0x8000000000000000
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

static inline char readULLint(unsigned long long int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void putULLint(register unsigned long long int output){
    if(output == 0)putchar('0');
    char buf[30];
    char *p = buf + 28;
    *(p + 1) = '\0';
    while(output){
        *p-- = '0' | (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar('\n');
}

int main(){
    unsigned long long int a, b;
    while(readULLint(&a)){
        readULLint(&b);
        unsigned long long int ans = 0;
        for(unsigned long long int i = FIRST; i > 0; i >>= 1){
            if((a&i) == (b&i))ans |= a&i;
            else break;
        }
        putULLint(ans);
    }
}

/*#include <stdio.h>//	AC (52ms, 64KB)
#define FIRST 0x8000000000000000

int main(){
    unsigned long long int a, b;
    while(scanf("%llu%llu", &a, &b) == 2){
        unsigned long long int ans = 0;
        for(unsigned long long int i = FIRST; i > 0; i >>= 1){
            if((a&i) == (b&i))ans |= a&i;
            else break;
        }
        printf("%llu\n", ans);
    }
}*/

