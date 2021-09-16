#include <stdio.h>//	AC (4ms, 112KB)
#include <string.h>
#define SIZE 52
#define MAXINF 0x7fffffff

int map[SIZE][SIZE];
int newmap[SIZE][SIZE];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int row, col, k, m;

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
    putchar('\n');
}

int* solve(){
    int *nowp = &map[0][0], *newp = &newmap[0][0];
    int *newtemp, *nowtemp, *temp = nowp;
    while(m--){
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                *(newp + i * SIZE + j) = *(nowp + i * SIZE + j);
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++){
                nowtemp = nowp + i * SIZE + j;
                if(*nowtemp == -1)continue;
                newtemp = newp + i * SIZE + j;
                for(int d = 0; d < 4; d++){
                    if(*(nowtemp + dir[d][0] * SIZE + dir[d][1]) == -1)continue;
                    //printf("enter%d\n", *(nowtemp + dir[d][0] * SIZE + dir[d][1]));
                    *temp = (*nowtemp) / k;
                    *(newtemp + dir[d][0] * SIZE + dir[d][1]) += *temp;
                    *newtemp -= *temp;
                    //printf("%d %d\n", *newtemp, *(newtemp + dir[d][0] * SIZE + dir[d][1]));
                }
            }
        temp = nowp;
        nowp = newp;
        newp = temp;
        /*for(int i = 0; i < row + 1; i++){
            for(int j = 0; j < col + 1; j++)
                printf("%d ", *(nowp + i * SIZE +j));
            putchar('\n');
        }
        putchar('\n');*/
    }
    return nowp;
}

int main(){
    while(scanf("%d%d%d%d", &row, &col, &k, &m) == 4){
        memset(map, -1, sizeof(map));
        memset(newmap, -1, sizeof(newmap));
        row++;
        col++;
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                map[i][j] = get_int();
        int *pointer = solve();
        int max = 0, min = MAXINF;
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++){
                int temp = *(pointer + i*SIZE + j);
                if(temp == -1)continue;
                if(temp > max)max = temp;
                else if(temp <min)min = temp;
            }
        putint(min);
        putint(max);
    }
}
