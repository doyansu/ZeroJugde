#include <stdio.h>
#include <string.h>

static inline void solve(){
    int len, t;
    char str[100], *p = str;
    scanf("%d ", &len);
    for(int i = 0; i < len; i++)
        *p++ = ' ';
    gets(p);
    p += strlen(p);
    for(int i = 0; i < len; i++)
        *p++ = ' ';
    scanf("%d", &t);
    *(str + len + t) = '\0';
    puts(str + t);
}

int main(){
    solve();
    return 0;
}
