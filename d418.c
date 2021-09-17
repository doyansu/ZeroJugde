#include <stdio.h>
#define OUTSIZE 1000

static inline void solve(){
    int test;
    char out[OUTSIZE];
    out[OUTSIZE] = '\0';
    scanf("%d", &test);
    while(test--){
        int n, factor = 9;
        char *p = out + OUTSIZE - 1;
        scanf("%d", &n);
        while(factor > 1){
            if(n % factor)
                factor--;
            else {
                n /= factor;
                *p-- = '0' ^ factor;
            }
        }
        if(*p == '\0')
            puts("1");
        else if(n == 1)
            puts(++p);
        else
            puts("-1");
    }
}

int main(){
    solve();
    return 0;
}
