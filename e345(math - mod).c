/*
https://zh.wikipedia.org/wiki/%E5%8E%BB%E4%B9%9D%E6%B3%95

ABC≡A+B+C (mod9)
*/

#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        if(n%9 == 0 && n > 0)puts("9");
        else printf("%d\n", n%9);
    }
}
