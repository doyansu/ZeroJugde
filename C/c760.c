#include <stdio.h>
#define SIZE 100

int main(){
    char str[SIZE];
    while(scanf("%s",str)!=EOF){
        *str-=32;
        puts(str);
    }
}
