#include <stdio.h>//	AC (88ms, 104KB)
#define MAXINF 0x7fffffff

static inline void solve(){
    int n, k, t, ais = 1;
    scanf("%d%d%d", &n, &k, &t);
    t *= k - 2;
    for(int applepie = 0; applepie < n; applepie++){
        int data, sum = 0, min = MAXINF, max = 0;
        for(int i = 0; i < k; i++){
            scanf("%d", &data);
            sum += data;
            if(max < data)max = data;
            if(min > data)min = data;
        }
        if(sum - max - min >= t){
            ais = 0;
            printf("%d\n", applepie);
        }
    }
    if(ais)
        puts("A is for apple.");

}

int main(){
    solve();
    return 0;
}
