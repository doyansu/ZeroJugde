#include <stdio.h>//AC 2ms
#define SIZE 10003

char str[SIZE];

void getSum(char *str, int *sum){
    if(*str == '-')str++;
    while(*str != '\n'){
        *sum += *str ^ '0';
        str++;
    }
}

int main(){

    int sum;
    while(fgets(str, SIZE, stdin) != NULL){
        sum=0;
        getSum(str,&sum);
        if(sum%3 == 0)puts("yes");
        else puts("no");
    }
    return 0;
}
