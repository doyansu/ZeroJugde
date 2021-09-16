#include <stdio.h>

int f(int n){
    int t=0;
    (n>0) && (t=n+f(n-1));
    return t;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
}
