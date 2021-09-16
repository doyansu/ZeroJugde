#include <stdio.h>
#include <string.h>
#define SIZE 50

typedef struct car_s{
    char brand[SIZE];
    char color[SIZE];
}car_t;

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        car_t list[n];
        char type[SIZE], temp[SIZE];
        for(int i = 0; i < n; i++)
            scanf("%s%s", list[i].brand, list[i].color);
        while(m--){
            scanf("%s%s", type, temp);
            if(strcmp(type, "brand") == 0){
                for(int i = 0; i < n; i++){
                    if(strcmp(list[i].brand, temp) == 0){
                        fputs(list[i].brand, stdout);
                        putchar(' ');
                        fputs(list[i].color, stdout);
                        putchar('\n');
                    }
                }
            }
            else {
                for(int i = 0; i < n; i++){
                    if(strcmp(list[i].color, temp) == 0){
                        fputs(list[i].brand, stdout);
                        putchar(' ');
                        fputs(list[i].color, stdout);
                        putchar('\n');
                    }
                }
            }
        }
    }
}
