#include <stdio.h>
#include <stdlib.h>

int cmp(const int *a, const int *b){
    return *a - *b;
}

static inline void solve(){
    int n, r;
    while(scanf("%d%d", &r, &n) == 2 && (r != -1 || n != -1)){
        int list[n], i, count = 0;
        for(i = 0; i < n; i++)
            scanf("%d", list + i);
        qsort(list, n, sizeof(int), cmp);
        /*for(i = 0; i < n; i++)printf("%d ", list[i]);
        putchar('\n');*/
        int temp = -1;
        for(i = 0; i < n; i++){
            if(list[i] > temp){
                if((temp = list[i] + r) >= list[i + 1]){
                    while(++i < n && temp >= list[i]);
                    temp = list[--i] + r;
                    //printf("i = %d\n", list[i]);
                }
                //else
                    //printf("i = %d\n", list[i]);
                //printf("temp = %d\n", temp);
                count++;
            }
        }
        printf("%d\n", count);
    }
}

int main(){
    solve();
    return 0;
}
