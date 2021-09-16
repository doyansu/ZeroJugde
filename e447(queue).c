#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

nodep_t insertFromTail(nodep_t tail, int data){
    return tail->next = createNewNode(data);
}

int deleteFormFront(nodep_t pointer){
    nodep_t freeNode = pointer->next;
    pointer->data = freeNode->data;
    pointer->next = freeNode->next;
    free(freeNode);
    return pointer->data;
}

int main(){
    int n, oper;
    nodep_t queuep = createNewNode(-1), tail = queuep;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &oper);
        switch(oper){
        case 1:
            scanf("%d", &oper);
            tail = insertFromTail(tail, oper);
            break;
        case 2:
            if(queuep->next == NULL)puts("-1");
            else printf("%d\n", queuep->next->data);
            break;
        case 3:
            if(queuep->next != NULL){
                deleteFormFront(queuep);
                if(queuep->next == NULL)tail = queuep;
            }
            break;
        }
    }
    return 0;
}

/*#include <stdio.h>//AC (8ms, 1.3MB)
#define BUFSIZE 1048576
#define SIZE 100001

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
    putchar('\n');
}

int list[SIZE];

static inline void solve(){
    int n, oper;
    register int start = 0, tail = 0;
    readint(&n);
    while(n--){
        readint(&oper);
        switch(oper){
        case 1:
            readint(list + tail++);
            break;
        case 2:
            if(start == tail)puts("-1");
            else putint(list[start]);
            break;
        case 3:
            if(start != tail)start++;
            break;
        }
    }
}

int main(){
    solve();
    return 0;
}*/

/*#include <stdio.h>//	AC (10ms, 3.2MB)
#include <stdlib.h>
#define BUFSIZE 1048576
#define SIZE 100001

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
    putchar('\n');
}

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

static inline nodep_t createNewNode(int data){
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

static inline nodep_t insertFromTail(nodep_t tail, int data){
    return tail->next = createNewNode(data);
}

static inline int deleteFormFront(nodep_t pointer){
    nodep_t freeNode = pointer->next;
    pointer->data = freeNode->data;
    pointer->next = freeNode->next;
    free(freeNode);
    return pointer->data;
}

static inline void solve(){
    int n, oper;
    nodep_t queuep = createNewNode(-1), tail = queuep;
    readint(&n);
    while(n--){
        readint(&oper);
        switch(oper){
        case 1:
            readint(&oper);
            tail = insertFromTail(tail, oper);
            break;
        case 2:
            if(queuep->next == NULL)puts("-1");
            else putint(queuep->next->data);
            break;
        case 3:
            if(queuep->next != NULL){
                deleteFormFront(queuep);
                if(queuep->next == NULL)tail = queuep;
            }
            break;
        }
    }
}

int main(){
    solve();
    return 0;
}*/

/*#include <stdio.h>
#define SIZE 100001

int list[SIZE];

int main(){
    int n, oper;
    register int start = 0, tail = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &oper);
        switch(oper){
        case 1:
            scanf("%d", list + tail++);
            break;
        case 2:
            if(start == tail)puts("-1");
            else printf("%d\n", list[start]);
            break;
        case 3:
            if(start != tail)start++;
            break;
        }
    }
    return 0;
}*/
