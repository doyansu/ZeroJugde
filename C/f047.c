#include <stdio.h>
#define MAXSIZE 101

int main(){
    int len = 0;
    char ch = '\0', list[MAXSIZE][MAXSIZE];
    while(scanf("%s%c", list + len++, &ch) == 2 && ch != '\n');
    for(int i = 0; i < len; i += 3)
        printf("%s ", list[i]);
    printf("\n");
    for(int i = 1; i < len; i += 3)
        printf("%s ", list[i]);
    printf("\n");
    for(int i = 2; i < len; i += 3)
        printf("%s ", list[i]);
    printf("\n");

}
