#include <stdio.h>
#define MAXN 2001
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

int main(){
    int type;
    while(scanf("%d", &type) == 1){
        type -= 1;
        int len = 0, m;
        int Heap[MAXN] = {type ? MAXINF : -MAXINF};
        scanf("%d", &len);
        for(int i = 1; i <= len; i++)
            scanf("%d", Heap + i);
        for(int i = len>>1; i > 0; i--)
            downHeapify(Heap, len, i, type);
        scanf("%d", &m);
        while(m--){
            int ins, x, y;
            scanf("%d", &ins);
            switch(ins){
            case 1:
                scanf("%d%d", &x, &y);
                y = y > len ? len : y;
                for(int i = x; i <= y; i++)
                    printf("%d ", Heap[i]);
                putchar('\n');
                break;
            case 2:
                scanf("%d", &x);
                Heap[++len] = x;
                upHeapify(Heap, len, type);
                break;
            case 3:
                if(len){
                    Heap[1] = 0;
                    swap(Heap + 1, Heap + len);
                    downHeapify(Heap, --len, 1, type);
                }
                break;
            }
        }
        putchar('\n');
    }
    return 0;
}

