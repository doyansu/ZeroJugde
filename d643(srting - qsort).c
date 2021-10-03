#include <stdio.h>//	AC (69ms, 1.2MB)
#include <stdlib.h>
#include <string.h>
#define SIZE 100010

int cmp(const char **a, const char **b){
    return strcmp(*a, *b);
}

int cmpstr(char *input, char* list[SIZE], int size, int factor){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < factor; j++)
            if(*input++ != list[i][j])
                return 1;
    return 0;
}

int main(){
    char input[SIZE], *jugde = 0;
    gets(input);
    int len = strlen(input);
    for(int factor = 1, maxFactor = len >> 1; factor <= maxFactor; factor++){
        if(!(len % factor)){
            int listSize = len / factor;
            char* list[SIZE];
            for(int i = 0; i < listSize; i++)
                list[i] = &input[i * factor];

            qsort(list, listSize, sizeof(char *), cmp);

            if(cmpstr(input, list, listSize, factor)){
                char out[SIZE];
                jugde = out;
                for(int i = 0; i < listSize; i++)
                    for(int j = 0; j < factor; j++)
                        *jugde++ = list[i][j];
                puts(out);
            }
        }
    }
    if(!jugde)
        puts("bomb!");
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100010

void mystrcpy(char *res, char *sour, int size){
    while(size--)
        *res++ = *sour++;
    *res = '\0';
}

void swap(char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int getMid(char *list[SIZE], int left, int right){
    swap(&list[(left + right) / 2], &list[right]);
    char *cmpPointer = list[right];
    for(int i = left; i < right; i++)
        if(strcmp(cmpPointer, list[i]) == 1)
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(char *list[SIZE], int left, int right){
    if(right > left){
        int mid = getMid(list, left, right);
        myqsort(list, left, mid - 1);
        myqsort(list, mid + 1, right);
    }
}

int main(){
    char input[SIZE];
    fgets(input, SIZE, stdin);
    int len = strlen(input), jugde = 1;
    if(input[len - 1] =='\n')len--;
    input[len] = '\0';
    for(int factor = 1, maxFactor = (len / 2); factor <= maxFactor; factor++){
        if(!(len % factor)){
            int listSize = len / factor;
            char* list[SIZE];
            char *p = input;
            for(int i = 0; i < listSize; i++){
                char *split = calloc(factor + 1, sizeof(char));
                mystrcpy(split, p, factor);
                list[i] = split;
                p += factor;
            }
            myqsort(list, 0, listSize - 1);
            char temp[SIZE];
            p = temp;
            for(int i = 0; i < listSize; i++){
                mystrcpy(p, list[i], factor);
                free(list[i]);
                p += factor;
            }
            if(strcmp(input, temp)){
                jugde = 0;
                fputs(temp, stdout);
                putchar('\n');
            }
        }
    }
    if(jugde)puts("bomb!");
}*/
