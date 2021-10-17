#include <stdio.h>
#include <string.h>
#define MAXITEMSIZE 100
#define MAXBACKSIZE 10000
#define MAXINF 0x7fffffff

int itemList[MAXITEMSIZE], dp[MAXBACKSIZE], n, backSize;

void solve(){

    memset(dp, 0, backSize + 1);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        int weight = itemList[i];
        for(int j = 0; j <= backSize - weight; j++)
            if(dp[j])
                dp[j + weight] = 1;
        if(dp[backSize]){
            puts("Yes");
            return;
        }
    }

    puts("No");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &backSize);
        for(int i = 0; i < n; i++)
            scanf("%d", itemList + i);
        solve();
    }
	return 0;
}
