#include <stdio.h>
#include <string.h>

static inline void solve(){
    int Case = 1;
    char input[16];
    while(scanf("%s", input) == 1){
        switch(*input){
            case '#':
                return ;
                break;
            case 'H':
                printf("Case %d: ", Case++);
                if(strcmp(input, "HELLO") == 0)puts("ENGLISH");
                else if(strcmp(input, "HOLA") == 0)puts("SPANISH");
                else if(strcmp(input, "HALLO") == 0)puts("GERMAN");
                else puts("UNKNOWN");
                break;
            case 'B':
                printf("Case %d: ", Case++);
                if(strcmp(input, "BONJOUR") == 0)puts("FRENCH");
                else puts("UNKNOWN");
                break;
            case 'C':
                printf("Case %d: ", Case++);
                if(strcmp(input, "CIAO") == 0)puts("ITALIAN");
                else puts("UNKNOWN");
                break;
            case 'Z':
                printf("Case %d: ", Case++);
                if(strcmp(input, "ZDRAVSTVUJTE") == 0)puts("RUSSIAN");
                else puts("UNKNOWN");
                break;
            default:
                printf("Case %d: ", Case++);
                puts("UNKNOWN");
                break;
        }
    }
}

int main(){
    solve();
    return 0;
}
