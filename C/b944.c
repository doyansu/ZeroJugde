#include <stdio.h>
#include <stdlib.h>
#define SIZE 25

int search(int time[SIZE],int size){
    for(int i=1;i<size+1;++i)if(time[i]==0 && time[i-1]==0 && time[i+1]==0)return i;
    for(int i=1;i<size+1;++i)if(time[i]==0)return i;
    return -1;
}

int main()
{
    int time[SIZE]={0};
    int toilet[SIZE]={0};
    int size,number,cost;
    scanf("%d",&size);
    while(scanf("%d%d",&number,&cost)!=EOF){
        int index=search(time,size);
        if(index==-1)puts("  Not enough");
        else{
            toilet[index]=number;
            time[index]=cost;
        }
        printf("Number: ");
        for(int i=1;i<size+1;++i)printf("%d ",toilet[i]);
        putchar('\n');
        printf("  Time: ");
        for(int i=1;i<size+1;++i){
            printf("%d ",time[i]);
            if(time[i]>0)--time[i];
        }
        putchar('\n');
        for(int i=1;i<size+1;++i)if(time[i]==0)toilet[i]=0;
    }
}
