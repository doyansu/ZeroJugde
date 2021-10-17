#include <stdio.h>
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=-1){
        if(a==b)printf("%d\n",b);
        else printf("%d\n",b+1);
    }
}

