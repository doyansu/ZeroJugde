#include <stdio.h>//AC 9ms
#include <stdlib.h>
#define SIZE 101

int n,count;

int comp(const void*a,const void*b){return *(int*)a-*(int*)b;}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int list[SIZE]={0};
        for(int i=0;i<n;++i)scanf("%d",&list[i]);
        qsort(list,n,sizeof(int),comp);
        count=0;
        for(int x=0;x<n;++x){
            for(int y=x+1;y<n;++y){
                for(int z=y+1;z<n;++z){
                    if(list[x]*list[x]+list[y]*list[y]==list[z]*list[z])++count;
                }
            }
        }
        printf("%d\n",count);
    }
}

/*#include <stdio.h>//AC 12ms
#include <stdlib.h>
#define SIZE 101

int n,count;

int comp(const void*a,const void*b){return *(int*)a-*(int*)b;}

void dfs(int *list,int level,int start,int sum){
    if(start==n)return;
    if(level==2){
        for(int i=start;i<n;++i)if(sum==list[i]*list[i])++count;
        return;
    }
    for(int i=start;i<n;++i){
        dfs(list,level+1,i+1,sum+list[i]*list[i]);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int list[SIZE]={0};
        for(int i=0;i<n;++i)scanf("%d",&list[i]);
        qsort(list,n,sizeof(int),comp);
        count=0;
        dfs(list,0,0,0);
        printf("%d\n",count);
    }
}*/

