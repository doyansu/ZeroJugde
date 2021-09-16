#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int list[SIZE]={0};
int n,m;

int comp(const void*a,const void*b){return *(int*)a-*(int*)b;}

void dfs(int level,int visit,int start){
    //printf("level %d v %d\n",level,visit);
    if(level==m){
        int index=0;
        while(visit){
            if(visit&1)printf("%d ",list[index]);
            visit>>=1;
            ++index;
        }
        putchar('\n');
        return;
    }
    for(int i=start;i<n;++i){
        dfs(level+1,visit|(1<<i),i+1);

    }
}

int main(){
    while(scanf("%d",&n)){
        if(n==0)break;
        for(int i=0;i<n;++i)scanf("%d",&list[i]);
        scanf("%d",&m);
        qsort(list,n,sizeof(int),comp);
        dfs(0,0,0);
        putchar('\n');
    }
}
