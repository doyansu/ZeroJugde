#include <stdio.h>
#define SIZE 12000000

char output[SIZE];

static inline void solve(){
    int n, temp, flag = 0;
    register char *p;
    scanf("%d", &n);
    p = output + SIZE - 1;
    *p-- = '\0';
    while(n--){
        flag = 0;
        scanf("%d", &temp);
        if(temp < 0){
            flag = 1;
            temp = ~temp + 1;
        }
        while(temp){
            *p-- = '0' | (temp%10);
            temp /= 10;
        }
        if(flag)*p-- = '-';
        *p-- = ' ';
    }
    puts(p + 2);

}

int main(){
    solve();
    return 0;
}
