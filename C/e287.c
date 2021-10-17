#include <stdio.h>
#include <stdlib.h>
#define SIZE 10501
#define MAXINF 1000000

int main(){
    int n,m;
    int map[SIZE];
    for(int x=0;x<SIZE;++x)map[x]=MAXINF;
    scanf("%d%d",&n,&m);
    int min=MAXINF,index=n+1;
    for(int x=m+1;x<n*m+m+1;++x){
        scanf("%d",&map[x]);
        if(min>map[x]){
            min=map[x];
            index=x;
        }
    }
    /*printf("index %d min %d\n",index,min);
    for(int x=m+1;x<n*m+m+1;++x)printf("%d\n",map[x]);*/

    long long int sum=min;
    map[index]=MAXINF;
    while(1){
        min=MAXINF;
        int temp=0;
        if(map[index+1]<min){
            min=map[index+1];
            temp=index+1;
        }
        if(map[index-1]<min){
            min=map[index-1];
            temp=index-1;
        }
        if(map[index+m]<min){
            min=map[index+m];
            temp=index+m;
        }
        if(map[index-m]<min){
            min=map[index-m];
            temp=index-m;
        }
        if(min==MAXINF || temp==0)break;
        index=temp;
        sum+=map[index];
        //printf("%d->\n",map[index]);
        map[index]=MAXINF;
    }
    printf("%lld\n",sum);
}
