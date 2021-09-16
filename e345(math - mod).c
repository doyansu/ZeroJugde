#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        if(n%9 == 0 && n > 0)puts("9");
        else printf("%d\n", n%9);
    }
}
