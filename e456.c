#include <stdio.h>

int main(){
    int size = 0;
    char input[30][100];
    while(scanf("%s", input[size]) == 1)
        size++;
    size--;
    for(int i = 0; i < size; i++)
        printf("%s little, ", input[i]);
    printf("%s little Indians", input[size]);
}
