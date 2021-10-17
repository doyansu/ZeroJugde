/*
用 qsort 對數字進行排序
*** cmp 函數比較方式為 a , b 長度相同則直接進行比較, 不同則串接成 ab , ba 在進行比較 ***
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 51

void swap(char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void mystrcpy(char *res, char *sour){
    while(*sour != '\0')
        *res++ = *sour++;
    *res = '\0';
}

int cmp(char *a, char *b){
    int temp = 0;
    if(strlen(a) == strlen(b)){
        for(;*a != '\0' && *b != '\0';a++,b++)
            if(*a != *b)return *a > *b;
    }
    else {
        char *ab = malloc(SIZE * sizeof(char)), *ba = malloc(SIZE * sizeof(char));
        mystrcpy(ab , a);
        mystrcpy(ab + strlen(ab), b);
        mystrcpy(ba , b);
        mystrcpy(ba + strlen(ba), a);
        temp = cmp(ab, ba);
        free(ab);
        free(ba);
    }
    return temp;
}

int getMid(char* list[SIZE], int left, int right){
    swap(&list[(left + right) / 2], &list[right]);
    char* cmpPointer = list[right];
    for(int i = left; i < right; i++)
        if(cmp(list[i], cmpPointer))
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(char* list[SIZE], int left, int right){
    if(right > left){
        int mid = getMid(list, left, right);
        myqsort(list, left, mid - 1);
        myqsort(list, mid + 1, right);
    }
}

int main(){
    int n;
    char* list[SIZE];
    while(scanf("%d", &n) == 1){
        if(n == 0)break;
        getchar();
        for(int i = 0; i < n; i++){
            char *p = malloc(SIZE * sizeof(char));
            scanf("%s", p);
            list[i] = p;
        }
        myqsort(list, 0, n - 1);
        for(int i = 0; i < n; i++)fputs(list[i], stdout);
        putchar('\n');
    }
}
