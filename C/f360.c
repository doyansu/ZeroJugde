#include <stdio.h>
#include <string.h>
#define SIZE 1003

static inline void solve(){
    char str[SIZE];
    register char *p;
    while(gets(str) != NULL){
        p = str + strlen(str) - 1;
        if(*p > '0'){
            (*p)--;
            p = str;
        }
        else{
            while(*p == '0' && p >= str)
                *p-- = '9';
            (*p)--;
            if(p == str && *p == '0')p = str + 1;
            else p = str;
        }
        puts(p);
    }
}

int main(){
    solve();
    return 0;
}
