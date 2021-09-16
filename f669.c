#include <stdio.h>
#include <string.h>
#define SIZE 103
#define BUFSIZE 65536

static inline void solve(){
    char str[SIZE], *p;
    fgets(str + 1, SIZE, stdin);
    *str = '\0';
    p = str + strlen(str + 1);
    while(*(--p) != '\0')
        putchar(*p);
}

int main(){
    solve();
    return 0;
}
