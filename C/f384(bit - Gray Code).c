#include <stdio.h>// AC (0.3s, 72KB)
#define SIZE 34

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[15];
    char *p = buf + 12;
    *(p + 2) = '\0';
    *(p + 1) = '\n';
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
}

static inline void solve(){
    char input[SIZE];
    register char *p;
    while(fgets(input, SIZE, stdin) != NULL){
        p = input;
        register int temp = -1, ans = *p ^ '0', n = 0;
        while(*p != '\n'){
            n <<= 1;
            temp++;
            if(*p++ == '1')n++;
        }
        while(temp--){
            ans <<= 1;
            if(((n >> temp)&1) != ((ans >> 1)&1))ans++;
        }
        putint(ans);
    }
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>//AC (0.3s, 72KB)

static inline void solve(){
    char input[33];
    register char *p;
    while(gets(input) != NULL){
        p = input;
        register int temp = -1, ans = *p ^ '0', n = 0;
        while(*p != '\0'){
            n <<= 1;
            temp++;
            if(*p++ == '1')n++;
        }
        while(temp--){
            ans <<= 1;
            if(((n >> temp)&1) != ((ans >> 1)&1))ans++;
        }
        printf("%d\n", ans);
    }
}

int main(){
    solve();
    return 0;
}*/
