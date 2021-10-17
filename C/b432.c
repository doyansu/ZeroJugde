#include <stdio.h>//	AC (23ms, 4.1MB)
#define BUFSIZE 65536
#define MOD 1048575

int list[MOD + 2];

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

static inline char readUint(register unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[13];
    char *p = buf + 10;
    *(p + 1) = '\n';
    *(p + 2) = '\0';
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
}

static inline void solve(){
    register int power;
    register unsigned long long int temp, ans;
    for(int i = 0; i <= MOD; i++){
        power = 23333;
        temp = i;
        ans = 1;
        while(power){
            if(power&1)
                ans = (ans * temp) & MOD;
            temp = (temp * temp) & MOD;
            power >>= 1;
        }
        list[ans] = i;
    }
    int n;
    while(readUint(&n))
        putint(list[n]);
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>//	AC (59ms, 4.1MB)
#define MOD 1048575

int list[MOD + 2];

static inline void solve(){
    register int power;
    register unsigned long long int temp, ans;
    for(int i = 0; i <= MOD; i++){
        power = 23333;
        temp = i;
        ans = 1;
        while(power){
            if(power&1)
                ans = (ans * temp) & MOD;
            temp = (temp * temp) & MOD;
            power >>= 1;
        }
        list[ans] = i;
    }
    int n;
    while(scanf("%d", &n) == 1)
        printf("%d\n", list[n]);
}

int main(){
    solve();
    return 0;
}*/


/*#include <stdio.h>//	NA (score:20%)
#define MOD 1048575

static inline void solve(){
    int n;
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= MOD; i += 2){
            register int power = 23333;
            register unsigned long long int temp = i, ans = 1;
            while(power){
                if(power&1)
                    ans = (ans * temp) & MOD;
                temp = (temp * temp) & MOD;
                power >>= 1;
            }
            if(ans == n){
                printf("%d\n", i);
                break;
            }
        }
    }
}

int main(){
    solve();
    return 0;
}*/


/*#include <stdio.h>
#define MOD 1048575

unsigned long long mpow(unsigned long long x, unsigned long long y, unsigned long long mod) {
    unsigned long long ret = 1;
    while (y) {
        if (y&1)
            ret = (ret * x)%mod;
        y >>= 1, x = (x * x)%mod;
    }
    return ret % mod;
}
// find a^23333 = n \mod 2^32
int main() {
    const long long M = 1LL<<20;
    const long long E = 23333;
    long long n;
    while (scanf("%lld", &n) == 1) {
        long long a = 0;
        for (int i = 0; i < 32; i++) {
            long long t = mpow(a, E, M), mask = (1LL<<(i+1))-1;
            if ((t&mask) == (n&mask));
            else
                a |= 1LL<<i;
        }
        printf("%lld\n", a);
    }
    return 0;
}*/
