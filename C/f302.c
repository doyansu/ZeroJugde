#include<stdio.h>
#define SIZE 100

char number[SIZE];

int main(){
    char *p = number;
    fgets(number, SIZE, stdin);
    int ans=0;
    while(*p != '\n'){
        ans += (ans<<3) + (*p ^ '0');
        p++;
    }
    printf("%d",ans);
    return 0;
}
