/*
耗很多空間的解法

建立 mid[n] 為座標 (n , n) 的值
利用 sqrt() 求出 n - 1 的平方根 r 可得知 r + 1 為目標座標(x , y)其一
n - mid[r + 1] 為 n 秒與中間座標差 所以 (r + 1) - abs(n - mid[r + 1]) 即為另一座標
再根據 r + 1 為奇、偶數判斷輸出是否交換位置
*/

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
