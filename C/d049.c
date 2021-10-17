#include <stdio.h>
#define YEAR(n) n-1911
int main(){
    int num;
    scanf("%d",&num);
    printf("%d",YEAR(num));
}
