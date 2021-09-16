#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")//	AC (0.2s, 2.1MB)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <stdio.h>
#define BUFSIZE 1048576

char out[BUFSIZE];
char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;

static inline char readChar(){
    if(temp == end){
        if(end < buf + BUFSIZE)
            return 0;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline void solve(){
    register char ch, isOdd = 0, *op = out, *max = out + BUFSIZE;
    while(ch = readChar()){
        if(ch == ' ')
            isOdd = ~isOdd;
        else{
            if(isOdd){
                *op++ = ' ';
                isOdd = 0;
            }
            *op++ = ch;
            if(op > max){
                *op = '\0';
                fputs(out, stdout);
                op = out;
            }
        }
    }
    *op = '\0';
    fputs(out, stdout);
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>
#define BUFSIZE 1048576

char out[BUFSIZE];

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return 0;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

int main(){
    char ch, isOdd = 0, *op = out, *end = out + BUFSIZE - 500;
    while(ch = readChar()){
        if(ch == ' ')
            isOdd = ~isOdd;
        else{
            if(isOdd){
                *op++ = ' ';
                isOdd = 0;
            }
            *op++ = ch;
            if(op > end){
                *op = '\0';
                fputs(out, stdout);
                op = out;
            }
        }
    }
    *op = '\0';
    fputs(out, stdout);
    return 0;
}*/
