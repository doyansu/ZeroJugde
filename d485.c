#include<stdio.h>

int main(){
    int a,b;
    scanf("%d%d", &a, &b);
    printf("%d",((b - a) / 2) + 1 - (a&1 && b&1));
}
