#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        //int temp = 2 + (n<<5) + (n<<4) + n;
        //printf("%d\n", (temp<<4) + (temp<<3) + temp);
        int ans = 0, temp = 1, d = 1;
        for(int i = 0; i < 50; i++){
            ans += temp;
            temp += d;
            d += n;
        }
        printf("%d\n", ans);
        //printf("%d\n", 50 + n* ((49 * 50 * 51) / 6) - (n - 1) * 1225);
    }
}
