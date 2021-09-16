#include <stdio.h>
#include <stdlib.h>
#define SIZE 101

int cmp(const int *a, const int *b){
    return *b - *a;
}

int main(){
    int list[SIZE], len = 0;
    while(scanf("%d", list + len) == 1 && list[len++] != -1);
    qsort(list, len - 1, sizeof(int), cmp);
    scanf("%d", &len);
    printf("%d", list[len - 1]);
    return 0;
}
