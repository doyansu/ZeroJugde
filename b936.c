#include <stdio.h>

/*long long int solve(long long int n,long long int m){//AC 1.5S
    if(n<m)return 0;
    long long int temp=1;
    if(n%2==0){
        if(n>>1>=m)temp=2*solve(n>>1,m);
    }
    else if((n+1)>>1>m){
        temp=solve((n+1)>>1,m);
        if((n-1)>>1>=m)temp+=solve((n-1)>>1,m);
    }
    return temp;
}*/

int main(){
    long long int n,m,count=1;
    while (scanf("%lld%lld",&n,&m)!=EOF){
        //printf("my%lld\n",solve(n,m));
        if(m>n){//AC 0.5S
            puts("0");
            continue;
        }
        long long int l=1,r=0;
        while(n>>1>=m){
            if(n%2)r=(r<<1)+l;
            else l=(l<<1)+r;
            n>>=1;
            //printf("n%d L %d r %d\n",n,l,r);
        }
        l+=r;
        if(n%2 && (n>>1)+1==m)l+=r;
        printf("%lld\n",l);
    }
}
