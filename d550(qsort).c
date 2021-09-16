#include <stdio.h>
#include <stdlib.h>

int group, size;

void putint(int out){
    char buf[1000];
    int n = 0;
    if(out < 0){
        putchar('-');
        out *= -1;
    }
    do
    {
        buf[n++] = '0' + (out%10);
        out /= 10;
    }while(out > 0);
    for(--n; n >= 0; --n)putchar(buf[n]);
    putchar(' ');
}

int get_int(){
    int n = 0, si = 1;
    char tc = getchar();
    while((tc<'0'||tc>'9') &&  tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0' && tc <= '9'){
        n = (n<<1) + (n<<3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}

void swap(int **a,int **b){
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int cmpArray(int *a, int *b){
    for(int i = 0; i < size; i++)
        if(a[i] < b[i])return -1;
        else if(a[i] > b[i])return 1;
    return 0;
}

int getMidPoint(int* list[size], int left, int right){
    int* cmpValue = list[right];
    for(int i = left; i < right; i++)
        if(cmpArray(list[i], cmpValue) == -1)
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(int* list[size], int left, int right){
    if(right>left){
        int povit = getMidPoint(list, left, right);
        myqsort(list, left, povit - 1);
        myqsort(list, povit + 1, right);
    }
}

int main(){
    while(scanf("%d%d", &group, &size) == 2){
        int* list[group];
        for(int i = 0; i < group; i++){
            int* temp = calloc(size, sizeof(int));
            for(int j = 0; j < size; j++)
                temp[j] = get_int();
            list[i] = temp;
        }
        myqsort(list, 0, group-1);
        for(int i = 0; i < group; i++){
            for(int j = 0; j < size; j++)
                putint(list[i][j]);
            free(list[i]);
            putchar('\n');
        }
    }
}
