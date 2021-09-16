#include <stdio.h>
#define SIZE 15

int HEXtoRGB(char ch){
    return ch > '9' ? ch - '7' : ch ^ '0';
}

char RGBtoHEX(int n){
    return n > 9 ? n + '7' : n ^ '0';
}

static inline void solve(){
    char input[SIZE];
    register char *p;
    while(fgets(input, SIZE, stdin) != NULL){
        p = input;
        if(*p == '#'){
            p++;
            for(int i = 0; i < 3; i++)
                printf("%d ", (HEXtoRGB(*p++) << 4) + HEXtoRGB(*p++));
        }
        else {
            putchar('#');
            do{
                int temp = 0;
                while(*p >= '0'){
                    temp = (temp << 3) + (temp << 1) + (*p ^ '0');
                    p++;
                }
                printf("%c%c", RGBtoHEX(temp >> 4), RGBtoHEX(temp & 15));
            }while(*p++ == ' ');
        }
        putchar('\n');
    }
}

int main(){
    solve();
    return 0;
}
