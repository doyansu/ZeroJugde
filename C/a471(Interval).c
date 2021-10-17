#include <stdio.h>
#include <math.h>
#define SIZE 20000

void putint(int out){//	AC (13ms, 116KB)
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
}

int main(){//AC (18ms, 140KB)
    int n;
    while(scanf("%d", &n) == 1){
        n <<= 1;
        int NoSolution = 1;
        for(int i = sqrt(n); i > 1; i--){
            if((n%i) == 0){
                int a = (n / i) - i + 1;
                if((a&1) == 0){
                    NoSolution = 0;
                    a >>= 1;
                    putint(a);
                    putchar('-');
                    putint(a + i - 1);
                    putchar('\n');
                }
            }
        }
        if(NoSolution)puts("No Solution...");
        putchar('\n');
    }
}
