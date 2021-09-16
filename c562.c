#include <stdio.h>

int main(){
    long long int n;
    while(scanf("%lld",&n)!=EOF){
        int fn=0;
        if(n==0)fn=1;
        while(n){
            switch(n%10){
            case 8:
                ++fn;
            case 0:
            case 6:
            case 9:
                ++fn;
                break;
            }
            n/=10;
        }
        printf("%d\n",fn);
    }
}
