#include <stdio.h>

static inline void solve(){
    int h, m, s;
    while(scanf("%d%d%d", &h, &m, &s) == 3){
        printf("%d %d %d", h, m, s);
        if(h * s < m)puts(". I will be late!");
        else puts(". I will make it!");
    }
}

int main(){
    solve();
    return 0;
}
