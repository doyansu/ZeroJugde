#include<stdio.h>
#define SIZE 1010
#define NEGFLAG 0x8fffffffe

int main(){
    char number[SIZE];
    fgets(number,SIZE,stdin);
    char *p = number;
    int flag = 1, d = 0;
    while(*p != '\n'){
        d += flag * (*p ^ '0');
        //printf("c%c d%d f%d\n",*p,(*p ^ '0'),flag);
        flag ^= NEGFLAG;
        p++;
    }
    if(d<0)d *= -1;
    printf("%d\n", d);
}
