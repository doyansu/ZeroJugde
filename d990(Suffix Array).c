#include <stdio.h>// This code is not done yet
#include <string.h>
#define SIZE 100001

char string[SIZE], target[SIZE] ;
int next[SIZE];


static inline void solve(){
    int n;
    *next = 0;
    gets(string);
    scanf("%d ", &n);
    while(n--){
        gets(target);
        int count = 0, str = 1, sub = 0, len = strlen(target), slen = strlen(string);
        while(str < len){
            if(target[str] == target[sub])
                next[str++] = ++sub;
            else if(sub)
                sub = next[--sub];
            else
                next[str++] = 0;
        }
        str = 0;
        sub = 0;
        while(str < slen){
            if(string[str] == target[sub]){
                str++;
                sub++;
                if(sub == len){
                    sub = next[sub - 1];
                    count++;
                }
            }
            else if(sub)
                sub = next[sub - 1];
            else
                str++;
        }
        printf("%d\n", count);
    }
}

int main(){
    solve();
    return 0;
}
