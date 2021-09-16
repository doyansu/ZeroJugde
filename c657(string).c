#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000
#define MAXINF 0x7fffffff

int main(){
    int n;
    char str[SIZE];
    while(fgets(str,SIZE,stdin)!=NULL){
        char *p=str,maxch,lastch='\0';
        int max=-1,len=0;
        while(*p!='\0'){
            if(*p==lastch)++len;
            else{
                if(len>max){
                    max=len;
                    maxch=lastch;
                }
                len=1;
            }
            lastch=*p;
            ++p;
        }
        putchar(maxch);
        putchar(' ');
        printf("%d",max);
        putchar('\n');
    }
}
