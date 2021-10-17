#include <stdio.h>//AC 0.2S
#define SIZE 10001

int binarySearch(int *array,int taget,int left,int right){
    int mid=(left+right)>>1;
    if(left>right)return 0;
    if(array[mid]==taget)return 1;
    else if(array[mid]>taget){
        return binarySearch(array,taget,left,mid-1);
    }
    else{
        return binarySearch(array,taget,mid+1,right);
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(n--){
        int list1[SIZE];
        int count=0;
        int temp;
        for(int i=0;i<m;++i)scanf("%d",&list1[i]);
        for(int i=0;i<m;++i){
            scanf("%d",&temp);
            if(binarySearch(list1,temp,0,m))++count;
        }
        printf("%d\n",count);
    }

}
