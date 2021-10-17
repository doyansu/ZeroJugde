#include <stdio.h>

int main(){
    double a, b, c, d;
    while(scanf("%lf%lf%lf%lf", &a, &b, &c, &d) == 4){
        if(a == 0 && b == 0 && c == 0 && d ==0)break;
        double jugde = a * d - b * c;
        if(jugde)printf("%.5f %.5f\n%.5f %.5f\n", d / jugde, -b / jugde, -c / jugde, a / jugde);
        else puts("cheat!");
    }
}
