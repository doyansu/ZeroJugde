#include <stdio.h>
#include <string.h>
#define SIZE 33

int main(){
    char str[SIZE], *p;
    while(fgets(str, SIZE, stdin) != NULL){
        p = str;
        int passwordStrength = 0, upper = 0, lower = 0, other =0;
        if(strlen(str) >= 9)passwordStrength++;
        while(*p != '\n'){
            if(*p >= 'A' && *p <= 'Z')upper = 1;
            else if(*p >= 'a' && *p <= 'z')lower = 1;
            else other = 1;
            p++;
        }
        if(upper && lower)passwordStrength++;
        if((upper + lower) && other)passwordStrength++;
        switch(passwordStrength){
        case 0:
            puts("This password is WEAK");
            break;
        case 1:
            puts("This password is ACCEPTABLE");
            break;
        case 2:
            puts("This password is GOOD");
            break;
        case 3:
            puts("This password is STRONG");
            break;
        }
    }
    return 0;
}
