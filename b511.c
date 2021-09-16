#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int n,taget,outindex=0;
int* output[1000];

void dfs(int *array,int *cvalue,int start){
    int sum=0;
    for(int i=0;i<n;++i)sum+=array[i]*cvalue[i];
    if(sum==taget){
        int index=0;
        int *out=malloc(SIZE*sizeof(int));
        for(int i=0;i<n;++i)out[i]=array[i];
        output[outindex++]=out;
    }
    else if(sum<taget){
        for(int i=start;i<n;++i){
            array[i]+=1;
            dfs(array,cvalue,i);
            array[i]-=1;
        }
    }
}

int main(){

    while(scanf("%d",&n)!=EOF){
        int array[SIZE]={0},cvalue[SIZE]={0};
        for(int i=0;i<n;++i)scanf("%d",&cvalue[i]);
        scanf("%d",&taget);
        dfs(array,cvalue,0);
        for(int i=outindex-1;i>=0;--i){
            putchar('(');
            for(int x=0;x<n;++x){
                printf("%d",output[i][x]);
                if(x!=n-1)putchar(',');
            }
            putchar(')');
            putchar('\n');
            free(output[i]);
        }
    }
}
