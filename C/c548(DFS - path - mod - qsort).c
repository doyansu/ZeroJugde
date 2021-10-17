#include <stdio.h>
#define SIZE 100001
#define BUFSIZE 2097152

typedef struct pigeon_s{
    int number, point;
}pigeon_t;

int n, k, len;
int path[SIZE];
pigeon_t list[SIZE];

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

static inline char readUint(unsigned int *input){
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
    char *p = &buf[11];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar(' ');
}

void swap(pigeon_t *a, pigeon_t *b){
    pigeon_t temp = *a;
    *a = *b;
    *b = temp;
}

int getMid(pigeon_t *list, int left, int right){
    //swap(&list[(left + right) / 2], &list[right]);
    int cmpValue = list[right].point;
    for(int i = left; i < right; i++)
        if(list[i].point <= cmpValue)
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(pigeon_t *list, int left, int right){
    if(right > left){
        int mid = getMid(list, left, right);
        myqsort(list, left, mid - 1);
        myqsort(list, mid + 1, right);
    }
}

char dfs(int sum, int start){
    if(sum == k)
        return 1;
    if(sum < k){
        for(int i = start; i < n; i++)
            if(dfs(sum + list[i].point, i + 1)){
                path[len++] = list[i].number;
                return 1;
            }
    }
    return 0;
}

int main(){
    while(readUint(&n)){
        readUint(&k);
        int temp;
        for(int i = 0; i < n; i++){
            readUint(&temp);
            list[i].number = i + 1;
            list[i].point = (temp % k);
        }
        myqsort(list, 0, n - 1);
        len = 0;
        dfs(0, 0);
        putint(len);
        putchar('\n');
        for(int i = 0; i < len; i++)putint(path[i]);
        putchar('\n');
    }
}

/*#include <stdio.h>
#define SIZE 100001
#define BUFSIZE 2097152

typedef struct pigeon_s{
    int number, point;
}pigeon_t;

int n, k, jugde;
int path[SIZE];
pigeon_t list[SIZE];

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

static inline char readUint(unsigned int *input){
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
    char *p = &buf[11];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar(' ');
}

void swap(pigeon_t *a, pigeon_t *b){
    pigeon_t temp = *a;
    *a = *b;
    *b = temp;
}

int getMid(pigeon_t *list, int left, int right){
    //swap(&list[(left + right) / 2], &list[right]);
    int cmpValue = list[right].point;
    for(int i = left; i < right; i++)
        if(list[i].point <= cmpValue)
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(pigeon_t *list, int left, int right){
    if(right > left){
        int mid = getMid(list, left, right);
        myqsort(list, left, mid - 1);
        myqsort(list, mid + 1, right);
    }
}

void dfs(int sum, int level){
    if(jugde)return ;
    if(sum == k){
        jugde = 1;
        putint(level);
        putchar('\n');
        for(int i = 0; i < level; i++)putint(path[i]);
    }
    else if(sum < k){
        for(int i = level; i < n; i++){
            path[level] = list[i].number;
            dfs(sum + list[i].point, level + 1);
        }
    }
}

int main(){
    while(readUint(&n)){
        readUint(&k);
        int temp;
        for(int i = 0; i < n; i++){
            readUint(&temp);
            list[i].number = i + 1;
            list[i].point = (temp % k);
        }
        myqsort(list, 0, n - 1);
        jugde = 0;
        dfs(0, 0);
        putchar('\n');
    }
}
*/
/*#include <stdio.h>
#define MAX 100010

int n, k, list[MAX], ans[MAX], aLen;

char dfs(int s, long long sum)
{
    if (!(sum % k) && sum)
        return 1;
    for (int i = s; i <= n; i++)
    {
        if (dfs(i + 1, sum + list[i]))
        {
            ans[aLen++] = i;
            return 1;
        }
    }
    return 0;
}

int main()
{
    while (scanf(" %d %d", &n, &k) == 2)
    {
        aLen = 0;
        for (int i = 1; i <= n; i++)
            scanf(" %d", &list[i]);
        if (dfs(1, 0))
        {
            printf("%d\n", aLen);
            for (int i = 0; i < aLen; i++)
                printf("%d ", ans[i]);
            putchar('\n');
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}
*/

/*
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cin.sync_with_stdio(false), cin.tie(0);
	int amount, multiple, scores, sums = 0, haveSum[100001], i;
	bool have = false;
	cin >> amount >> multiple;
	memset(haveSum, -1, sizeof(haveSum)), haveSum[0] = 0;
	for (i = 1; i <= amount; i++) {
		cin >> scores;
		sums = (sums + scores % multiple) % multiple;
		if (haveSum[sums] != -1) {
			cout << i - haveSum[sums] << '\n' << haveSum[sums] + 1;
			for (int j = haveSum[sums] + 2; j <= i; j++)
				cout << ' ' << j;
			cout << '\n';
			break;
		}
		haveSum[sums] = i;
	}
	for (i++; i <= amount; i++)
		cin >> scores;
}
*/

