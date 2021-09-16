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
