#include <stdio.h>//	NA (score:15%)
#define MAXSIZE 200001
#define BUFSIZE 1048576

int n, q, BIT[MAXSIZE] = {0};

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

int lowbit(int a){
    return a & -a;
}

void initialBIT(){
    readUint(&n);
    readUint(&q);
    for(int i = 1; i <= n; i++){
        readUint(BIT + i);
        BIT[i] += BIT[i - 1];
    }
    for(int i = n; i > 0; i--)
        BIT[i] -= BIT[i - lowbit(i)];
}

int query(int left, int right){
    int ans = 0;
    while(right){
        ans += BIT[right];
        right -= lowbit(right);
    }
    left--;
    while(left){
        ans -= BIT[left];
        left -= lowbit(left);
    }
    return ans;
}

void update(int left, int right){
    int val = 1;
    while(left <= right){
        for(int i = left; i <= n; i += lowbit(i))
            BIT[i] += val;
        val++;
        left++;
    }
}

void operate(){
    int oper, left, right;
    while(q--){
        readUint(&oper);
        readUint(&left);
        readUint(&right);
        switch(oper){
        case 2:
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
    initialBIT();
    operate();
    return 0;
}
