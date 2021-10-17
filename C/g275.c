#include <stdio.h>
#define SIZE 14

static inline void solve(){
    int n;
    char first[SIZE], second[SIZE];
    scanf("%d ", &n);
    while(n--){
        gets(first);
        gets(second);
        int a = 1, b = 1, c = 1;
        if(first[2] == first[6] || first[2] != first[10] || second[2] == second[6] || second[2] != second[10])a = 0;
        if(first[12] == '0' || second[12] == '1')b = 0;
        if(first[2] == second[2] || first[6] == second[6] || first[10] == second[10])c = 0;
        if(a && b && c)puts("None");
        else {
            if(a == 0)putchar('A');
            if(b == 0)putchar('B');
            if(c == 0)putchar('C');
            putchar('\n');
        }
    }
}

int main(){
    solve();
    return 0;
}
