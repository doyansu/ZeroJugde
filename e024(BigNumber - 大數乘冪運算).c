/*
大數用千萬進制做完乘法後再進位速度遠高於十億進制一邊乘一邊進位。

除法和取餘運算很久，改成用除法得到商後再將原數減去除法得到的商乘上一千萬，也就是將

a = n / 10;
b = n % 10;

改成

a = n / 10;
b = n - (a * 10);

不過 10 要改成 1000 萬

乘法用左移運算加速

用指標減少記憶體操作量

輸入輸出優化
*/

#include <stdio.h>//	AC (7.7s, 428KB)

int main(){
    long int index, i;
    long long int base, power, len, carry;
    while(scanf("%lld%lld", &base, &power) == 2 && base && power){
        long long int result[40000] = {0};
        len = 1;
        carry = 0;
        result[0] = 1;
        for(index = 0; index < power; index++){
            for(i = 0; i < len; i++){
                result[i] = result[i] * base + carry;
                carry = result[i] / 10000000000000;
                result[i] -= carry * 10000000000000;
                if(carry && (i + 1) == len)len++;
            }
        }
        printf("%lld", result[--len]);
        for(int i = --len; i >= 0; i--)
            printf("%013lld", result[i]);
        putchar('\n');
    }
}


/*#include <stdio.h>//AC (8.2s, 416KB)

int main(){
    long int index, i;
    long long int base, power, len, carry;
    while(scanf("%lld%lld", &base, &power) == 2 && base && power){
        long long int result[42000] = {0};
        len = 1;
        carry = 0;
        result[0] = 1;
        for(index = 0; index < power; index++){
            for(i = 0; i < len; i++){
                result[i] = result[i] * base + carry;
                carry = result[i] / 1000000000000;
                result[i] %= 1000000000000;
                if(carry && (i + 1) == len)len++;
            }
        }
        for(i = --len; i >= 0; i--){
            if(i != len)
                printf("%012lld", result[i]);
            else printf("%lld", result[i]);
        }
        putchar('\n');
    }
}*/
