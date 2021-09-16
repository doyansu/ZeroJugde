#include <stdio.h>
#define BUFSIZE 2097152
#define SIZE 1000


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

static inline char readint(register int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    if(ch == '-'){
        ch = readChar();
        flag = -1;
    }
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[13];
    char *p = buf + 11;
    *(p + 1) = '\0';
    if(output < 0){
        putchar('-');
        output = ~output + 1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar(' ');
}

int main(){
    int n, list[SIZE];
    while(readint(&n)){
        for(int i = n - 1; i >= 0; i--){
            readint(list + i);
            list[i] *= i;
        }
        for(int i = --n; i > 0; i--)
            putint(list[i]);
        if(n == 0)putchar('0');
        putchar('\n');
    }

}
