#include <stdio.h>//	AC (11ms, 196KB)
#define SIZE 10001
#define BUFSIZE 65536

int parent[SIZE], groupSIZE[SIZE];

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

static inline char readUint(register int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

int findParnent(int a){
    return parent[a] == a ? a : (parent[a] = findParnent(parent[a]));
}

static inline void solve(){
    int n, m, q;
    while(readUint(&n)){
        readUint(&m);
        readUint(&q);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            groupSIZE[i] = 1;
        }
        int a, b;
        while(m--){
            readUint(&a);
            readUint(&b);
            a = findParnent(a);
            b = findParnent(b);
            if(a != b){
                if(groupSIZE[a] > groupSIZE[b]){
                    parent[b] = a;
                    groupSIZE[a] += groupSIZE[b];
                }
                else {
                    parent[a] = b;
                    groupSIZE[b] += groupSIZE[a];
                }
            }
        }
        while(q--){
            readUint(&a);
            readUint(&b);
            if(findParnent(a) == findParnent(b))puts(":)");
            else puts(":(");
        }
    }
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>//	AC (30ms, 148KB)
#define SIZE 10001

int parent[SIZE], groupSIZE[SIZE];

int findParnent(int a){
    return parent[a] == a ? a : findParnent(parent[a]);
}

static inline void solve(){
    int n, m, q;
    while(scanf("%d%d%d", &n, &m, &q) == 3){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            groupSIZE[i] = 1;
        }
        int a, b;
        while(m--){
            scanf("%d%d", &a, &b);
            a = findParnent(a);
            b = findParnent(b);
            if(a != b){
                if(groupSIZE[a] > groupSIZE[b]){
                    parent[b] = a;
                    groupSIZE[a] += groupSIZE[b];
                }
                else {
                    parent[a] = b;
                    groupSIZE[b] += groupSIZE[a];
                }
            }
        }
        while(q--){
            scanf("%d%d", &a, &b);
            if(findParnent(a) == findParnent(b))puts(":)");
            else puts(":(");
        }
    }
}

int main(){
    solve();
    return 0;
}*/
