#include <stdio.h>
#include <string.h>
#define MAXSIZE 10000

char str1[MAXSIZE], str2[MAXSIZE];

int gcd(int n, int m){
    return n % m ? gcd(m, n % m) : m;
}

int mystrcmp(char *s1, char *s2, int size){
    while(size--)
        if(*s1++ != *s2++)
            return 0;
    return 1;
}

char* getGCD(char *longer, char *shorter){
    char *temp;
    if(strlen(longer) < strlen(shorter)){
        temp = longer;
        longer = shorter;
        shorter = temp;
    }
    int lenl, lens, g = gcd(lenl = strlen(longer), lens =  strlen(shorter));
    for(int factor = g; factor > 0; factor--){
        if((g % factor) == 0){
            int j;
            for(j = factor; j < lens; j += factor){
                if(mystrcmp(shorter, shorter + j, factor) == 0)
                    break;
            }
            if(j != lens)
                continue;
            for(j = 0; j < lenl; j += factor){
                if(mystrcmp(shorter, longer + j, factor) == 0)
                    break;
            }
            if(j == lenl){
                shorter[factor] = '\0';
                return shorter;
            }
        }
    }
    return "= =";
}

int main(){
    while(scanf("%s%s", str1, str2) == 2)
        puts(getGCD(str1, str2));
    return 0;
}
