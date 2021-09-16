#include <stdio.h>


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int s=1;
        for(int i=2;i<n;++i)if(!(n%i))s+=i;
        if(s>n)printf("盈數\n");
        else if(s<n)printf("虧數\n");
        else printf("完全數\n");
    }
}
