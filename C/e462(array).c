#include <stdio.h>

static inline void getARR(int size){
    int array[size][size], dir[2][2] = {{1, -1}, {-1, 1}};
    int state = 1, x = 0, y = 0, index = 1;
    while(index <= size * size){
        array[x][y] = index++;
        x += dir[state][0];
        y += dir[state][1];
        if(x + y < size && x != size && y != size){
            if(y < 0){
                y = 0;
                state = 1;
            }
            else if(x < 0){
                x = 0;
                state = 0;
            }
        }
        else {
            if(x == size){
                x -= 1;
                y += 2;
                state = 1;
            }
            else if(y == size){
                x += 2;
                y -= 1;
                state = 0;
            }
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            printf("%d ", array[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

int main(){
    int n;
    while(scanf("%d", &n) == 1)
        getARR(n);
    return 0;
}
