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
        if(count)printf("�i�c!!��F�o��[%s���M�L�k�Q2��%d���㰣\n", str, n);
        else printf("YA!!�ש��X%s�i�Q2��%d���㰣�F!!\n", str, n);

    }
    return 0;
}
