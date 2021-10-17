#include <stdio.h>
#include <string.h>
#define SIZE 12

int main(){
    int len;
    char number[SIZE];
    fgets(number, SIZE, stdin);
    len = strlen(number) - 1;
    while(len){
        number[len--] = '\0';
        puts(number);
    }
}
