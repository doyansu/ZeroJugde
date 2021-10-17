#include<stdio.h>

int main(){
    int a, b, n;
    scanf("%d%d", &a, &b);
    if(a>b){
        n=a;
        a=b;
        b=n;
    }
    if(a&1)a++;
    if(b&1)b--;
    n = ((b - a)>>1) + 1;
    printf("%d", ((a + b)>>1)*n);
}
