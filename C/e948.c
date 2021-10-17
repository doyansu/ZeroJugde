#include <stdio.h>

static inline void solve(){
    int n, g;
    scanf("%d", &n);
    double a, h, w;
    while(n--){
        scanf("%d%lf%lf%lf", &g, &a, &h, &w);
        if(g)printf("%.2f\n", 13.7 * w + 5 * h - 6.8 * a + 66);
        else printf("%.2f\n", 9.6 * w + 1.8 * h - 4.7 * a + 655);
    }
}

int main(){
    solve();
    return 0;
}
