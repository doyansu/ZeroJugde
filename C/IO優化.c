#include <stdio.h>
#define BUFSIZE 1048576//<- pow(2, n)

// readint

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

static inline char readint(register int *input){
    register char ch;
    char flag = 0;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    if(ch == '-'){
        ch = readChar();
        flag = 1;
    }
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    if(flag)
        *input = ~(*input) + 1;
    return 1;
}

// unsinged

static inline char readUint(register unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

// putint

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
    putchar('\n');
}

// other 
static inline int get_int(register int *n){
    register char tc ;
    int si = 1;
    while((tc = getchar()) < '0' && tc != '-')
        if(tc == EOF)return 0;
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    *n = tc ^ '0';
    while((tc = getchar()) >= '0')
        *n = (*n << 1) + (*n << 3) + (tc ^ '0');
    *n *= si;
    return 1;
}
