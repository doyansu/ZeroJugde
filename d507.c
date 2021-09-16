#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int list[3];
    scanf("%d%d%d", list, list + 1, list + 2);
    for(int i = 1; i < 3; i++)
        for(int j = i; j >0; j--)
            if(list[j-1] > list[j])
                swap(&list[j-1],&list[j]);
    int d = list[2] * list[2] - list[1] * list[1] -list[0] * list[0];
    if(d>0)puts("obtuse triangle");
    else if(d<0)puts("acute triangle");
    else puts("right triangle");
}
