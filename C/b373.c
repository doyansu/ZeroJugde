#include <stdio.h>
#define SIZE 1000

int main(){
    int n;
    scanf("%d",&n);
    int list[SIZE];
    int answer=0;
    for(int i=0;i<n;++i){
        int d;
        scanf("%d",&d);
        list[i]=d;
        for(int j=i;j>0;--j){
            int temp;
            if(list[j-1]>list[j]){
                ++answer;
                temp=list[j-1];
                list[j-1]=list[j];
                list[j]=temp;
            }
            else break;
        }
    }
    printf("%d",answer);
}
