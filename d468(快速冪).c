#include <stdio.h>
#include <string.h>

static inline void solve(){
    char str[1000];
    long long int base, power;
    while(scanf("%lld", &base) == 1){
        if(base == -1){
            scanf("%s", str);
            if(*(str + strlen(str) - 1)&1)puts("-1");
            else puts("1");
        }
        else {
            scanf("%lld", &power);
            if(!base && !power)break;
            long long int ans = 1;
            while(power){
                if(power&1)ans *= base;
                base *= base;
                power >>= 1;
            }
            printf("%lld\n", ans);
        }
    }
    puts("All Over.");
}

int main(){
    solve();
    return 0;
}
