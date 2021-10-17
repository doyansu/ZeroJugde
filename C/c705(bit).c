#include <stdio.h>

int main(){
    unsigned int n;
    while(scanf("%u", &n) == 1){
        int list[4];
        for(int i = 0; i < 4; i++){
            list[i] = n & 255;
            n >>= 8;
        }
        for(int i = 3; i >= 0; i--){
            printf("%d", list[i]);
            if(i != 0)putchar('.');
        }
        putchar('\n');
    }

}
