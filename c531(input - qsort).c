#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int cmp(const int *a, const int *b){
    return *a - *b;
}

int main(){
    char str[SIZE];
    while(gets(str) != NULL){
        int len = 0, sortlen = 0, list[SIZE]= {0}, sort[SIZE] = {0};
        char *p = str;
        while(1){
            while(*p >= '0')
                list[len] = (list[len]<<3) + (list[len]<<1) + ('0' ^ *p++);
            if(!(list[len] & 1))sort[sortlen++] = list[len];
            len++;
            if(*p++ == '\0')break;
        }

        qsort(sort, sortlen, sizeof(int), cmp);
        /*for(int i = 0; i < len; i++)printf("%d ", list[i]);
        putchar('\n');
        for(int i = 0; i < sortlen; i++)printf("%d ", sort[i]);
        putchar('\n');*/
        sortlen = 0;
        for(int i = 0; i < len; i++){
            if(list[i]&1)printf("%d", list[i]);
            else printf("%d", sort[sortlen++]);
            if(i != len - 1)putchar(',');
        }
        putchar('\n');
    }
}
