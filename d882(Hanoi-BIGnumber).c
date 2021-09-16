#include <stdio.h>
#include <stdlib.h>
#define SIZE 10001
#define BSIZE 50

int* array[SIZE];

void add(int *res,int *a,int *b){
    int carry=0,temp;
    for(int i=0;i<BSIZE;++i){
        temp=a[i]+b[i]+carry;
        res[i]=temp%10;
        carry=temp/10;
    }
}

int main(){
    int nowtime=1,count=1;
    int nowpow[BSIZE]={1};
    array[0]=calloc(BSIZE,sizeof(int));
    for(int i=1;i<SIZE;++i){
        int *p=calloc(BSIZE,sizeof(int));
        add(p,array[i-1],nowpow);
        array[i]=p;
        --nowtime;
        if(nowtime==0){
            ++count;
            nowtime=count;
            add(nowpow,nowpow,nowpow);
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        count=0;
        for(int i=BSIZE-1;i>=0;--i){
            if(count==0 && array[n][i])count=1;
            if(count)printf("%d",array[n][i]);
        }
        if(count==0)putchar('0');
        putchar('\n');
    }
}
