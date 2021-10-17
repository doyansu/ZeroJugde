#include <stdio.h>

int main(){
    int n, list[50], count = 1;
    while(scanf("%d", &n) == 1 && n){
        printf("Set #%d\n", count++);
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", list + i);
            sum += list[i];
        }
        sum /= n;
        for(int i = 0; i < n; i++)
            if(list[i] > sum)
                ans += list[i] - sum;
        printf("The minimum number of moves is %d.\n\n", ans);
    }
    return 0;
}
