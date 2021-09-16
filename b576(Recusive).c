#include <stdio.h>

static inline int solve(){
    int n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int temp = 3, count = 0;
        temp = 3;
        while(n > temp)
            temp <<= 1;
        while(n > 3){
            if(n > temp){
                n -= temp;
                count++;
            }
            temp >>= 1;
        }
        if(count&1)
            n = 4 - n;
        printf("%d\n", n);
    }
}

int main(){
    solve();
    return 0;
}
