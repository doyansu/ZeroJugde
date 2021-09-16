#include <stdio.h>
#include <math.h>
#define SIZE 100001
int main(){
    int n;
    int mid[SIZE] = {0 , 1};
    for(int i = 2; i < SIZE; i++)mid[i] = mid[i - 1] + ((i - 1) << 1);
    while(scanf("%d", &n) == 1){
        if(n == 0)break;
        int x = sqrt(n - 1) + 1;
        int y = n - mid[x];
        if(x&1){
            if(y < 0){
                y = x + y;
                printf("%d %d\n", x, y);
            }
            else{
                y = x - y;
                printf("%d %d\n", y, x);
            }
        }
        else{
            if(y < 0){
                y = x + y;
                printf("%d %d\n", y, x);
            }
            else{
                y = x - y;
                printf("%d %d\n", x, y);
            }
        }
    }
}
