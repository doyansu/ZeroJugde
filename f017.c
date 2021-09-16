#include <stdio.h>
#include <string.h>
#define SIZE 36

static inline void solve(){
    char str[SIZE];
    int len;
    register char *p;
    while(gets(str) != NULL){
        len = strlen(str);
        p = str;
        putchar(*p++);
        while(--len){
            putchar('-');
            putchar(*p++);
        }
        putchar('\n');
    }
}

int main(){
    solve();
    return 0;
}
