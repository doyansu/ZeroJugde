#include <stdio.h>//	AC (91ms, 180KB)
#include <math.h>
#define BUFSIZE 131072

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

static inline char readint(int *input){
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

int main(){
    int a, b, c, d, r;
    while(readint(&a)){
        readint(&b);
        readint(&c);
        readint(&d);
        readint(&r);
        if(llabs(a - c) + llabs(b - d) > r) puts("alive");
        else puts("die");
    }
}

/*#include <stdio.h>//	AC (0.2s, 68KB)
#include <math.h>

static inline int get_int(int *n){
    *n = 0;
    int si = 1;
    register char tc = getchar();
    if(tc == EOF)return 0;
    while(tc < '0' && tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0'){
        *n = (*n <<1) + (*n <<3) + (tc ^ '0');
        tc = getchar();
    }
    *n *= si;
    return 1;
}

int main(){
    int a, b, c, d, r;
    while(get_int(&a)){
        get_int(&b);
        get_int(&c);
        get_int(&d);
        get_int(&r);
        if(llabs(a - c) + llabs(b - d) > r) puts("alive");
        else puts("die");
    }
}*/
