#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001

typedef struct object_s{
    int w,f;
}object_t;

void swap(object_t *a, object_t *b){
    object_t temp = *a;
    *a=*b;
    *b=temp;
}

int cmpobj(object_t a, object_t b){
    if(a.w*b.f < b.w*a.f)return 1;
    return 0;
}

int part(object_t *list, int left, int right){
    object_t cmpValue=list[right];
    for(int i=left; i<right; i++)
        if(cmpobj(list[i], cmpValue))
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(object_t *list, int left, int right){
    if(right>left){
        int povit=part(list, left, right);
        myqsort(list, left, povit-1);
        myqsort(list, povit+1, right);
    }
}

int main(){
    int n;
    object_t list[SIZE];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &list[i].w);
    for(int i = 0; i < n; i++)scanf("%d", &list[i].f);
    myqsort(list,0,n-1);
    //for(int i = 0; i < n; i++)printf("w%d f%d\n",list[i].w,list[i].f);
    n--;
    long energy = 0, total=0;
    for(int i=0 ; i < n; i++){
        energy += list[i].w;
        total += energy * list[i + 1].f;
    }
    printf("%lu\n",total);
}
