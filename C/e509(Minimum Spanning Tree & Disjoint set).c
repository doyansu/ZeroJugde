#include <stdio.h>//°Ñ¦Ò https://caidocode.blogspot.com/2020/06/zerojudge-e509conscription.html
#include <string.h>
#include <stdlib.h>

typedef struct edge_s{
    int boy, girl, w;
}edge_t;

edge_t edge[50001];
int parent[20001];

int findParent(int a){
    return parent[a] == -1 ? a : (parent[a] = findParent(parent[a]));
}

int cmp(edge_t *a, edge_t *b){
    return a->w < b->w;
}

int main(){
    int k;
    scanf("%d", &k);
    while(k--){
        int n, m, r, wSum = 0;
        scanf("%d%d%d", &n, &m, &r);
        memset(parent, -1, sizeof(parent));
        for(int i = 0; i < r; i++){
            scanf("%d%d%d", &edge[i].girl, &edge[i].boy, &edge[i].w);
            edge[i].boy += n;
        }
        qsort(edge, r, sizeof(edge_t), cmp);
        for(int i = 0; i < r; i++){
            int boy = findParent(edge[i].boy), girl = findParent(edge[i].girl);
            if(boy != girl){
                parent[boy] = girl;
                wSum += edge[i].w;
            }
        }
        printf("%d\n", 10000 * (n + m) - wSum);
    }
    return 0;
}
