#include <stdio.h>
#define SIZE 1002


int main(){
    char str[SIZE];
    char *p = str;
    fgets(str, SIZE, stdin);
    putchar(*p++);
    while(*(++p) != '\n')
        putchar('_');
    putchar(*(--p));
}
