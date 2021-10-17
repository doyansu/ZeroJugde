#include <stdio.h>
#define SIZE 1000001

int prime[SIZE] = {0};

static inline void solve(){
    int n, temp = 2;
    while(temp * temp < SIZE){
        for(int i = temp<<1; i < SIZE; i += temp)
            prime[i] = 1;
        while(prime[++temp]);
    }
    while(scanf("%d", &n) == 1){
        if(prime[n])puts("no");
        else puts("yes");
    }
}

int main(){
    solve();
    return 0;
}
