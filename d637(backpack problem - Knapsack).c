#include <stdio.h>
#define BPackSIZE 100
#define ItemSIZE 10001

typedef struct item_s{
    int weight,value;
}item_t;

void knapsack(item_t list[], int n){
    int maxCost[BPackSIZE + 1] = {0};
    for(int i = 0; i < n; i++){
        int weight = list[i].weight;
        int cost = list[i].value;
        for(int j = BPackSIZE; j - weight >= 0; --j)
            if(maxCost[j] < maxCost[j - weight] + cost)maxCost[j] = maxCost[j - weight] + cost;
    }
    printf("%d\n", maxCost[BPackSIZE]);
}


int main(){
    int n;
    while(scanf("%d", &n) == 1){
        item_t list[n];
        for(int i = 0; i < n; i++)
            scanf("%d%d", &list[i].weight, &list[i].value);
        knapsack(list, n);
    }
}
