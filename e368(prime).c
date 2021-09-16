#include <stdio.h>//AC (6ms, 64KB)
#include <string.h>
#define SIZE 725

int len = 1;
int list[SIZE] = {2};

/*int binarySearch(int n, int left, int right){
    int mid = (left + right) / 2;
    if(right < left)return 0;
    else if(list[mid] == n)return mid;
    else if(list[mid] > n)return binarySearch(n, left, mid - 1);
    return binarySearch(n, mid + 1, right);
}*/

int getList(int n){
    //if(binarySearch(n, 0, len - 1))return 1;
    //else if(n > list[len - 1]){
    for(int i = 0; i < len; i++){
        if(list[i] * list[i] > n)break;
        if(n%list[i] == 0)return 0;
    }
    return list[len++] = n;
    //}
    //return 0;
}

int isPrime(int n){
    if(n == 1)return 0;
    for(int i = 0; list[i] * list[i] <= n; i++){
        if(n % list[i] == 0)return 0;
    }
    return 1;
}

int main(){
    int date[17] = {103, 107, 113, 223, 307, 313, 317, 503, 523, 607, 613, 617, 823, 907, 1013, 1103, 1223};
    for(int i = 3; i < 5500; i++)getList(i);
    for(int i = 2000; i < 3000; i++){
        for(int j = 0; j < 17; j++){
            int mod = 10000000;
            for(int temp = i * 10000 + date[j]; mod > 1000; temp %= mod, mod /= 10)
                if(!isPrime(temp))break;
            if(mod == 1000)printf("%d/%02d/%02d\n", i, date[j]/100, date[j]%100);
        }
    }
    return 0;
}


/*#include <stdio.h>//AC (8ms, 80KB)
#include <string.h>
#define SIZE 725

int len = 1;
int list[SIZE] = {2};


int getList(int n){
    //if(binarySearch(n, 0, len - 1))return 1;
    //else if(n > list[len - 1]){
    for(int i = 0; i < len; i++){
        if(list[i] * list[i] > n)break;
        if(n%list[i] == 0)return 0;
    }
    return list[len++] = n;
    //}
    //return 0;
}

int isPrime(int n){
    if(n == 1)return 0;
    for(int i = 0; list[i] * list[i] <= n; i++){
        if(n % list[i] == 0)return 0;
    }
    return 1;
}

int main(){
    int date[17] = {103, 107, 113, 223, 307, 313, 317, 503, 523, 607, 613, 617, 823, 907, 1013, 1103, 1223};
    for(int i = 3; i < 5500; i++)getList(i);
    for(int i = 2000; i < 3000; i++){
        for(int j = 0; j < 17; j++){
            for(int temp = i * 10000 + date[j], mod = 10000000; mod > 1000; temp %= mod, mod /= 10){
                if(!isPrime(temp))break;
                if(mod == 10000)printf("%d/%02d/%02d\n", i, date[j]/100, date[j]%100);
            }
        }
    }
    return 0;
}*/
