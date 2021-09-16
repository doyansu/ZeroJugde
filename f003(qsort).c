#include <stdio.h>
#include <stdlib.h>

typedef struct point_s{
    int x, y, distance;
}point_t;

int min(int a, int b){
    return a < b ? a : b;
}

int myabs(int a){
    return a > 0 ? a : -a;
}

int cmp(const point_t *a, const point_t *b){
    return a->distance != b->distance ? a->distance - b->distance : (a->x != b->x ? a->x - b->x : a->y - b->y);
}

static inline void solve(){
    int n = 0;
    while(scanf("%d", &n) == 1){
        int mind = 0x7fffffff, temp;
        point_t points[n];
        point_t *p, *end = points + n;
        for(p = points; p < end; p++){
            scanf("%d%d", &p->x, &p->y);
            p->distance = 0;
        }
        for(p = points; p < end; p++){
            for(point_t *j = p + 1; j < end; j++){
                temp = myabs(p->x - j->x) + myabs(p->y - j->y);
                p->distance += temp;
                j->distance += temp;
            }
            mind = min(mind, p->distance);
        }
        qsort(points, n, sizeof(point_t), cmp);
        for(p = points; p < end && p->distance == mind; p++)
            printf("%d %d\n", p->x, p->y);
        printf("%d\n\n", mind);
    }
}

int main(){
    solve();
    return 0;
}
