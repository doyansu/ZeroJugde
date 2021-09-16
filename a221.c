#include <stdio.h>
#include <string.h>
#define SIZE 30


static inline void solve(){
    int n;
    char correct[SIZE], input[SIZE];
    register char *cp, *ip;
    scanf("%d", &n);
    getchar();
    for(int Case = 1; Case <= n; Case++){
        int state = 0;
        fgets(input, SIZE, stdin);
        fgets(correct, SIZE, stdin);
        for(cp = correct, ip = input; *cp != '\0' && *ip != '\0'; cp++, ip++){
            while(*ip == ' '){
                state = 1;
                ip++;
            }
            //printf("c = %c i = %c\n", *cp, *ip);
            if(*cp != *ip){
                state = -1;
                break;
            }
        }
        printf("Case %d: ", Case);
        switch(state){
        case 0:
            puts("Yes");
            break;
        case 1:
            puts("Output Format Error");
            break;
        case -1:
            puts("Wrong Answer");
            break;
        }
    }
}

int main(){
    solve();
    return 0;
}
