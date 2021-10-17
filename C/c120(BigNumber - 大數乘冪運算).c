#include <stdio.h>
#define SIZE 200
#define MOD 10000000000000

static inline void solve(){
    int n;
    register long long int len , carry;
    while(scanf("%d", &n) == 1){
        printf("%d!\n", n);
        long long int result[SIZE] = {1};
        len = 1;
        carry = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < len; j++){
                result[j] = result[j] * i + carry;
                carry = result[j] / MOD;
                result[j] -= carry * MOD;
                if(carry && (j + 1) == len)len++;
            }
        }
        printf("%lld", result[--len]);
        for(int i = --len; i >= 0; i--)
            printf("%013lld", result[i]);
        putchar('\n');
    }
}

int main(){
    solve();
    return 0;
}
