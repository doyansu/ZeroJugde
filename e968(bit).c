#include <stdio.h>

static inline void solve(){
    int n, temp, visited = 0;
    scanf("%d", &n);
    for(int i = 0; i < 3; i++){
        scanf("%d", &temp);
        visited |= 1 << temp;
    }
    while(n){
        if(!((visited >> n) & 1))printf("No. %d\n", n);
        n--;
    }
}

int main(){
    solve();
    return 0;
}
