#include <stdio.h>

/*long long sumxor(long long N){
    long long ans=0;
    for(long long i=0;i<N;i++)
        if((N^i)==(N+i))ans++;
    return ans;
}*/

long long sumxor(long long n){
    long long temp = 1;
    while(n){
        if(!(n&1))temp <<= 1;
        n >>= 1;
    }
    return temp;
}


int main(){
    long long n;
    while(scanf("%lld", &n) == 1){
        if(n == 0)puts("0");
        else printf("%lld\n", sumxor(n));
    }
}
