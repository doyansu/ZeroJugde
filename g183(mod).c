#include <stdio.h>
#define SIZE 110

int main(){
    char str[SIZE];
    while(fgets(str, SIZE, stdin) != NULL){
        register char *p = str;
        int count = 0;
        while(*p != '\n')
            count = ((count<<3) + (count<<1) + ('0' ^ *p++)) % 81;
        if(count)puts("konosuba!");
        else puts("konopad!");

    }
    return 0;
}
