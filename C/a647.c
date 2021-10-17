#include <stdio.h>

float myabs(float f){
    return f>0?f:-f;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int m,p;
        scanf("%d%d",&m,&p);
        float d=100*((float)p/(float)m-1);
        if(d>0)d+=0.00001;
        else if(d<0)d-=0.00001;
        if(myabs(d)*100.0<1.0)printf("0.00");
        else printf("%.2f",d);
        putchar('%');
        if(d>=10.0 || d<=-7.0)printf(" dispose\n");
        else printf(" keep\n");
    }
}
