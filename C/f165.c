#include <stdio.h>

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(m==0){
            puts("OK!");
            continue;
        }
        int x=n%m;
        if(x==0)
            puts("OK!");
        else
            printf("%d\n",x);
    }
}
