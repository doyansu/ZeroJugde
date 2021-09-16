#include <stdio.h>

long long int func(long long int x,long long int a,long long int b,long long int c,long long int d,long long int e,long long int f){
    return a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+f;
}

int main(){
    long long int a,b,c,d,e,f;
    while(scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f)!=EOF){
        int jugde=1;
        if(a==0 && b==0 && c==0 && d==0 && e==0 && f==0){
            puts("Too many... = =\"");
            continue;
        }
        for(long long int x=-35;x<36;++x){
            long long int t1=func(x,a,b,c,d,e,f),t2=func(x+1,a,b,c,d,e,f);
            if(t1*t2<0){
                jugde=0;
                printf("%lld %lld\n",x,x+1);
            }
            else if(t1==0){
                jugde=0;
                printf("%lld %lld\n",x,x);
            }
        }
        if(jugde){
            printf("N0THING! >");
            putchar('\\');
            putchar('\\');
            putchar('\\');
            puts("<");
        }
    }
}
