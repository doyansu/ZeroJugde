#include <stdio.h>//	AC (0.1s, 4.9MB)
#define MAXSIZE 1000001
#define BUFSIZE 1048576

int n, q;
int BIT[MAXSIZE] = {0};
char out[65536], *p = out, *end = out + 65516;

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

static inline int lowbit(int a){
    return a & -a;
}

static inline void initialBIT(){
    for(int i = n; i > 0; i--)
        BIT[i] ^= BIT[i - lowbit(i)];
}

static inline int query(int left, int right){
    int ans = 0;
    for(int i = right; i > 0; i -= lowbit(i))
        ans ^= BIT[i];
    for(int i = left - 1; i > 0; i -= lowbit(i))
        ans ^= BIT[i];
    return ans;
}

static inline void update(int x, int v){
    v ^= query(x, x);
    for(int i = x; i <= n; i += lowbit(i))
        BIT[i] ^= v;
}

static inline void putAns(int src){
    char temp[20], *tp = temp + 19;
    *tp-- = '\0';
    if(p > end){
        *p = '\0';
        fputs(out, stdout);
        p = out;
    }
    while(src){
        *tp-- = '0' ^ (src % 10);
        src /= 10;
    }
    while(*++tp)
        *p++ = *tp;
    *p++ = '\n';
}

static inline void operate(){
    int oper, left, right;
    while(q--){
        readUint(&oper);
        readUint(&left);
        readUint(&right);
        switch(oper){
        case 0:
            putAns(query(left, right));
            break;
        case 1:
            update(left, right);
            break;
        default:
            puts("ERROR");
            return;
        }
    }
    *p = '\0';
    fputs(out, stdout);
}

int main(){
    readUint(&n);
    readUint(&q);
    for(int i = 1; i <= n; i++){
        readUint(BIT + i);
        BIT[i] ^= BIT[i - 1];
    }
    initialBIT();
    operate();
    return 0;
}

/*
#include <stdio.h>//AC (0.3s, 4.9MB)
#define MAXSIZE 1000001
#define BUFSIZE 1048576

int n, q;
int BIT[MAXSIZE] = {0};

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

static inline int lowbit(int a){
    return a & -a;
}

static inline void initialBIT(){
    for(int i = n; i > 0; i--)
        BIT[i] ^= BIT[i - lowbit(i)];
}

static inline int query(int left, int right){
    int ans = 0;
    for(int i = right; i > 0; i -= lowbit(i))
        ans ^= BIT[i];
    for(int i = left - 1; i > 0; i -= lowbit(i))
        ans ^= BIT[i];
    return ans;
}

static inline void update(int x, int v){
    v ^= query(x, x);
    for(int i = x; i <= n; i += lowbit(i))
        BIT[i] ^= v;
}

static inline void operate(){
    int oper, left, right;
    while(q--){
        readUint(&oper);
        readUint(&left);
        readUint(&right);
        switch(oper){
        case 0:
            printf("%d\n", query(left, right));
            break;
        case 1:
            update(left, right);
            break;
        default:
            puts("ERROR");
            return;
        }
    }
}

int main(){
    readUint(&n);
    readUint(&q);
    for(int i = 1; i <= n; i++){
        readUint(BIT + i);
        BIT[i] ^= BIT[i - 1];
    }
    initialBIT();
    operate();
    return 0;
}
*/

/*
#include <stdio.h>// 12%
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

static inline int lowbit(int a){
    return a & -a;
}

static inline void initialBIT(){
    for(int i = n; i > 0; i--)
        prefix[i] ^= prefix[i - lowbit(i)];
}

static inline int query(int left, int right){
    int ans = 0;
    for(int i = right; i > 0; i -= lowbit(i))
        ans ^= prefix[i];
    for(int i = left - 1; i > 0; i -= lowbit(i))
        ans ^= prefix[i];
    return ans;
}

static inline void update(int x, int v){
    v ^= prefix[x] ^ prefix[x - 1];
    for(int i = x; i <= n; i += lowbit(i))
        prefix[i] ^= v;
}

static inline void operate(){
    int oper, left, right;
    //register int *p, *end = prefix + n;
    while(q--){
        readUint(&oper);
        readUint(&left);
        readUint(&right);
        switch(oper){
        case 0:
            printf("%d\n", query(left, right));
            break;
        case 1:
            update(left, right);
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
    initialBIT();
    operate();
    return 0;
}
*/



/*
#include <stdio.h>
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

static inline int lowbit(int a){
    return a & -a;
}

static inline void initialBIT(){
    for(int i = n; i > 0; i--)
        prefix[i] ^= prefix[i - lowbit(i)];
}

static inline int query(int left, int right){
    int ans = 0;
    for(int i = right; i > 0; i -= lowbit(i))
        ans ^= prefix[i];
    for(int i = left - 1; i > 0; i -= lowbit(i))
        ans ^= prefix[i];
    return ans;
}

static inline void update(int x, int v){
    v ^= prefix[x] ^ prefix[x - 1];
    for(int i = x; i <= n; i += lowbit(i))
        prefix[i] ^= v;
}

static inline void solve(){
    int oper, left, right;
    //register int *p, *end = prefix + n;
    while(q--){
        readUint(&oper);
        readUint(&left);
        readUint(&right);
        switch(oper){
        case 0:
            printf("%d\n", query(left, right));
            break;
        case 1:
            update(left, right);
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
    initialBIT();
    solve();
    return 0;
}

*/

/*
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
*/
