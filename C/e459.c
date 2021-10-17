#include <stdio.h>
#define SIZE 100001

long long int myllabs(long long int n){
    return n > 0 ? n : -n;
}

long long int gcd(long long int n, long long int m){
    return n%m == 0 ? m : gcd(m, n%m);
}

static inline void solve(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long int x1, x2, y1, y2, dx, dy;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        dx = myllabs(x2 - x1);
        dy = myllabs(y2 - y1);
        if(dx && dy)
            printf("%lld\n", gcd(dy, dx) + 1);
        else if(dx)
            printf("%lld\n", dx + 1);
        else if(dy)
            printf("%lld\n", dy + 1);
        else
            puts("1");
    }
}

int main(){
    solve();
    return 0;
}
