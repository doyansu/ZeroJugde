#include <stdio.h>
#define SIZE 10

typedef struct subway_s{
    int number;
    char URL[101];
}subway_t;

int main(){
    int n;
    scanf("%d", &n);
    n++;
    for(int Case = 1; Case < n; Case++){
        printf("Case #%d:\n", Case);
        int max = -1;
        subway_t list[SIZE];
        for(int data = 0; data < SIZE; data++){
            scanf("%s%d", list[data].URL, &list[data]);
            if(list[data].number > max)max = list[data].number;
        }
        for(int i = 0; i < SIZE; i++)
            if(list[i].number == max)
                puts(list[i].URL);
    }
}
