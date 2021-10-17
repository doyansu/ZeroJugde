#include <stdio.h>

int gcd(int n, int m){
    return n%m ? gcd(m, n%m) : m;
}

static inline void solve(){
    int n, t;
    while(scanf("%d%d", &n, &t) == 2){
        int temp = gcd(t, n), count = -1;
        if(temp)temp = (n + t) / temp;
        else temp = n + t;
        while(temp){
            count++;
            temp >>= 1;
        }
        printf("%d\n", count);
    }
}

int main(){
    solve();
    return 0;
}
