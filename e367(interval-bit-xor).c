#include <stdio.h>
#define SIZE 100001

void putint(int out){
    char buf[1000];
    int n = 0;
    if(out < 0){
        putchar('-');
        out *= -1;
    }
    do
    {
        buf[n++] = '0' + (out%10);
        out /= 10;
    }while(out > 0);
    for(--n; n >= 0; --n)putchar(buf[n]);
    putchar('\n');
}

int main(){
    int list[SIZE];
    int a, b, temp = 0;
    for(int i = 1; i < SIZE; i++){
        temp ^= i;
        list[i] = list[i - 1] ^ temp;
    }
    while(scanf("%d%d", &a, &b) == 2)
        putint(list[b] ^ list[a-1]);
}
