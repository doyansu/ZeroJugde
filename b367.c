#include <stdio.h>
#define SIZE 1000

int main(){
    int t;
    scanf("%d",&t);
    int list[SIZE]={0};
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n*m;++i){
            scanf("%d",&list[i]);
        }
        int temp=0;
        for(int i=0;i<n*m;++i){
            if(list[i]!=list[n*m-1-i]){
                temp=1;
                break;
            }
        }
        if(temp)printf("keep defending\n");
        else printf("go forward\n");
    }
}
