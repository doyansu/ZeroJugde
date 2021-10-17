#include <stdio.h>
#define SIZE 700000

int main(){
    int n;
    char temp[SIZE];
    while(scanf("%d ", &n) == 1){
        if(n == 1){
            scanf("%d", &n);
            printf("%d", n);
        }
        else {
            fgets(temp, SIZE, stdin);
            putchar('0');
        }
        putchar('\n');
    }
}
