/*
typedef struct Devil_s{
    int x, y, s, t;
    char survive;
}Devil_t;

x , y   為該魔王目前位置
s , t   為每回合成長
survive 為該魔王是否還在 map 上 '1' 代表存在 '0' 代表消失

流程:

初始化 map [n*m] = ' '  

number 儲存輸入魔王資料的陣列

sur = 剩餘魔王數 bomb = 紀錄炸彈數

-> //move

如果沒有炸彈則魔王放下炸彈(bomb++)並移動，移動完成後判斷是否出邊界，出邊界則該魔王消失(survive = '0' sur--)

-> //clearDevil

如果魔王碰到炸彈則設 survive = '-' (為暫時狀態為了清除炸彈使用代表該魔王這回合會消失)

-> //clearbomb

如果魔王這回合會消失清除該位置炸彈並且魔王消失(survive = '0' sur--)
*/

#include <stdio.h>
#define mapSIZE 100
#define devulSIZE 500

typedef struct Devil_s{
    int x, y, s, t;
    char survive;
}Devil_t;

static inline void solve(){
    int n, m, k;
    char map[mapSIZE][mapSIZE];
    Devil_t number[devulSIZE];
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            map[i][j] = ' ';
    Devil_t *p, *end = number + k;
    for(p = number; p < end; p++){
        scanf("%d%d%d%d", &p->x, &p->y, &p->s, &p->t);
        p->survive = '1';
    }
    //for(int i = 0; i < k; i++)printf("%d%d%d%d\n", number[i].x, number[i].y, number[i].s, number[i].t);
    int sur = k, bomb = 0;
    while(sur){
        for(p = number; p < end; p++){//move
            if(p->survive == '1'){
                if(map[p->x][p->y] == ' '){
                    bomb++;
                    map[p->x][p->y] = '*';
                }
                p->x += p->s;
                p->y += p->t;
                if(p->x < 0 || p->y < 0 || p->x >= n || p->y >= m){
                    p->survive = '0';
                    sur--;
                }
            }
        }
        for(p = number; p < end; p++){//clearDevil
            if(p->survive == '1' && map[p->x][p->y] == '*'){
                p->survive = '-';
                sur--;
            }
        }
        for(p = number; p < end; p++){//clearbomb
            if(p->survive == '-'){
                p->survive = '0';
                if(map[p->x][p->y] == '*'){
                    map[p->x][p->y] = ' ';
                    bomb--;
                }
            }
        }
    }
    printf("%d\n", bomb);
}

int main(){
    solve();
    return 0;
}
