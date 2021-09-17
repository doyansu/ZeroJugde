#include <stdio.h>
#define ARRAYSIZE 100

static inline void solve(){
    char out[ARRAYSIZE];
    gets(out);
    printf("hello, %s", out);
}

int main(){
    solve();
    return 0;
}
