#include <stdio.h>
#include <math.h>

int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}

int main(){
    int a,b,c,d;
    char oper;
    while(scanf("%d%d%d%d %c",&a,&b,&c,&d,&oper)!=EOF){
        //printf("%d%d%d%d %c\n",a,b,c,d,oper);
        int son,mon;
        switch(oper){
        case '+':
            son=a*d+b*c;
            mon=b*d;
            break;
        case '-':
            son=a*d-b*c;
            mon=b*d;
            break;
        case '*':
            son=a*c;
            mon=b*d;
            break;
        case '/':
            son=a*d;
            mon=b*c;
            break;
        }
        int g=gcd(son,mon);
        son/=g;
        mon/=g;
        if(son==0)putchar('0');
        else if(abs(son)==abs(mon)){
            if(son==mon)putchar('1');
            else printf("-1");
        }
        else if(mon==1)printf("%d",son);
        else if(mon==-1)printf("%d",-son);
        else if(son<0 && mon>0 || son>0 && mon<0)printf("-%d/%d",abs(son),abs(mon));
        else printf("%d/%d",abs(son),abs(mon));
        putchar('\n');
    }
}
