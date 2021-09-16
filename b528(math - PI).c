#include <stdio.h>
#include <math.h>
#define PI acos(-1)

static inline int solve(){
    double n;
    while(scanf("%lf", &n) == 1){
        double temp = (acos(asin(n))*180)/PI;
        if(temp <= 180.0 && temp >= 0.0)
            printf("%.2f\n", temp);
        else
            puts("FAIL!");
    }
}

int main(){
    solve();
    return 0;
}
