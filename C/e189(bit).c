/*
判斷是否 3 的倍數:

法一:

最直觀直接 '/' 或 '%'。

法二:  

用減的 每次 -3 減到 <= 0
如果 == 0 則為 3 的倍數。

法三:  

把每個位數加起來
如果和是 3 的倍數 則該數為 3 的倍數。

法四:

在 N base 的系統中判斷是否能被 (N+1) 整除的方式
將 奇數位和 - 偶數位和
如果結果能被 N + 1 整除(或 == 0)則該數是 N + 1 的倍數。


以上方法可做結合 
例如: 法二 + 法三
先把位數加起來再用減的看是不是 3 的倍數。
*/

#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int count = 1, jugde = 0;
        while(n){
            if(count&1)jugde += n&1;
            else jugde -= n&1;
            count++;
            n >>= 1;
        }
        //printf("%d\n", jugde);
        while(jugde < 2)
            jugde += 3;
        while(jugde > 2)
            jugde -= 3;
        if(jugde == 0)puts("YES");
        else puts("NO");
    }
}
