#include <stdio.h>
#include <math.h>

int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==0)break;
        int i,sum=1;
        double temp=sqrt(n);
        for(i=2;i<=temp;++i){
            if(n%i==0)
                sum+=i+n/i;
        }
        if(sum==n)printf("=%d\n",n);
        else{
            int comp=1;
            temp=sqrt(sum);
            for(i=2;i<=temp;++i){
                if(sum%i==0)
                    comp+=i+sum/i;
            }
            if(comp==n)
                printf("%d\n",sum);
            else
                puts("0");
        }
    }
}
