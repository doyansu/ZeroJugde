#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<n+1;++i){
        int temp;
        scanf("%d",&temp);
        sum+=temp*i;
    }
    printf("%d\n",sum);
}
