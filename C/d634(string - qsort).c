#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

void swap(char **a, char **b){
    char* temp = *a;
    *a = *b;
    *b =temp;
}

int myStingCmp(char *a, char *b){
    for(; *a != '\0' && *b !='\0'; a++, b++)
        if(*a != *b)return *a < *b;
    return 0;
}

int getMid(char* list[SIZE], int left, int right){
    //swap(&list[(left + right) / 2], &list[right]);
    char* cmpSting = list[right];
    for(int i = left; i < right; i++)
        if(myStingCmp(list[i], cmpSting))
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
    int n, size = 12 * sizeof(char);
    char* list[SIZE];
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char *p = malloc(size);
        fgets(p, SIZE, stdin);
        list[i] = p;
    }
    myqsort(list, 0, n - 1);
    for(int i = 0; i < n; i++){
        fputs(list[i], stdout);
        free(list[i]);
    }
}
