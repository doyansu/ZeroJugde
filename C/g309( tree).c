#include <stdio.h>//	AC (2ms, 80KB)
#define MAXINPUT 10

typedef struct animal_s{
    int cake, left, right;
}animal_t;

animal_t list[MAXINPUT];

void divCake(int index, int cake){
    list[index].cake += cake;
    int div = 3, left = list[index].left, right = list[index].right;
    if(left == -1 && right == -1)return;
    else if(left == -1 || right == -1)div = 2;
    cake /= div;
    if(left != -1){
        divCake(left, cake);
        list[index].cake -= cake;
    }
    if(right != -1){
        divCake(right, cake);
        list[index].cake -= cake;
    }
}

static inline void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        list[i].cake = 0;
        int number;
        scanf("%d", &number);
        scanf("%d%d", &list[number].left, &list[number].right);
    }
    divCake(0, k);
    for(int i = 0; i < n; i++)
        printf("%d ", list[i].cake);
}

int main(){
    solve();
    return 0;
}
