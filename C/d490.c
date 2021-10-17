#include<stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a&1)a++;
    if(b&1)b--;
    int n = ((b - a)>>1) + 1;
    printf("%d", ((a + b)>>1)*n);
}
