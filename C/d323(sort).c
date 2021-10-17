#include <stdio.h>
#include <stdlib.h>
#define MAXINPUTSIZE 10000000

int list[MAXINPUTSIZE];

int cmp(const int *a, const int *b){
    return *a - *b;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++)
            scanf("%d", list + i);
        qsort(list, n, sizeof(int), cmp);
        for(int i = 0; i < n; i++)
            printf("%d ", list[i]);
    }
    return 0;
}
