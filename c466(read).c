#include <stdio.h>
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

static inline int solve(){
    int count = 0;
    char ch;
    while((ch = readChar()) == '-')
        count++;
    if(ch == '0')puts("0");
    else {
        if(count&1)
            putchar('-');
        putchar(ch);
    }
}

int main(){
    solve();
    return 0;
}
