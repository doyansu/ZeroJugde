#include <stdio.h>
#define SIZE 10000

static inline void solve(){
    int n = 0, temp;
    char input[SIZE], out[SIZE], *p;
    scanf("%d", &n);
    while(n--){
        scanf("%s", input);
        p = input;
        int ans = 0;
        if(*p >= '0' && *p <= '9'){
            while(*p != '\0')
                ans = (ans << 3) + (ans << 1) + ('0' ^ *p++);
            p = out + SIZE;
            *p-- = '\0';
            while(ans){
                temp = ans % 26;
                ans /= 26;
                if(temp)
                    *p-- = '@' ^ temp;
                else{
                    *p-- = 'Z';
                    ans--;
                }
            }
            puts(++p);
        }
        else {
            while(*p != '\0')
                ans = (ans << 4) + (ans << 3) + (ans << 1) + ('@' ^ *p++);
            printf("%d\n", ans);
        }
    }
}

int main(){
    solve();
    return 0;
}
