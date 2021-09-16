#include <stdio.h>//	AC (0.2s, 8.7MB)
#include <stdlib.h>
#define SIZE 500000
#define BUFSIZE 1048576

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

static inline char readint(register int *input){
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

typedef struct node_s{
    int x, y;
}node_t;

int Case = 1;
node_t list[SIZE];

int cmp(const node_t *a, const node_t *b){
    return  a->y != b->y ? b->y - a->y : b->x - a->x;
}

int main(){
    int n;
    node_t *p ,*end;
    while(readint(&n)){
        printf("Case %d:\n", Case++);
        for(int i = 0; i < n; i++){
            readint(&list[i].x);
            readint(&list[i].y);
        }
        qsort(list, n, sizeof(node_t), cmp);
        int x = list[0].x, y = list[0].y, len = 1;
        p = list;
        end = list + n;
        while(++p < end){
            if(p->y < y && p->x > x){
                list[len++] = *p;
                x = p->x;
                y = p->y;
            }
        }
        p = list;
        end = list + len;
        printf("Dominate Point: %d\n", len);
        while(p < end){
            printf("(%d,%d)\n", p->x, p->y);
            p++;
        }
    }
}

/*#include <stdio.h>//	AC (0.3s, 7.7MB)
#include <stdlib.h>
#define SIZE 500000

typedef struct node_s{
    int x, y;
}node_t;

int Case = 1;
node_t list[SIZE], out[SIZE];

int cmp(const node_t *a, const node_t *b){
    return  a->y != b->y ? b->y - a->y : b->x - a->x;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        printf("Case %d:\n", Case++);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &list[i].x, &list[i].y);
        qsort(list, n, sizeof(node_t), cmp);
        int x = list[0].x, y = list[0].y, len = 1;
        out[0] = list[0];
        for(int i = 1; i < n; i++){
            if(list[i].y < y && list[i].x > x){
                out[len++] = list[i];
                x = list[i].x;
                y = list[i].y;
            }
        }
        printf("Dominate Point: %d\n", len);
        for(int i = 0; i < len; i++)
            printf("(%d,%d)\n", out[i].x, out[i].y);

    }
}*/
