#include <stdio.h>
#include <math.h>
#define OLACONST 0.577215664901532


int main(){
    int n;
    while(scanf("%d", &n) == 1){
        if(n > 100)
            printf("%.3f\n", log(n) + OLACONST);
        else {
            double ans = 0;
            for(int i = 1; i <= n; i++)
                ans += 1.0 / i;
            printf("%.3f\n", ans);
        }
    }
    return 0;
}
