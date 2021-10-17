/*
long long sumxor(long long N){
    long long ans=0;
    for(long long i=0;i<N;i++){
	if((N^i)==(N+i))ans++;
    }
    return ans;
} 

(N^i) == (N+i) 代表 N + i 運算(二進位運算)中不會有任何進位(參考加法器)

所以計算 n 的二進位中 0 的數量 x
回傳值為 2 的 x 次方

ex 
n = 4(10) -> 100(2) -> 2個0 -> sumxor(n) = 2**2 = 4
n = 10(10) -> 1010(2) -> 2個0 -> sumxor(n) = 2**2 = 4
n = 41(10) -> 101001(2) -> 3個0 -> sumxor(n) = 2**3 = 8
n = 47(10) -> 101111(2) -> 1個0 -> sumxor(n) = 2**1 = 2
*/

#include <stdio.h>

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
