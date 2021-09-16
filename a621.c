#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    ++n;
    for(int i=0;i<n;++i){
        printf("2^%d = %d\n",i,1<<i);
    }
}
