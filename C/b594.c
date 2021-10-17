#include <stdio.h>
#define SIZE 101
#define MAXINF 0x7fffffff


int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==0)break;
        int ans=0;
        for(int x=n/2+1;x>1;--x){
            int temp=0;
            for(int i=x;i>0;--i){
                temp+=i;
                if(temp<n);
                else{
                    if(temp==n)++ans;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
}
