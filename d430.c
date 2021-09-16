#include <stdio.h>
#define SIZE 10000

static inline void solve(){
    int count = 0;
    char input[SIZE], *p;
    while(scanf("%s", input) == 1){
        p = input;
        while(!((*p >= 'a' && *p <= 'z') || (*p >= '@' && *p <= 'Z') || (*p >= '0' && *p <='9')) && *p != '\0')p++;
        if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <='9'))
            count++;
    }
    printf("%d", count);
}

int main(){
    solve();
    return 0;
}

