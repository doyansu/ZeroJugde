#include <stdio.h>
#include <string.h>
#define SIZE 20000

int main()
{
    char str[SIZE];
    while(fgets(str,SIZE,stdin)!=NULL){
        long long int sum=0;
        char *p=str;
        while(*p!='\0'){
            if(*p!=' '){
                int temp=0;
                while(*p!=' ' && *p!='\n'){
                    temp=(temp<<3)+(temp<<1)+*p-'0';
                    ++p;
                }
                sum+=temp;
            }
            ++p;
        }
        printf("%lld\n",sum);
    }
}
