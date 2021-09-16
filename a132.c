#include <stdio.h>
#include <string.h>
#define SIZE 33

static inline void solve(){
    int n, len = 0;
    while(scanf("%d", &n) == 1 && n){
        int parity = 0;
        char str[SIZE], *p = str + 31;
        *(p + 1) = '\0';
        while(n){
            if(n&1){
                *p-- = '1';
                parity++;
            }
            else *p-- = '0';
            n >>= 1;
        }
        printf("The parity of %s is %d (mod 2).\n", ++p, parity);

    }
}

int main(){
    solve();
    return 0;
}
