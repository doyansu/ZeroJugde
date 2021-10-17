#include <stdio.h>
#include <math.h>

static inline void solve(){
    double t, n;
    while(scanf("%lf%lf", &t, &n) == 2){
        printf("%.3lf\n", t * -log2(n));
    }
}

int main(){
    solve();
    return 0;
}
