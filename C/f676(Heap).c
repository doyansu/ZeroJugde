#include <stdio.h>
#define MAXN 1001
#define MAXINF 0x7fffffff

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeapify(int *heap, int last, int type){//upHeapify, type 0 = minheap, type 1 = maxheap
    while(type ? heap[last] > heap[last>>1] : heap[last] < heap[last>>1]){
        swap(heap + last, heap + (last>>1));
        last >>= 1;
    }
}

void downHeapify(int *heap, int len, int root, int type){//downHeapify, type 0 = minheap, type 1 = maxheap
    int left = root << 1, right = left + 1, next = root;
    if(left <= len && (type ? heap[left] > heap[next] : heap[left] < heap[next]))
        next = left;
    if(right <= len && (type ? heap[right] > heap[next] : heap[right] < heap[next]))
        next = right;
    if(next != root){
        swap(heap + root, heap + next);
        downHeapify(heap, len, next, type);
    }
}

void insertHeap(int *heap, int* len, int data){
    heap[++(*len)] = data;
    upHeapify(heap, *len, 1);
}

int removeMax(int *heap, int* len){
    int temp = heap[1];
    if(*len){
        heap[1] = 0;
        swap(heap + 1, heap + *len);
        downHeapify(heap, --(*len), 1, 1);
        return temp;
    }
    return -1;
}

int main(){
    char ins;
    int len = 0, Heap[MAXN] = {MAXINF};
    while(scanf("%c", &ins) == 1){
        int data;
        switch(ins){
        case 'I':
            scanf("%d", &data);
            insertHeap(Heap, &len, data);
            break;
        case 'D':
            printf("%d\n", removeMax(Heap, &len));
            break;
        }
    }
    return 0;
}
