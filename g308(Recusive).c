#include <stdio.h>//	AC (2ms, 104KB)
#define MAXINPUT 1000

typedef struct node_s{
    int tppoint;
    char brownie;
}node_t;

node_t list[MAXINPUT];

int tp(int point){
    switch(list[point].brownie){
    case 0:
        return 0;
    case '1':
        list[point].brownie = 0;
        return 1 + tp(list[point].tppoint);
    default:
        list[point].brownie = 0;
        return tp(list[point].tppoint);
    }
}

static inline void solve(){
    int n, t;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n; i++)
        scanf("%d", &list[i].tppoint);
    for(int i = 0; i < n; i++)
        scanf(" %c", &list[i].brownie);
    printf("%d", tp(t));
}

int main(){
    solve();
    return 0;
}
