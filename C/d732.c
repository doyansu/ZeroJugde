#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001

int binarySearch(int array[SIZE],int taget,int left,int right){
    if(left>right)return 0;
    int mid=(left+right)/2;
    if(array[mid]==taget)return mid+1;
    else if(array[mid]>taget){
        return binarySearch(array,taget,left,mid-1);
    }
    return binarySearch(array,taget,mid+1,right);
}

int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        int array[SIZE]={0};
        for(int i=0;i<n;++i)scanf("%d",array+i);
        while(k--){
            int x;
            scanf("%d",&x);
            printf("%d\n",binarySearch(array,x,0,n));
        }
    }
}
