/*
所求為 一質數 x 使 n%x 值為最大 (x <= n)(100 <= n <=10000)
(n - p*x) p 越大 x 就越小 當 p = 1 即為 n%x 的最大化 
p = 1 代表 x > n / 2
x 越接近 n 餘數越小
所以第一個大於 (n/2) 質數即為所求

先用埃式篩法找出小於 10000 的質數建成清單，再利用二元搜尋法找到目標。
*/

#include <stdio.h>//	AC (2ms, 100KB)
#define PRIMESIZE 1229
#define MAXINPUT 10000

int prime[PRIMESIZE];
char isnotprime[MAXINPUT];

int binarySearch(int target, int left, int right){
    if(left > right)return left;
    int mid = (left + right) >> 1;
    if(prime[mid] == target)return mid;
    else if(prime[mid] > target)return binarySearch(target, left, mid - 1);
    return binarySearch(target, mid + 1, right);
}


static inline void solve(){
    int p = 2;
    while(p < 100){
        for(int i = p << 1; i < MAXINPUT; i += p)
            isnotprime[i] = 1;
        while(isnotprime[++p]);
    }
    p = 0;
    for(int i = 0; i < MAXINPUT; i++)
        if(isnotprime[i] == 0)
            prime[p++] = i;
    int m;
    scanf("%d", &m);
    while(m--){
        int n;
        scanf("%d", &n);
        printf("%d\n", prime[binarySearch((n >> 1) + 1, 0, 1228)]);
    }
}

int main(){
    solve();
    return 0;
}
