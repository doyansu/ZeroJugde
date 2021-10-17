#include <stdio.h>
#define SIZE 10001
#define MOD 1000000007

int hanoi(char *now,char *taget,int *step,int n){
    char subta[SIZE];
    int steps=0,base=1;
    while(now[base+1]==now[1] && base<n-1)
        ++base;
    subta[n]=taget[n];
    for(int i=n;i>1;--i)
        subta[i-1]=now[i]==subta[i]?subta[i]:6-now[i]-subta[i];
    char temp=now[base];
    for(int i=base+1;i<=n;++i){
        if(now[i]==subta[i])continue;
        if(temp+now[i]+subta[i]==6)++steps;
        else{
            steps=(steps+step[base])%MOD;
            base=i-1;
            temp=6-now[i]-subta[i];
        }
    }
    temp=subta[n-1];
    for(int i=base;i;--i){
        if(temp==taget[i])continue;
        temp=6-temp-taget[i];
        steps=(steps+step[i-1])%MOD;
    }
    return steps;
}

int main(){
    int n;
    int step[SIZE]={1};
    for(int i=1;i<SIZE;++i)step[i]=(step[i-1]<<1)%MOD;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        char now[SIZE],taget[SIZE];
        for(int i=1;i<=n;++i)
            scanf("%d",&now[i]);
        for(int i=1;i<=n;++i)
            scanf("%d",&taget[i]);
        while(now[n]==taget[n] && n)
            --n;
        if(n)
            printf("%d\n",hanoi(now,taget,step,n));
        else
            puts("0");
    }

}
