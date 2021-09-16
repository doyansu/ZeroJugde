#include <stdio.h>
#define SIZE 1001
#define MAXINF 0x7fffffff

int main(){
    int array[SIZE]={0};
    int n,max=-MAXINF,min=MAXINF;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int data;
        scanf("%d",&data);
        array[data]=1;
        if(min>data)min=data;
        if(max<data)max=data;
    }
    int jugde=1;
    for(int i=min;i<max;++i){
        if(array[i]==0){
            jugde=0;
            break;
        }
    }
    printf("%d %d ",min,max);
    if(jugde)puts("yes");
    else puts("no");
}
