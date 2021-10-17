#include <stdio.h>
#define BUFSIZE 524288

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

static inline char readUint(unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline int get_Uint(int *n){
    register char tc ;
    while((tc = getchar()) < '0')
        if(tc == EOF)return 0;
    *n = tc ^ '0';
    while((tc = getchar()) >= '0')
        *n = (*n << 1) + (*n << 3) + (tc ^ '0');
    return 1;
}

int main(){
    int ans = 0, temp = 0, input;
    readUint(&input);
    while(readUint(&input)){
        temp = ans & (temp ^ input);
        ans = temp | (ans ^ input);
    }
    printf("%d", ans);
}

/*t3 = t2 & t0;
    t2 &= ~t3;
    t0 &= ~t3;
    t2 ^= t1 & t0;
    t1 ^= t0;*/
