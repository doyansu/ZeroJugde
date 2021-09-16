#include <stdio.h>
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
