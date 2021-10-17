#include <stdio.h>
#define BUFSIZE 524288

static inline void putint(int output){
    char buf[13];
    char *p = &buf[11];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar('\n');
}

static inline int get_Uint(register int *n){
    register char tc ;
    while((tc = getchar()) < '0')
        if(tc == EOF)return 0;
    *n = tc ^ '0';
    while((tc = getchar()) >= '0')
        *n = (*n << 1) + (*n << 3) + (tc ^ '0');
    return 1;
}

int main(){
    int n;
    int table[55] = {0,'m','j','q','h','o','f','a','w','c','p','n','s','e','x','d','k','v','g','t','z','b','l','r','y','u','i',5,16,22,26,19,8,25,13,7,24,20,18,4,12,10,11,23,3,17,6,1,15,14,9,21,2};
    get_Uint(&n);
    while(n--){
        int t, out = 0;
        char input[3];
        get_Uint(&t);
        scanf("%s", input);
        if(*input > '9'){
            out = table[*input - 70];
            while(--t){
                scanf("%s", input);
                out += table[*input - 70];
            }
            putint(out);
        }
        else{
            char *p = input;
            while(*p != '\0')
                out = (out << 3) + (out << 1) + (*p++ ^ '0');
            putchar(table[out]);
            while(--t){
                get_Uint(&out);
                putchar(table[out]);
            }
            putchar('\n');
        }

    }
}
