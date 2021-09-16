#include <stdio.h>
#define SIZE 11

int main(){
    char str[SIZE];
    while(fgets(str, SIZE, stdin) != NULL){
        register char *p = str;
        int count = 0;
        while(*p != '\0'){
            if(*p != ' ' && *p != '\n')count++;
            p++;
        }
        printf("%d\n", count);
    }
    return 0;
}
