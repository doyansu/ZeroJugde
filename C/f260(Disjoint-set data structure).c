#include <stdio.h>
#define SIZE 100000

int parent[SIZE], groupSIZE[SIZE], group;

int findParent(int a){//search
    return parent[a] == a ? a : (parent[a] = findParent(parent[a]));
}

static inline void solve(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        group = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            groupSIZE[i] = 1;
        }
        while(m--){
            int a, b;
            scanf("%d%d", &a, &b);
            a = findParent(a);
            b = findParent(b);
            if(a != b){
                group--;
                if(groupSIZE[a] > groupSIZE[b]){//merge
                    parent[b] = a;
                    groupSIZE[a] += groupSIZE[b];
                }
                else {
                    parent[a] = b;
                    groupSIZE[b] += groupSIZE[a];
                }
            }
        }
        printf("%d\n", group);
    }
}

int main(){
    solve();
    return 0;
}
