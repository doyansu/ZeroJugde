#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",1-(((n>>31)&1)<<1)-(!n));
}
