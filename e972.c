#include <stdio.h>

int main(){
    double n;
    while(scanf("%lf", &n) == 1){
        double coin;
        char type;
        scanf("%lf %c", &coin, &type);
        switch(type){
        case 'T':
            n /= 1.0;
            break;
        case 'U':
            n /= 30.9;
            break;
        case 'J':
            n /= 0.28;
            break;
        case 'E':
            n /= 34.5;
            break;
        }
        n -= coin;
        if(n > 0){
            if(n < 0.05)printf("%c %.2f\n", type, 0);
            else printf("%c %.2f\n", type, n);
        }
        else puts("No Money");
    }
}
