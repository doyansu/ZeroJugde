#include <stdio.h>//AC (8ms, 84KB)
#define MAXN 1025
#define MAXINF 0x7fffffff

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int *heap, int data, int last, int type){//insert heap, type 0 = minheap, type 1 = maxheap
    heap[last] = data;
    while(type ? heap[last] > heap[last>>1] : heap[last] < heap[last>>1]){
        swap(heap + last, heap + (last>>1));
        last >>= 1;
    }
}

int main(){
    int len = 0;
    int minHeap[MAXN] = {-MAXINF}, maxHeap[MAXN] = {MAXINF};
    while(scanf("%d", &len) == 1){
        for(int i = 1; i <= len; i++){
            int data;
            scanf("%d", &data);
            insert(minHeap, data, i, 0);
            insert(maxHeap, data, i, 1);
        }
        for(int i = 1; i <= len; i++)
            printf("%d ", minHeap[i]);
        printf("\n");
        for(int i = 1; i <= len; i++)
            printf("%d ", maxHeap[i]);
        printf("\n");
    }
    return 0;
}

