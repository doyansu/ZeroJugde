#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int myabs(const int *a){
    return *a > 0 ? *a : -*a;
}

int cmp(const int *a, const int *b){
    return ((*a&1) != (*b&1)) ? (*a&1) - (*b&1) : ((*a&1) ? *b - *a : *a - *b);
}

static inline void solve(){
    int list[SIZE], len;
    scanf("%d", &len);
    for(int i = 0; i < len; i++)
        scanf("%d", list + i);
    qsort(list, len, sizeof(int), cmp);
    for(int i = 0; i < len; i++)
        printf("%d ", list[i]);

}

int main(){
    solve();
    return 0;
}
