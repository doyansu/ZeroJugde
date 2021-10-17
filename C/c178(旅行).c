#include <stdio.h>
#include <string.h>
#define MAXINT 0x7fffffff
#define NSIZE 15
int minValue(int x, int y){
     return (x>y?y:x);
}

int Rec(int R[][1<<NSIZE],int d[][NSIZE],int v,int S,int n){
    int ans=MAXINT;
    if(R[v][S]>=0)return R[v][S];
    for(int i=0;i<n;i++)if(!(S>>i&1))ans=minValue(ans,d[v][i]+Rec(R,d,i,S|(1<<i),n));
    return R[v][S]=ans;
}

void solve(){
    int n,v=0,S=(0|1<<v);
    int R[NSIZE][1<<NSIZE],d[NSIZE][NSIZE];
    memset(R,-1,sizeof(R));
    scanf("%d",&n);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)scanf("%d",&d[i][j]);
    for (int i=0;i<n;i++)R[i][(1<<n)-1]=d[i][0];
    printf("%d\n", Rec(R,d,v,S,n));
}

int main(){
    solve();
}
