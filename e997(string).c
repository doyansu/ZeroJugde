#include <stdio.h>
#include <string.h>
#define SIZE 1000

static inline void solve(){
    int n, len = 0;
    char str[SIZE];
    *str = ' ';
    gets(str + 1);
    scanf("%d", &n);
    register char *p = str + strlen(str + 1);
    while(*p != '\0'){
        if(*p == ' '){
            *p = '\0';
            if(++len == n){
                fputs(++p, stdout);
                break;
            }
        }
        p--;
    }
}

int main(){
    solve();
    return 0;
}
