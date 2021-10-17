#include <stdio.h>
#define SIZE 11

int main(){
    int len, m;
    while(scanf("%d%d", &len, &m) == 2){
        int list[SIZE] = {0};
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            list[a] |= 1<<b;
            list[b] |= 1<<a;
        }
        for(int i = 1; i < len + 1; i++){
            printf("%d: ", i);
            m = 0;
            while(list[i]){
                if(list[i] & 1)
                    printf("%d ", m);
                list[i] >>= 1;
                m++;
            }
            putchar('\n');
        }
    }
    return 0;
}
