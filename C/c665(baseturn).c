#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){
    char table[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int chTOint[43]={0,1,2,3,4,5,6,7,8,9,-1,-1,-1,-1,-1,-1,-1,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
    char number[SIZE];
    while(scanf("%s",number)!=EOF){
        int b1,b2;
        unsigned long long int n=0;
        char *p=number;
        scanf("%d%d",&b1,&b2);
        while(*p!='\0'){
            n=n*b1+chTOint[*p-'0'];
            ++p;
        }
        char out[SIZE];
        int index=0;
        while(n){
            out[index++]=table[n%b2];
            n/=b2;
        }
        --index;
        for(int i=index;i>=0;--i)putchar(out[i]);
        putchar('\n');
    }
}
