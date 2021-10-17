#include <stdio.h>
#define MAXINF 0x7fffffff
#define SIZE 13

static inline void solve(){
    char str[SIZE], *p;
    while(gets(str) != NULL){
        p = str;
        while(*p != '\0' && !(*p&1))p++;
        if(*p == '\0')puts("0");
        else {
            int up = 0, low = 0;
            while(*++p != '\0'){
                up = (up << 3) + (up << 1) + ('9' - *p);
                low = (low << 3) + (low << 1) + ('0' ^ *p) + 1;
            }
            if(*str == '9')up = MAXINF;
            printf("%d\n", up > low? ++low : ++up);
        }
    }
}

int main(){
    solve();
    return 0;
}
