#include <stdio.h>
#define SIZE 31

static inline void solve(){
    int n, u, a, b, max = -1, list[SIZE] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &u, &a, &b);
        if(a != -1)list[a] = list[u] + 1;
        if(b != -1)list[b] = list[u] + 1;
    }
    for(int i = 0; i < n; i++)
        if(list[i] > max)max = list[i];
    printf("%d\n", max);
}

int main(){
    solve();
    return 0;
}
