#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int s = (a + b + c) / 2;
    printf("%d",s * (s - a) * (s - b) * (s - c));
}
