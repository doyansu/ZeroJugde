#include <stdio.h>

int main(){
    double r,R;
    while(scanf("%lf",&r)!=EOF){
        R=r*9.0/5.0+32;
        printf("%g",R);
        putchar('\n');
    }
}
