#include <stdio.h>

static inline void solve(){
    int n;
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++){
            if(i&1){
                for(int j = n; j > 0; j--){
                    printf("%d ", i * n + j);
                }
            }
            else{
                for(int j = 1; j <= n; j++){
                    printf("%d ", i * n + j);
                }
            }
            putchar('\n');
        }
        putchar('\n');
    }
}

int main(){
    solve();
    return 0;
}

