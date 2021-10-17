#include <stdio.h>
#define SIZE 2010
#define MAXINF 0x7fffffff

void SWAP(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int part(int *list,int left,int right,int mid){
    int cmpValue=list[mid];
    SWAP(&list[mid],&list[right]);
    for(int i=left;i<right;++i){
        if(list[i]<cmpValue)SWAP(&list[left++],&list[i]);
    }
    SWAP(&list[left],&list[right]);
    return left;
}

void myqsort(int *list,int left,int right){
    if(right>left){
        int mid=part(list,left,right,(left+right)/2);
        myqsort(list,left,mid-1);
        myqsort(list,mid+1,right);
    }
}

int main(){
    int number[SIZE]={0};
    int n;
    scanf("%d",&n);
    int index=0;
    int sum=0;
    while(n--){
        int num,data;
        scanf("%d%d",&num,&data);
        if(data>100){
            number[index++]=num;
            sum+=(data-100)*5;
        }
    }
    myqsort(number,0,index-1);
    for(int i=0;i<index;++i)printf("%d ",number[i]);
    if(sum)putchar('\n');
    printf("%d\n",sum);
}
