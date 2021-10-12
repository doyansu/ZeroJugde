#include <stdio.h>// 	AC (3.5s, 5.9MB)
#include <memory.h>
#define MOD 10000000
#define NUMDIGIT 7
#define BIGSIZE 72000
#define BUFSIZE 1048576


typedef struct bigNum_s{
    int len;
    unsigned long long int num[BIGSIZE];
}bigNum_t;

bigNum_t tmp, *t = &tmp, ans, base;;
char LLUbuf[NUMDIGIT + 1], out[BUFSIZE], *op = out, *max = out + BUFSIZE - 60000;

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

static inline char readULLint(register unsigned long long int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void putLLUint(register unsigned long long int src){
    register char *p = LLUbuf + NUMDIGIT - 1;
    while(src){
        *p-- = '0' ^ (src % 10);
        src /= 10;
    }
    while(*++p)
        *op++ = *p;
}

static inline void putDLLUint(register unsigned long long int src){
    register int digit = NUMDIGIT;
    register char *p = LLUbuf + NUMDIGIT - 1;
    while(digit--){
        *p-- = '0' | (src % 10);
        src /= 10;
    }
    while(*++p)
        *op++ = *p;
}

static inline bigNum_t bigMul(bigNum_t a, bigNum_t b){
    t = &tmp;
    memset(t, 0, sizeof(bigNum_t));
    t->len = a.len + b.len - 1;
    unsigned long long carry;
    for(int i = 0; i < a.len; i++){
        if(a.num[i]){
            for(int j = 0; j < b.len; j++){
                if(b.num[j])
                    t->num[i + j] += a.num[i] * b.num[j];
            }
        }
    }

    for(int i = 0; i < t->len; i++)
        if(t->num[i] >= MOD){
            carry = t->num[i] / MOD;
            t->num[i] -= carry * MOD;
            t->num[i + 1] += carry;
            if(i + 1 == t->len)
                t->len++;
        }

    return tmp;
}

static inline void fastPower(unsigned long long int b, unsigned long long int power){
    memset(&ans, 0, sizeof(bigNum_t));
    memset(&base, 0, sizeof(bigNum_t));
    base.num[0] = b;
    ans.num[0] = 1;
    base.len = ans.len = 1;

    for(;; power >>= 1){
        if(power & 1){
            ans = bigMul(ans, base);
            if(power == 1)
                break;
        }
        base = bigMul(base, base);
    }

    t = &ans;
    int len = t->len;
    putLLUint(t->num[--len]);
    while(len)
        putDLLUint(t->num[--len]);
    *op++ = '\n';
    if(op > max){
        *op = '\0';
        fputs(out, stdout);
        op = out;
    }
}

int main() {
    unsigned long long int power, base;
    while(readULLint(&base) && readULLint(&power) && base && power)
        fastPower(base, power);
    *op = '\0';
    fputs(out, stdout);
    return 0;
}

/*#include <stdio.h>//	AC (7.7s, 428KB)

int main(){
    long int index, i;
    long long int base, power, len, carry;
    while(scanf("%lld%lld", &base, &power) == 2 && base && power){
        long long int result[40000] = {0};
        len = 1;
        carry = 0;
        result[0] = 1;
        for(index = 0; index < power; index++){
            for(i = 0; i < len; i++){
                result[i] = result[i] * base + carry;
                carry = result[i] / 10000000000000;
                result[i] -= carry * 10000000000000;
                if(carry && (i + 1) == len)len++;
            }
        }
        printf("%lld", result[--len]);
        for(int i = --len; i >= 0; i--)
            printf("%013lld", result[i]);
        putchar('\n');
    }
}*/


/*#include <stdio.h>//AC (8.2s, 416KB)

int main(){
    long int index, i;
    long long int base, power, len, carry;
    while(scanf("%lld%lld", &base, &power) == 2 && base && power){
        long long int result[42000] = {0};
        len = 1;
        carry = 0;
        result[0] = 1;
        for(index = 0; index < power; index++){
            for(i = 0; i < len; i++){
                result[i] = result[i] * base + carry;
                carry = result[i] / 1000000000000;
                result[i] %= 1000000000000;
                if(carry && (i + 1) == len)len++;
            }
        }
        for(i = --len; i >= 0; i--){
            if(i != len)
                printf("%012lld", result[i]);
            else printf("%lld", result[i]);
        }
        putchar('\n');
    }
}*/
