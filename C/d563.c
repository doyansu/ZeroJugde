#include <stdio.h>
#define SIZE 100000
#define BUFSIZE 1000000

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return (*temp)++;
}

static inline char readint(int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0'){
        if(ch == EOF) return 0;
        if(ch == '-') flag = -1;
    }
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

static inline int get_int(){//	AC (5ms, 480KB)
    int n = 0, si = 1;
    register char tc = getchar();
    while(tc < '0' && tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0'){
        n = (n << 1) + (n << 3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}

static inline void putint(int output){
    int size = 0;
    char buf[1000];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        buf[size++] = '0' ^ (output % 10);
        output /= 10;
    }
    for(size--; size > -1; size--)putchar(buf[size]);
    //putchar('');
}

int main(){
    int n;
    int list[SIZE] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++)list[i] = get_int();
    int i = 0, j = n - 1, dif = 0, ans = 0;
    while(j > 0 || i < n){
        if(dif >= 0){
            if(dif == 0)ans++;
            dif -= list[i++];
        }
        else dif += list[j--];
    }
    putint(ans);
}
