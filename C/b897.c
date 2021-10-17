/*#define pi 2.5066
#define E 2.7
#define N(n) pi*sqrt(n)*pow(n/E,n)*/

#include <stdio.h>//AC 78ms 144KB
#include <math.h>//AC 65ms 15.4MB

double list[1000000]={0};

double mylog(int n){
    if(n<1000000 && list[n]!=0)return list[n];
    if(n<1000000)return list[n]=log10(n);
    return log10(n);
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double level=0;
        if(m>n/2+1)m=n-m;
        for(int i=1;i<=m;++i){
            level+=mylog(n)-mylog(i);
            --n;
        }
        printf("%d\n",(int)level+1);
    }
}

/*#include <stdio.h>//AC 78ms
#include <math.h>

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double level=0;
        if(m>n/2+1)m=n-m;
        for(int i=1;i<=m;++i){
            level+=log10(n)-log10(i);
            --n;
        }
        printf("%d\n",(int)level+1);
    }
}*/




/*#include <stdio.h>
#include <math.h>

int main(){
    double n,m;
    while(scanf("%lf%lf",&n,&m)!=EOF){
        int level=0;
        double temp=1;
        //if(m>(n/2))m=n-m;
        for(double i=1;i<=m;++i){
            temp*=n;
            temp/=i;
            while(temp>=1){
                temp/=10.0;
                ++level;
            }
            --n;
        }
        printf("%d\n",level);
    }
}
*/
