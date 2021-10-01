#include <stdio.h>// 	NA (score:20%)
#define MAXSIZE 1000001
#define BUFSIZE 1048576

int n, q;
int prefix[MAXSIZE];

static inline char readChar(){
    static char buf[BUFSIZE], *p = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(p == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        p = buf;
    }
    return *p++;
}

static inline char readUint(register int *temp){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF)
            return 0;
    *temp = '0' ^ ch;
    while((ch = readChar()) >= '0')
        *temp = (*temp << 3) + (*temp << 1) + ('0' ^ ch);
    return 1;
}

static inline void solve(){
    int oper, left, right;
    register int *p, *end = prefix + n;
    while(q--){
        readUint(&oper);
        readUint(&left);
        readUint(&right);
        switch(oper){
        case 0:
            printf("%d\n", prefix[right] ^ prefix[left - 1]);
            break;
        case 1:
            right ^= prefix[left] ^ prefix[left - 1];
            for(p = prefix + left; p <= end; p++)
                *p ^= right;
            break;
        }
    }
}

int main(){
    readUint(&n);
    readUint(&q);
    *prefix = 0;
    for(int i = 1; i <= n; i++){
        readUint(prefix + i);
        prefix[i] ^= prefix[i - 1];
    }
    solve();
    return 0;
}
