#include <stdio.h>
#define BUFSIZE 65536

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline char readLLUint(register long long int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return ch;
}

static inline void solve(){
    int n;
    long long int temp, ans;
    scanf("%d", &n);
    while(n--){
        ans = 0;
        while(readLLUint(&temp) == ' ')
            ans += temp;
        ans += temp;
        printf("%lld\n", ans);
    }
}

int main(){
    solve();
    return 0;
}
