#include <stdio.h>

static inline void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    m <<= 3;
    if(m > (n << 1) + n)puts("Too much");
    else if(m >= (n << 1))puts("Yes");
    else puts("Not enough");
}

int main(){
    solve();
    return 0;
}
