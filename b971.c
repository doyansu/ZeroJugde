#include <stdio.h>

int main(){
    int a0,an,d;
    scanf("%d%d%d",&a0,&an,&d);
    for(int i=a0;i!=an+d;i+=d)printf("%d ",i);

}
