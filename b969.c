#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    char *str=malloc(SIZE*sizeof(char));
    char hello[SIZE];
    gets(str);
    gets(hello);
    char *index=str;
    while(*index!='\0'){
        if(*index==' '){
            *index='\0';
            printf("%s, %s\n",hello,str);
            str=index+1;
        }
        ++index;
    }
    *index='\0';
    printf("%s, %s\n",hello,str);
}
