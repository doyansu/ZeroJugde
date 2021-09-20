#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 1000000

int array[MAXINPUT], *temp;

void mergeSortRecusive(int start, int end){
    if(start >= end)
        return;
    int mid = (start + end) >> 1;
    int st1 = start , st2 = mid + 1, ti = start;
    mergeSortRecusive(start, mid);
    mergeSortRecusive(st2, end);
    while(st1 <= mid && st2 <= end)
        temp[ti++] = array[st1] < array[st2] ? array[st1++] : array[st2++];
    while(st1 <= mid)
        temp[ti++] = array[st1++];
    while(st2 <= end)
        temp[ti++] = array[st2++];
    while(start <= end)
        array[start++] = temp[start];
}

void mergeSort(int len){
    temp = malloc(len * sizeof(int));
    mergeSortRecusive(0, len - 1);
    free(temp);
}

static inline void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", array + i);
    mergeSort(n);
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
}

int main(){
    solve();
    return 0;
}
