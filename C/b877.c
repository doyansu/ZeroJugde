#include <stdio.h>

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d\n",(b+100-a)%100);
    }
}
