#include <stdio.h>
#include <string.h>
#define SIZE 1000010

char string[SIZE], target[SIZE] ;
int next[SIZE];

static inline void solve(){
    int n;
    *next = 0;
    scanf("%d ", &n);
    gets(target);
    gets(string);
    register int str = 1, sub = 0, len = strlen(target), slen = strlen(string);
    while(str < len){
        if(target[str] == target[sub])
            next[str++] = ++sub;
        else if(sub)
            sub = next[sub - 1];
        else
            next[str++] = 0;
    }
    n++;
    str = 0;
    sub = 0;
    while(str < slen && n){
        if(string[str] == target[sub]){
            str++;
            sub++;
            if(sub == len){
                sub = next[sub - 1];
                n--;
            }
        }
        else if(sub)
            sub = next[sub - 1];
        else
            str++;
    }
    if(n == 1)puts("YES");
    else puts("NO");
}

int main(){
    solve();
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#define SIZE 1000001

char string[SIZE], target[SIZE] ;
int next[SIZE];

static inline void solve(){
    int n;
    *next = 0;
    scanf("%d ", &n);
    gets(target);
    gets(string);
    int str = 1, sub = 0, len = strlen(target), slen = strlen(string);
    while(str < len){
        if(target[str] == target[sub])
            next[str++] = ++sub;
        else if(sub)
            sub = next[--sub];
        else
            next[str++] = 0;
    }
    n++;
    str = 0;
    sub = 0;
    //for(int i = 0; i < strlen(target); i++)printf("%d ", next[i]);
    while((str < slen) && n){
        if(string[str] == target[sub]){
            str++;
            sub++;
        }
        if(sub == len){
            sub = next[sub - 1];
            n--;
        }
        else if(sub)
            sub = next[sub - 1];
        else
            str++;
    }
    //printf("%d\n", n);
    if(n == 1)puts("YES");
    else puts("NO");
}

int main(){
    solve();
    return 0;
}
*/



/*#include <stdio.h>
#include <string.h>
#define SIZE 1000001

char string[SIZE], target[SIZE] ;
int next[SIZE] = {0};

void getNext(){
    int index = 0, *list = next + 1;
    char *mainp = target + 1, *subp = target, *mainend;
    mainend = target + strlen(target);
    while(mainp < mainend){
        if(*mainp == *subp){
            index++;
            subp++;
        }
        else if((index > 0) && (target[index = next[--index]] == *mainp))
            subp = target + ++index;
        else {
            index = 0;
            subp = target;
        }
        *list++ = index;
        mainp++;
    }
}

static inline void solve(){
    int n;
    scanf("%d ", &n);
    gets(target);
    gets(string);
    getNext();
    //for(int i = 0; i < strlen(target); i++)printf("%d ", next[i]);
    int index = 0, len = strlen(string);
    char *subp = target;
    while(index < len){
        if(string[index] == *subp){
            index++;
            subp++;
            if(*subp == '\0')n--;
        }
        else if(subp == target)
            index++;
        else
            subp = target + next[index - 1];
    }
    if(n == 0)puts("YES");
    else puts("NO");
}

int main(){
    solve();
    return 0;
}*/
