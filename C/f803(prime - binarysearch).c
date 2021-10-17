/*
https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
利用埃式篩法 找出小於 10000000 的質數 並儲存成一個 list
再用二元搜索法找到再質數位於 list 的索引值
*/

#include <stdio.h>//AC (55ms, 12.2MB)
#define SIZE 664579
#define MAX 10000000

char array[MAX] = {'1', '1'};
int list[SIZE] = {2}, len = 1;

static inline void getPrime(){
    register int prime = 2;
    while(prime < 3163){
        for(int i = prime << 1; i < MAX; i += prime)array[i] = '1';
        while(array[++prime] == '1');
    }
    for(int i = 3; i < MAX; i += 2)
        if(array[i] == '\0')list[len++] = i;
}

static inline int binarySearch(int taget, int left, int right){
    int mid = (left + right) >> 1;
    if(right < left)return -1;
    if(list[mid] == taget)return mid + 1;
    else if(list[mid] > taget)return binarySearch(taget, left, --mid);
    else return binarySearch(taget, ++mid, right);
}

static inline void solve(){
    getPrime();
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d", &n);
        printf("%d\n", binarySearch(n, 0, SIZE - 1));
    }
}

int main(){
    solve();
    return 0;
}


/*#include <stdio.h>//	AC (0.1s, 40.8MB)
#define SIZE 664579
#define MAX 10000000

int array[MAX] = {1, 1};
int list[SIZE] = {2}, len = 1;

void getPrime(){
    int prime = 2;
    while(prime < 3163){
        for(int i = prime << 1; i < MAX; i += prime)array[i] = 1;
        while(array[++prime] == 1);
    }
    for(int i = 3; i < MAX; i += 2)
        if(array[i] == 0)list[len++] = i;
}

int binarySearch(int taget, int left, int right){
    int mid = (left + right) >> 1;
    if(right < left)return -1;
    if(list[mid] == taget)return mid + 1;
    else if(list[mid] > taget)return binarySearch(taget, left, --mid);
    else return binarySearch(taget, ++mid, right);
}

static inline void solve(){
    getPrime();
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d", &n);
        printf("%d\n", binarySearch(n, 0, SIZE - 1));
    }
}

int main(){
    solve();
    return 0;
}*/

/*#include <stdio.h>
#define SIZE 664579

int list[SIZE] = {2}, len = 1;

void getPrime(int n){
    for(int i = 0; list[i] * list[i] <= n; i++)
        if(n%list[i] == 0)return ;
    list[len++] = n;
}

int binarySearch(int taget, int left, int right){
    int mid = (left + right) >> 1;
    if(right < left)return -1;
    if(list[mid] == taget)return mid + 1;
    else if(list[mid] > taget)return binarySearch(taget, left, --mid);
    else return binarySearch(taget, ++mid, right);
}

static inline void solve(){
    for(int i = 3; i < 10000000; i += 2)getPrime(i);
    int n, m, data;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d", &n);
        printf("%d\n", binarySearch(n, 0, SIZE - 1));
    }
}

int main(){
    solve();
    return 0;
}*/
