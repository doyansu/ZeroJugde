#include <stdio.h>

static inline void solve(){
    int n, table[6] = {1000, 500, 100, 50, 10, 5};
    while(scanf("%d", &n) == 1){
        register int jugde = 0, q;
        printf("%d = ", n);
        for(int i = 0; i < 6; i++){
            q = n / table[i];
            if(q){
                printf("%d*%d", jugde = table[i], q);
                n -= jugde * q;
                if(n > 4)printf(" + ");
            }
        }
        if(n){
            if(jugde)printf(" + ");
            printf("1*%d", n);
        }
        putchar('\n');
    }
}

int main(){
    solve();
    return 0;
}
