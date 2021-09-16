#include <stdio.h>//AC (3ms, 3.9MB)
#include <stdlib.h>
#define SIZE 500001
#define BUFSIZE 2097152

typedef struct node_s{
    int left, right;
}node_t;

node_t list[SIZE];

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
    char *p = buf + 11;
    *(p + 1) = '\0';
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar(' ');
}

void Move(){
    int a, b;
    char oper = readChar();
    readUint(&a);
    readUint(&b);
    if(a == b)return;
    int left = list[a].left, right = list[a].right;
    list[left].right = right;
    list[right].left = left;
    if(oper == 'R'){
        left = list[b].left;
        list[left].right = a;
        list[b].left = a;
        list[a].left = left;
        list[a].right = b;
    }
    else {
        right = list[b].right;
        list[right].left = a;
        list[b].right = a;
        list[a].left = b;
        list[a].right = right;
    }

}

int main(){
    int n, m, q;
    readUint(&n);
    readUint(&m);
    readUint(&q);
    for(int i = 0; i < n; i++){
        list[i].left = i - 1;
        list[i].right = i + 1;
    }
    list[0].left = n - 1;
    list[n - 1].right = 0;
    while(m--)Move(list);
    while(q--){
        readUint(&m);
        putint(list[m].left);
        putint(list[m].right);
    }
}

/*#include <stdio.h>//	AC (25ms, 19.1MB)
#include <stdlib.h>
#define SIZE 500001
#define BUFSIZE 2097152

typedef struct node_s{
    int number;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;


nodep_t list[SIZE];


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
    char *p = buf + 11;
    *(p + 1) = '\0';
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar(' ');
}

nodep_t createNewNode(int number, nodep_t left){
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->number = number;
    newNode->left = left;
    newNode->right = NULL;
    return newNode;
}

void createCircle(int n){
    list[0] = createNewNode(0, NULL);
    for(int i = 0; i < n; list[i] = list[i++]->right = createNewNode(i + 1, list[i]));
    list[0]->left = list[n - 1];
    list[n - 1]->right = list[0];
}

void Move(){
    readChar();
    int a, b;
    char oper = readChar();
    readUint(&a);
    readUint(&b);
    if(a == b)return;
    nodep_t left = list[a]->left, right = list[a]->right;
    left->right = right;
    right->left = left;
    if(oper == 'R'){
        left = list[b]->left;
        left->right = list[a];
        list[b]->left = list[a];
        list[a]->left = left;
        list[a]->right = list[b];
    }
    else {
        right = list[b]->right;
        right->left = list[a];
        list[b]->right = list[a];
        list[a]->left = list[b];
        list[a]->right = right;
    }
}

int main(){
    int n, m, q;
    readUint(&n);
    readUint(&m);
    readUint(&q);
    createCircle(n);
    while(m--)Move();
    while(q--){
        readUint(&m);
        putint(list[m]->left->number);
        putint(list[m]->right->number);
    }
}*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 500001

typedef struct node_s{
    int number;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;



nodep_t list[SIZE];



nodep_t createNewNode(int number, nodep_t left){
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->number = number;
    newNode->left = left;
    newNode->right = NULL;
    return newNode;
}

void createCircle(int n){
    list[0] = createNewNode(0, NULL);
    for(int i = 0; i < n; list[i] = list[i++]->right = createNewNode(i + 1, list[i]));
    list[0]->left = list[n - 1];
    list[n - 1]->right = list[0];
}

void Move(){
    int a, b;
    char oper;
    scanf(" %c%d%d", &oper, &a, &b);
    if(a == b)return;
    nodep_t left = list[a]->left, right = list[a]->right;
    left->right = right;
    right->left = left;
    if(oper == 'R'){
        left = list[b]->left;
        left->right = list[a];
        list[b]->left = list[a];
        list[a]->left = left;
        list[a]->right = list[b];
    }
    else {
        right = list[b]->right;
        right->left = list[a];
        list[b]->right = list[a];
        list[a]->left = list[b];
        list[a]->right = right;
    }
}

int main(){
    int n, m, q;
    while(scanf("%d%d%d", &n, &m, &q) == 3){
        createCircle(n);
        while(m--)Move();
        nodep_t pointer = list[0];
        while(q--){
            scanf("%d", &m);
            printf("%d %d ", list[m]->left->number, list[m]->right->number);
        }
        putchar('\n');
    }
}*/
