#include <stdio.h>//	AC (0.6s, 25.9MB)
#define MAXINPUT 1000001
#define BUFSIZE 1048576

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void putULLint(register long long int* output){
    if(*output == 0)putchar('0');
    static char buf[30], *p;
    p = buf + 29;
    *p-- = '\0';
    while(*output){
        *p-- = '0' ^ (*output % 10);
        *output /= 10;
    }
    fputs(++p, stdout);
    putchar('\n');
}

int n, list[MAXINPUT], dp[MAXINPUT] = {0};
long long int prefix[MAXINPUT], ans[MAXINPUT] = {0};

static inline void solve(){
    readUint(&n);
    readUint(list);
    *prefix = *list;
    for(int i = 1; i < n; i++){
        readUint(list + i);
        prefix[i] = prefix[i - 1] + list[i];
    }
    for(int i = 1, p; i < n; i++){
        if(list[i] > list[i - 1]){
            ans[i] = prefix[i - 1];
            dp[i] = dp[i - 1] + 1;
            p = i - 1;
            while(p >= 0 && list[p] < list[i])
                p -= dp[p] + 1;
            if(p >= 0)
                ans[i] -= prefix[p];
        }
    }
    dp[n - 1] = 0;
    for(int i = n - 2, p; i >= 0; i--){
        if(list[i] > list[i + 1]){
            dp[i] = dp[i + 1] + 1;
            p = i + 1;
            while(p < n && list[p] < list[i])
                p += dp[p] + 1;
            ans[i] += prefix[--p] - prefix[i];
        }
        else
            dp[i] = 0;
    }
    for(long long int *i = ans; i < ans + n; i++)
        putULLint(i);

}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>//AC (0.7s, 24.9MB)
#define MAXINPUT 1000001

int n, list[MAXINPUT], dp[MAXINPUT] = {0};
long long int prefix[MAXINPUT], ans[MAXINPUT] = {0};

static inline void solve(){
    scanf("%d", &n);
    scanf("%d", list);
    *prefix = *list;
    for(int i = 1; i < n; i++){
        scanf("%d", list + i);
        prefix[i] = prefix[i - 1] + list[i];
    }
    for(int i = 1, p; i < n; i++){
        if(list[i] > list[i - 1]){
            ans[i] = prefix[i - 1];
            dp[i] = dp[i - 1] + 1;
            p = i - 1;
            while(p >= 0 && list[p] < list[i])
                p -= dp[p] + 1;
            if(p >= 0)
                ans[i] -= prefix[p];
        }
    }
    dp[n - 1] = 0;
    for(int i = n - 2, p; i >= 0; i--){
        if(list[i] > list[i + 1]){
            dp[i] = dp[i + 1] + 1;
            p = i + 1;
            while(p < n && list[p] < list[i])
                p += dp[p] + 1;
            ans[i] += prefix[--p] - prefix[i];
        }
        else
            dp[i] = 0;
    }
    for(int i = 0; i < n; i++)
        printf("%lld\n", ans[i]);

}

int main(){
    solve();
    return 0;
}*/
