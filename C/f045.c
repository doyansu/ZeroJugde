#include <stdio.h>
#define SIZE 10

static inline void solve(){
    char input[SIZE];
    register char *p = input, *end = input + 9, *index;
    int max = -1, second = -1;
    gets(input);
    while(p < end){
        if((*p ^ '0') > max){
            max = *p ^ '0';
            index = p;
        }
        p++;
    }
    p = input;
    while(p < end){
        if(p != index && (*p ^ '0') > second)
            second = *p ^ '0';
        p++;
    }
    //printf("max = %d second = %d\n", max, second);
    max = max * max + second * second;
    second = (input[6] ^ '0') * 100;
    second += (input[7] ^ '0') * 10;
    second += input[8] ^ '0';
    //printf("end = %d\n", second);
    if(max == second)puts("Good Morning!");
    else puts("SPY!");
}

int main(){
    solve();
    return 0;
}
