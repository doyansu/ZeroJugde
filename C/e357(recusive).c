#include <stdio.h>

int func(int n){
    if(n == 1)return 1;
    if(n&1)return func(n - 1) + func(n + 1);
    else return func(n>>1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
}
