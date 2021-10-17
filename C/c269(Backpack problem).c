#include <stdio.h>//	AC (15ms, 104KB)

static inline int solve(){
    int n, t, cost, type;
    unsigned long long int maxFavor[1001] = {0}, favor;
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++){
        scanf("%d %llu %d", &cost, &favor, &type);
        favor *= 100000;
        if(type == 1){
            favor /= cost;
            type = 1;
            while(cost-- && type){
                type = 0;
                for(unsigned long long  *j = maxFavor + t, *end = maxFavor + 1; j >= end; j--)
                    if(*j < *(j - 1) + favor){
                        *j = *(j - 1) + favor;
                        type = 1;
                    }
            }
        }
        else {
            for(unsigned long long  *j = maxFavor + t, *end = maxFavor + cost; j >= end; j--)
                if(*j < *(j - cost) + favor)
                    *j = *(j - cost) + favor;
        }
    }
    printf("%llu\n", (maxFavor[t] + 50000) / 100000);
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000

typedef struct gril_s{
    int cost, favor, type;
}gril_t;

int cmp(const gril_t *a, const gril_t *b){
    float ta = a->favor, tb = b->favor;
    ta /= a->cost;
    tb /= b->cost;
    return ta != tb ? ta < tb : b->type - a->type;
}

int max(int a, int b){
    return a > b ? a : b;
}

static inline int solve(int n, int t, gril_t list[MAXSIZE]){
    return n >= 0 && t >= list[n].cost? max(solve(n - 1, t, list), solve(n - 1, t - list[n].cost, list) + list[n].favor) : 0;
}

static inline int solve(int n, int t, gril_t list[MAXSIZE]){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(t >= list[i].cost){
            list[n].type = ~list[n].type + 1;
            max += list[i].favor;
            t -= list[i++].cost;
        }
    }
    while(i < n && list[i].type == 2)i++;

    return max;
}

int main(){
    int n, t;
    gril_t list[MAXSIZE], *p = list;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n; i++, p++)
        scanf("%d%d%d", &p->cost, &p->favor, &p->type);
    qsort(list, n, sizeof(gril_t), cmp);
    printf("%d\n", solve(n - 1, t, list));
    return 0;
}
*/
