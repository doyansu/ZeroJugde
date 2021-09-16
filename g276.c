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
    /*bomb = 0;
    for(int i = 0; i < n; i++){
        puts(map[i]);
        for(int j = 0; j < m; j++)
            if(map[i][j] == '*')bomb++;
    }



    printf("%d", bomb);*/
}

int main(){
    solve();
    return 0;
}
