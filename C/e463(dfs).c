#include <stdio.h>//	AC (2ms, 120KB)
#include <stdlib.h>
#include <string.h>

int len = 0;
char *list[9828];

int cmp(const char **a, const char **b){
    return strlen(*a) != strlen(*b) ? strlen(*a) - strlen(*b) : strcmp(*a, *b);
}

void mystrcpy(char *s1, char *s2){
    while(*s2 != '\0')
        *s1++ = *s2++;
    *s1 = '\0';
}

void dfs(char *str, int n){
    if(n == 0)
        return;
    int temp = n;
    while(temp){
        *--str = '0' ^ (temp % 10);
        temp /= 10;
    }
    mystrcpy(list[len++] = malloc(14 * sizeof(char)), str);
    for(int i = 1; i <= (n >> 1); i++)
        dfs(str, i);
}

void getAns(int n){
    char out[14];
    out[13] = '\0';
    out[12] = ' ';
    len = 0;

    dfs(out + 12, n);
    qsort(list, len, sizeof(char*), cmp);

    printf("%d\n", len);
    for(int i = 0; i < len; i++)
        fputs(list[i], stdout);
    putchar('\n');
}

int main(){
    int n;
    while(scanf("%d", &n) == 1)
        getAns(n);
}


/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[101] = {0, 1}, len = 0;
char *list[9828];

int cmp(const char **a, const char **b){
    return strlen(*a) != strlen(*b) ? strlen(*a) - strlen(*b) : strcmp(*a, *b);
}

void mystrcpy(char *s1, char *s2){
    while(*s2 != '\0')
        *s1++ = *s2++;
    *s1 = '\0';
}

int getSize(int n){
    int temp = 1;
    if(dp[n])
        return dp[n];
    for(int i = 1; i <= (n >> 1); i++)
        temp += getSize(i);
    return dp[n] = temp;
}

void solve(char *str, int n){
    if(n == 0)
        return;
    int temp = n;
    while(temp){
        *--str = '0' ^ (temp % 10);
        temp /= 10;
    }
    mystrcpy(list[len++] = malloc(14 * sizeof(char)), str);
    for(int i = 1; i <= (n >> 1); i++)
        solve(str, i);
}

void getAns(int n){
    char out[14];
    out[13] = '\0';
    out[12] = ' ';
    len = 0;
    solve(out + 12, n);
    qsort(list, len, sizeof(char*), cmp);

    printf("%d\n", len);

    for(int i = 0; i < len; i++)
        fputs(list[i], stdout);
    putchar('\n');
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        //printf("%d\n", getSize(n));
        getAns(n);
    }
}*/
