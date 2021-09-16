#include <stdio.h>// NA67%
#include <math.h>

int main(){
    long long int n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        long long int d=(2-m)*(2-m)+8*m*n;
        double f=sqrt(d);
        if((f-(double)(int)f)==0)puts("Go Kevin!!");
        else puts("No Stop!!");
    }
}


/*#include <stdio.h>//AC 1ms

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int d=1;
        if(m==0)n=0;
        while(n>0){
            n-=d;
            d+=m;
        }
        if(n==0)puts("Go Kevin!!");
        else puts("No Stop!!");
    }
}*/
