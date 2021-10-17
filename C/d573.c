#include <stdio.h>
#include <string.h>
#define SIZE 100001

static inline int get_int(){
    int n = 0, si = 1;
    register char tc = getchar();
    while(tc < '0' && tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0'){
        n = (n << 1) + (n << 3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}

static inline void putint(int output){
    int size = 0;
    char buf[1000];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        buf[size++] = '0' ^ (output % 10);
        output /= 10;
    }
    for(size--; size > -1; size--)putchar(buf[size]);
    putchar('\n');
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int list[SIZE] = {0};
        int group, size;
        while(n--){
            group = get_int();
            size = get_int();
            while(size--)
                list[get_int()] = group;
        }
        putint(list[get_int()]);
    }
}
