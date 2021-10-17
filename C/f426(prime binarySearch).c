#include <stdio.h>//AC (2ms, 92KB)
#define MAXSIZE 10001
#define PRIMESIZE 1229

int prime[PRIMESIZE] = {0}, prefix[PRIMESIZE + 1] = {0};
char isnotprime[MAXSIZE] = {1, 1};

int binarySearch(int target, int left, int right, char type){
    if(left > right)
        return type ? right : left;
    int mid = (left + right) >> 1;
    if(prime[mid] == target)
        return mid;
    else if(prime[mid] > target)
        return binarySearch(target, left, mid - 1, type);
    else
        return binarySearch(target, mid + 1, right, type);
}

void initial(){
    int temp = 2, len = 0;
    while(temp < 100){
        for(int i = temp << 1; i < MAXSIZE; i += temp)
            isnotprime[i] = 1;
        while(isnotprime[++temp]);
    }
    for(int i = 2; i < MAXSIZE; i++)
        if(isnotprime[i] == 0){
            prime[len++] = i;
            prefix[len] = prefix[len - 1] + i;
        }
}

int main(){
    initial();
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        n = binarySearch(n, 0, PRIMESIZE, 0);
        m = binarySearch(m, 0, PRIMESIZE, 1);
       // printf("n = %d m = %d\n", n, m);
        printf("%d\n", m - n + 1);
        printf("%d\n", prefix[m + 1] - prefix[n]);
    }
}
