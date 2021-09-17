/*
https://home.gamer.com.tw/creationDetail.php?sn=4093823

#include <stdio.h>//d411
#define SIZE 10000

int main(){
    int n;
    char str[SIZE];
    while(scanf("%s%d", str, &n) == 2){
        register char *p = str;
        int count = 0, mod = 1<<n;
        while(*p != '\0')
            count = ((count<<3) + (count<<1) + ('0' ^ *p++)) % mod;
        if(count)printf("可惡!!算了這麼久%s竟然無法被2的%d次整除\n", str, n);
        else printf("YA!!終於算出%s可被2的%d次整除了!!\n", str, n);

    }
    return 0;
}

數字 ABCD == A * (10 ^ 3) + B * (10 ^ 2) + C * (10 ^ 1) + D * (10 ^ 0) 

相乘或相加的 先 MOD 結果與後 MOD 結果相同

設 MOD n -> ABCD % n == (A % n) * (10 ^ 3 % n) + (B % n) * (10 ^ 2 % n) + (C % n) * (10 ^ 1 % n) + (D % n) * (10 ^ 0 % n)  //(MOD n)


*/

#include <stdio.h>
#define SIZE 110

int main(){
    char str[SIZE];
    while(fgets(str, SIZE, stdin) != NULL){
        register char *p = str;
        int count = 0;
        while(*p != '\n')
            count = ((count<<3) + (count<<1) + ('0' ^ *p++)) % 81;
        if(count)puts("konosuba!");
        else puts("konopad!");

    }
    return 0;
}
