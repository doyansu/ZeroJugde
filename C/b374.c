#include <stdio.h>
#define SIZE 30001

int main(){
    int n;
    scanf("%d",&n);
    int list[SIZE]={0};
    for(int x=0;x<n;++x){
        int data;
        scanf("%d",&data);
        ++list[data];
    }
    int index=0;
    int max=0;
    int output[10001]={0};
    for(int i=1;i<SIZE;++i){
        if(list[i]>max){
            index=1;
            output[0]=i;
            max=list[i];
        }
        else if(list[i]==max){
            output[index++]=i;
        }
    }
    for(int i=0;i<index;++i){
        printf("%d %d\n",output[i],max);
    }

}
