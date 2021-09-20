/*
逆序數對、merge sort
*/

#include <stdio.h>//	AC (0.1s, 3.8MB)
#include <stdlib.h>
#define MAXINPUTSIZE 500001

long long int mergeSortRecusive(int *array, int *temp, int start, int end){
    if(start == end)
        return 0;
    int mid = (start + end) >> 1, st1 = start, st2 = mid + 1, ti = start;
    long long int count = mergeSortRecusive(array, temp, start, mid) + mergeSortRecusive(array, temp, st2, end);
    while(st1 <= mid && st2 <= end){
        if(array[st1] <= array[st2])
            temp[ti++] = array[st1++];
        else {
            temp[ti++] = array[st2++];
            count += mid - st1 + 1;
        }
    }
    while(st1 <= mid)
        temp[ti++] = array[st1++];
    while(st2 <= end)
        temp[ti++] = array[st2++];
    while(start <= end)
        array[start++] = temp[start];
    return count;
}

long long int mergeSort(int *array, int size){
    int *temp = malloc(size * sizeof(int));
    long long int ans = mergeSortRecusive(array, temp, 0, size - 1);
    free(temp);
    return ans;
}

int main(){
    int n, list[500001];
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++)
            scanf("%d", list + i);
        printf("%lld\n", mergeSort(list, n));
    }
    return 0;
}
