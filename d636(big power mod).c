#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

long long int mod(long long int b,long long int e,long long int m){
    long long int p = b, x = 1;
    while(e > 0){
        if(e&1)x = (x * p) % m;
        p = (p * p) % m;
        e >>= 1;
    }
    return x;
}

int main(){
    long long int a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld", mod(a, b, 10007));
}
