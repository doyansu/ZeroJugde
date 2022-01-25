#include <stdio.h>//	AC (4ms, 96KB)
//參考 https://home.gamer.com.tw/creationDetail.php?sn=4774857
//先找到 n 對應數字的長度，再找到該數字，在找到是第幾位

int solve(long long int index){
    static long long int numOfDigit[10] = {0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889},
                           start[10] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    long long int digit;
    int len, temp[10];
    for(len = 0; index > numOfDigit[len]; len++);
    index -= numOfDigit[len - 1];
    digit = start[len] + (index - 1) / len;
    //printf("%lld\n", digit);
    for(int i = len - 1; i >= 0; i--, digit /= 10)
        temp[i] = digit%10;
    return temp[(index - 1)%len];
}

int main(){
    long long int n;
    while(scanf("%lld", &n) == 1)
        printf("%d\n", solve(n));
    return 0;
}
