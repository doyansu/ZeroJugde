#include <stdio.h>
#define SIZE 100
#define GEINF 0xfffffffe

int get_int(){
    int n = 0, si = 1;
    char tc = getchar();
    while((tc<'0'||tc>'9') &&  tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0' && tc <= '9'){
        n = (n<<1) + (n<<3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}

int main(){
    int n;
    char out[1000000];
    while(scanf("%d",&n) == 1){
        int list[SIZE], index = 0, move = 1, len = n, count = 0;
        for(int i = 0; i < n; i++)list[i]= get_int();
        while(len--){
            if(list[index] > 9)
                out[count++] = '0' ^ (list[index] / 10);
            out[count++] = '0' ^ (list[index] % 10);
            out[count++] = ' ';
            index += move;
            if(len == 0){
                len = --n;
                move ^= GEINF;
                index += move;
                out[count++] = '\n';
            }
        }
        out[--count] = '\0';
        puts(out);
    }
}

/*#include <stdio.h>//AC (0.1s, 88KB)
#define SIZE 100
#define GEINF 0xfffffffe

int get_int(){
    int n = 0, si = 1;
    char tc = getchar();
    while((tc<'0'||tc>'9') &&  tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0' && tc <= '9'){
        n = (n<<1) + (n<<3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}

void putint(int out){
    char buf[1000];
    int n = 0;
    if(out < 0){
        putchar('-');
        out *= -1;
    }
    do
    {
        buf[n++] = '0' + (out%10);
        out /= 10;
    }while(out > 0);
    for(--n; n >= 0; --n)putchar(buf[n]);
    putchar(' ');
}

int main(){
    int n;
    while(scanf("%d",&n) == 1){
        int list[SIZE], index = 0, move = 1, len = n;
        for(int i = 0; i < n; i++)list[i]= get_int();
        while(len--){
            putint(list[index]);
            index += move;
            if(len == 0){
                len = --n;
                move ^= GEINF;
                index += move;
                putchar('\n');
            }
        }
    }
}*/
