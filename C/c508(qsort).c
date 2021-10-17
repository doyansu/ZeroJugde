#include <stdio.h>//AC 49ms
#include <string.h>
#define SIZE 100001

void SWAP(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *array,int left,int right,int pivot){
    int pivotValue=array[pivot];
    SWAP(array+right,array+pivot);
    for(int i=left;i<right;++i){
        if(array[i]<=pivotValue){
            SWAP(array+left,array+i);
            ++left;
        }
    }
    SWAP(array+left,array+right);
    return left;
}

void myqsort(int *array,int left,int right){
    if(right>left){
        int pivot=(left+right)/2;
        pivot=partition(array,left,right,pivot);
        myqsort(array,left,pivot-1);
        myqsort(array,pivot+1,right);
    }
}

int main(){
    int array[SIZE]={0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",array+i);
    myqsort(array,0,n-1);
    for(int i=0;i<n;++i)printf("%d ",array[i]);
    putchar('\n');
    int temp=-1;
    for(int i=n-1;i>=0;--i){
        if(temp!=array[i]){
            temp=array[i];
            printf("%d ",array[i]);
        }
    }
}

/*#include <stdio.h>//AC 49ms
#include <string.h>
#define SIZE 100001

int array[SIZE]={0};

void SWAP(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int left,int right,int pivot){
    int pivotValue=array[pivot];
    SWAP(&array[right],&array[pivot]);
    for(int i=left;i<right;++i){
        if(array[i]<=pivotValue){
            SWAP(&array[left],&array[i]);
            ++left;
        }
    }
    SWAP(&array[left],&array[right]);
    return left;
}

void myqsort(int left,int right){
    if(right>left){
        int pivot=(left+right)/2;
        pivot=partition(left,right,pivot);
        myqsort(left,pivot-1);
        myqsort(pivot+1,right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&array[i]);
    myqsort(0,n-1);
    for(int i=0;i<n;++i)printf("%d ",array[i]);
    putchar('\n');
    int temp=-1;
    for(int i=n-1;i>=0;--i){
        if(temp!=array[i]){
            temp=array[i];
            printf("%d ",array[i]);
        }
    }
}*/
