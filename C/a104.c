#include <stdio.h>
#define SIZE 1000
int SWAP(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        int list[SIZE]={0};
        for(int i=0;i<n;i++){
            scanf("%d",&list[i]);
            for(int j=i;j>0;j--)if(list[j]>list[j-1])SWAP(&list[j],&list[j-1]);else break;
        }
        for(int i=n-1;i>=0;i--)printf("%d ",list[i]);
        printf("\n");
    }
}
