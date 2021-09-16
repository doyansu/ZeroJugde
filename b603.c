#include <stdio.h>

int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}

int main(){
    int x1,y1,x2,y2;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF){
        int a,b,c,d;
        int as=y2-y1,am=(x2-x1)*(x2-x1);
        int g=gcd(as,am);
        as/=g;
        am/=g;
        a=am;
        b=as;
        c=-2*as*x1;
        d=y1*am+as*x1*x1;
        printf("%dy = %dx^2 + %dx + %d\n",a,b,c,d);

    }
}
