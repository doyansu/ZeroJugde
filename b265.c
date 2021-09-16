#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void getlist(int* temp){
    for(int i=0;i<SIZE;++i){
        scanf("%d",&temp[i]);
        for(int j=i;j>0;--j){
            int t;
            if(temp[j-1]>temp[j]){
                t=temp[j];
                temp[j]=temp[j-1];
                temp[j-1]=t;
            }
            else break;
        }
    }
}

int check(int **list,int *temp,int len){
    for(int i=0;i<len;++i){
        for(int x=0;x<SIZE;++x){
            if(list[i][x]!=temp[x]){
                break;
            }
            if(x==SIZE-1)return i;
        }
    }
    return -1;
}

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        int* list[n];
        int times[n];
        int len=0;
        for(int i=0;i<n;++i){
            int *temp=calloc(SIZE,sizeof(int));
            getlist(temp);
            int index;
            if((index=check(list,temp,len))!=-1){
                ++times[index];
                free(temp);
            }
            else{
                list[len]=temp;
                times[len]=1;
                len++;
            }
        }
        int max=0;
        int tempm=-1;
        for(int i=0;i<len;++i){
            if(times[i]>max)max=times[i];
            else if(times[i]==max)tempm=max;
        }
        if(tempm!=max)printf("%d\n",max);
        else{
            tempm=0;
            for(int i=0;i<len;++i){
                if(times[i]==max)tempm+=max;
            }
            printf("%d\n",tempm);
        }
        for(int i=0;i<len;++i)free(list[i]);
    }
}
