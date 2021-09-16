#include <stdio.h>
#define SIZE 103

int main(){
    char str[SIZE];
    while(fgets(str, SIZE, stdin) != NULL){
        int flag = 0;
        char *p = str;
        if(*p == '-'){
            flag = -1;
            p++;
        }
        int ans = 0, temp;
        for(int i = 2; i < 4; i++){
            if(p[i] == '\n')temp = 0;
            else temp = p[i] ^ '0';
            ans = (ans<<3) + (ans<<1) +temp;
        }
        if(p[4] > '4')ans++;
        if(ans == 0)flag = 0;
        if(flag)putchar('-');
        if(ans == 100 || *p =='1')puts("1.00");
        else{
            putchar('0');
            putchar('.');
            if(ans / 10 ==0)putchar('0');
            printf("%d", ans);
            putchar('\n');
        }
    }
}
