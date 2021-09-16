#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int myabs(const int *a){
    return *a > 0 ? *a : -*a;
}

int cmp(const int *a, const int *b){
    return myabs(a) - myabs(b);
}

static inline void solve(){
    int list[SIZE], len;
    scanf("%d", &len);
    for(int i = 0; i < len; i++)
        scanf("%d", list + i);
    qsort(list, len, sizeof(int), cmp);
    int patrol = 0, last = list[0];
    for(int i = 1; i < len; i++){
        if((last > 0 && list[i] < 0) || (last < 0 && list[i] > 0))
            patrol++;
        last = list[i];
    }
    printf("%d\n", patrol);
}

int main(){
    solve();
    return 0;
}
