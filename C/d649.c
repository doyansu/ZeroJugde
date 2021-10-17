#include <stdio.h>//	AC (2ms, 88KB)
#define SIZE 1002000

int main(){
    int n;
    char temp[SIZE];
    while(scanf("%d", &n) == 1){
        if(n == 0)break;
        char *p = temp;
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < n - i; j++)*p++ = '_';
            for(int j = 0; j < i; j++)*p++ = '+';
            *p++ = '\n';
        }
        *p = '\0';
        puts(temp);
    }
}
/*#include <stdio.h>//	AC (3ms, 88KB)
#define SIZE 1001

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        if(n == 0)break;
        char temp[n + 2];
        temp[n] = '\n';
        temp[n + 1] = '\0';
        for(int i = 1; i < n + 1; i++){
            char *p = temp;
            for(int j = 0; j < n - i; j++)*p++ = '_';
            for(int j = 0; j < i; j++)*p++ = '+';
            fputs(temp, stdout);
        }
        putchar('\n');
    }
}*/
