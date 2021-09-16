#include <stdio.h>

static inline void solve(){
    register int i, j, div, visited, temp;
    for(i = 123456789; i < 987654322; i++){
        div = i;
        visited = 0;
        for(j = 0; j < 9; j++){
            temp = div % 10;
            if(!temp || ((visited >> temp) & 1))break;
            visited |= 1 << temp;
            div /= 10;
        }
        if(j != 9)continue;
        div = 10000000;
        for(j = 2; j < 10; j++){
            if((i/div)%j)break;
            div /= 10;
        }
        if(j == 10){
            printf("%lld\n", i);
            break;
        }
    }
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>

static inline void solve(){
    puts("381654729");
}

int main(){
    solve();
    return 0;
}*/
