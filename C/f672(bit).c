#include <stdio.h>

static inline void solve(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        if(n&(1<<--m))puts("1");
        else puts("0");
    }
}

int main(){
    solve();
    return 0;
}
