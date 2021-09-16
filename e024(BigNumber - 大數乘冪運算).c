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
