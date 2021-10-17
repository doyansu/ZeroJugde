#include <stdio.h>
#include <memory.h>
#define MAXSIZE 101

int main(){
    int map[MAXSIZE][MAXSIZE], size, k;
    int dir[8][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
    while(scanf("%d", &size) == 1){
        scanf("%d", &k);
        memset(map, 0, sizeof(map));
        while(k--){
            int x, y;
            scanf("%d%d", &y, &x);
            if(map[x][y] != -1){
                map[x][y] = -1;
                for(int i = 0; i < 8; i++){
                    int tx = x + dir[i][0], ty = y + dir[i][1];
                    if(tx >= 0 && ty >= 0 && tx < size && ty < size && map[tx][ty] != -1)
                        map[tx][ty]++;
                }
            }
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                if(map[i][j] != -1)
                    printf("%d", map[i][j]);
                else
                    putchar('x');
            putchar('\n');
        }
    }

}
