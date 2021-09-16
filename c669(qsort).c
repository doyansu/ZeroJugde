#include <stdio.h>
#define SIZE 101
#define MAXINF 0x7fffffff

void SWAP(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *array,int left,int right,int mid){
    int pivotValue=array[mid];
    SWAP(&array[mid],&array[right]);
    for(int i=left;i<right;++i){
        if(array[i]<pivotValue){
            SWAP(&array[left++],&array[i]);
        }
    }
    SWAP(&array[left],&array[right]);
    return left;
}

void myqsort(int *array,int left,int right){
    if(right>left){
        int mid=(left+right)/2;
        mid=partition(array,left,right,mid);
        myqsort(array,left,mid-1);
        myqsort(array,mid+1,right);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int array[SIZE]={0};
        int temp;
        int index=0;
        int sum=0;
        char ch;
        while(scanf("%d%c",&temp,&ch)!=EOF){
            array[index++]=temp;
            sum+=temp;
            if(ch=='\n')break;
        }
        myqsort(array,0,index-1);
        int td[3]={array[1]-array[0],array[2]-array[1],array[3]-array[2]};
        myqsort(td,0,2);
        int d=td[1];
        temp=-MAXINF;
        for(int i=0;i<index;++i){
            if(temp==array[i])break;
            temp=array[i];
        }
        printf("%d %d\n",temp-sum+((array[0]+array[index-1])*index)/2,temp);
    }
}
