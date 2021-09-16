#include <stdio.h>

int main(){
    int w, h;
    while(scanf("%d%d", &w, &h) == 2){
        double temp = h / 100.0 ;
        printf("%.1f\n", w / (temp * temp));
    }
}
