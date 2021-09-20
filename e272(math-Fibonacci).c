/*
https://home.gamer.com.tw/creationDetail.php?sn=4427282
*/

#include <stdio.h>//	AC (43ms, 100KB)

int fibGCD(int n, int m){
    if(n <= 2 || m <= 2)
        return 1;
    else if(n == m)
        return n;
    return m > n ? fibGCD(m - n, n) : fibGCD(n - m, m);
}

static inline void solve(){
    int n, m;
    unsigned long long fibonacci[100] = {0, 1, 1};
    for(int i = 3; i < 101; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    while(scanf("%d%d", &n, &m) == 2)
        printf("%llu\n", fibonacci[fibGCD(n, m)]);
}

int main(){
    solve();
    return 0;
}
