#include <stdio.h>
#define SIZE 10

static inline void solve(){
    int n;
    char str[SIZE];
    while(scanf("%s %d", str, &n) == 2){
        n -= (n / 7) * 7;
        switch(*str){
        case 'M':
            n += 1;
            break;
        case 'T':
            if(str[1] == 'u')n += 2;
            else n += 4;
            break;
        case 'W':
            n += 3;
            break;
        case 'F':
            n += 5;
            break;
        case 'S':
            if(str[1] == 'a')n += 6;
            break;
        }
        switch(n%7){
        case 0:
            puts("Sunday");
            break;
        case 1:
            puts("Monday");
            break;
        case 2:
            puts("Tuesday");
            break;
        case 3:
            puts("Wednesday");
            break;
        case 4:
            puts("Thursday");
            break;
        case 5:
            puts("Friday");
            break;
        case 6:
            puts("Saturday");
            break;
        }
    }
}

int main(){
    solve();
    return 0;
}
