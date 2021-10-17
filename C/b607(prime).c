#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000001

int cmp(const int *a, const int *b){
    return *a - *b;
}

int binarySearch(int list[], int target, int left, int right){
    if(left > right)return right;
    int mid = (left + right) >> 1;
    if(list[mid] == target)return mid;
    else if(list[mid] > target)return binarySearch(list, target, left, mid - 1);
    return binarySearch(list, target, mid + 1, right);
}

static inline void solve(){
    int n = 0, prime = 2, list[78498];//28665
    char isnotprime[SIZE] = {0, 0};
    while(prime < 1001){
        for(int i = prime << 1; i < SIZE; i += prime)
            isnotprime[i] = 1;
        while(isnotprime[++prime]);
    }
    for(int i = 2; i < SIZE; i++)
        if(!isnotprime[i])list[n++] = i;
    while(scanf("%d", &n) == 1 && n){
        if(isnotprime[n]){
            if(n&1){
                if(isnotprime[n - 2]){
                    int ans[3];
                    long long int max = -1;
                    for(int temp = n / 3, j = binarySearch(list, temp, 0, 28666); j > 0; j--){
                        for(int i = binarySearch(list, (n - list[j]) >> 1, 0, 28666); i > 0; i--){
                            if(!isnotprime[n - list[j] - list[i]]){
                                long long int t = list[j];
                                t *= list[i];
                                t *= n - list[j] - list[i];
                                if(max < t){
                                    max = t;
                                    //printf("%lld\n", max);
                                    ans[0] = list[j];
                                    ans[1] = list[i];
                                    ans[2] = n - list[j] - list[i];
                                }
                                else if (max > t + 100000)break;
                            }
                        }
                    }
                    qsort(ans, 3, sizeof(int), cmp);
                    printf("3 %d %d %d\n", ans[0], ans[1], ans[2]);
                }
                else
                    printf("2 2 %d\n", n - 2);
            }
            else {
                for(prime = n >> 1; prime > 2 && (isnotprime[prime] || isnotprime[n - prime]); prime--);
                printf("2 %d %d\n", prime, n - prime);
            }
        }
        else
            printf("1 %d\n", n);
    }
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000001

int cmp(const int *a, const int *b){
    return *a - *b;
}

static inline void solve(){
    int n = 0, prime = 2, list[100000];
    char isnotprime[SIZE] = {0, 0};
    while(prime < 1001){
        for(int i = prime << 1; i < SIZE; i += prime)
            isnotprime[i] = 1;
        while(isnotprime[++prime]);
    }
    for(int i = 2; i < SIZE; i++)
        if(!isnotprime[i])list[n++] = i;
    while(scanf("%d", &n) == 1 && n){
        if(isnotprime[n]){
            if(n&1){
                if(isnotprime[n - 2]){
                    int ans[3];
                    long long int max = -1;
                    for(int j = 25000, temp = n / 3; list[j] <= temp; j++){
                        for(int i = 25000; list[i] <= ((n - list[j]) >> 1); i++){
                            if(!isnotprime[n - list[j] - list[i]]){
                                long long int t = list[j];
                                t *= list[i];
                                t *= n - list[j] - list[i];
                                if(max < t){
                                    max = t;
                                    ans[0] = list[j];
                                    ans[1] = list[i];
                                    ans[2] = n - list[j] - list[i];
                                }
                                //else break;
                            }
                        }
                    }
                    qsort(ans, 3, sizeof(int), cmp);
                    printf("3 %d %d %d\n", ans[0], ans[1], ans[2]);
                }
                else
                    printf("2 2 %d\n", n - 2);
            }
            else {
                for(prime = n >> 1; prime > 2 && (isnotprime[prime] || isnotprime[n - prime]); prime--);
                printf("2 %d %d\n", prime, n - prime);
            }
        }
        else
            printf("1 %d\n", n);
    }
}

int main(){
    solve();
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000001

int cmp(const int *a, const int *b){
    return *a - *b;
}

static inline void solve(){
    int n, prime = 2, i;
    char isnotprime[SIZE] = {0, 0};
    while(prime < 1001){
        for(i = prime << 1; i < SIZE; i += prime)
            isnotprime[i] = 1;
        while(isnotprime[++prime]);
    }
    while(scanf("%d", &n) == 1 && n){
        if(isnotprime[n]){
            if(n&1){
                if(isnotprime[n - 2]){
                    long long int temp = n / 3;
                    if((temp<<1) + temp == n)
                        printf("3 %d %d %d\n", temp, temp, temp);
                    else {
                        int ans[3];
                        long long int max = -1;
                        if((temp&1) == 0)temp--;
                        while(temp > 2){
                            while(isnotprime[temp])
                                temp -= 2;
                            for(i = (n - temp) >> 1; i > 2 && (isnotprime[i] || isnotprime[n - temp - i]); i -= 2);
                            //printf("%lld\n", max);
                            if(max < temp * i * (n - temp - i)){
                                max = temp * i * (n - temp - i);
                                //printf("%lld\n", max);
                                ans[0] = temp;
                                ans[1] = i;
                                ans[2] = n - temp - i;
                            }
                            temp -= 2;
                        }
                        qsort(ans, 3, sizeof(int), cmp);
                        printf("3 %d %d %d\n", ans[0], ans[1], ans[2]);
                    }

                }
                else
                    printf("2 2 %d\n", n - 2);
            }
            else {
                for(i = n >> 1; i > 2 && (isnotprime[i] || isnotprime[n - i]); i -= 2);
                printf("2 %d %d\n", i, n - i);
            }
        }
        else
            printf("1 %d\n", n);
    }
}

int main(){
    solve();
    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000001

int cmp(const int *a, const int *b){
    return *a - *b;
}

static inline void solve(){
    int n, prime = 2, i;
    char isnotprime[SIZE] = {0, 0};
    while(prime < 1001){
        for(i = prime << 1; i < SIZE; i += prime)
            isnotprime[i] = 1;
        while(isnotprime[++prime]);
    }
    while(scanf("%d", &n) == 1 && n){
        if(isnotprime[n]){
            if(n&1){
                if(isnotprime[n - 2]){
                    long long int temp = n / 3;
                    if((temp<<1) + temp == n)
                        printf("3 %d %d %d\n", temp, temp, temp);
                    else {
                        int ans[3];
                        long long int max = -1;
                        if((temp&1) == 0)temp--;
                        while(temp > 300000){
                            while(isnotprime[temp])
                                temp -= 2;
                            for(i = (n - temp) >> 1; i > 1 && isnotprime[i]; i -= 2);
                            if(max < temp * i * (n - temp - i)){
                                //printf("%lld\n", temp * i * (n - i));
                                max = temp * i * (n - temp - i);
                                ans[0] = temp;
                                ans[1] = i;
                                ans[2] = n - temp - i;
                            }
                        }
                        qsort(ans, 3, sizeof(int), cmp);
                        printf("3 %d %d %d\n", ans[0], ans[1], ans[2]);
                    }

                }
                else
                    printf("2 2 %d\n", n - 2);
            }
            else {
                for(i = n >> 1; i > 0 && isnotprime[i]; i--);
                printf("2 %d %d\n", i, n - i);
            }
        }
        else
            printf("1 %d\n", n);
    }
}

int main(){
    solve();
    return 0;
}*/
