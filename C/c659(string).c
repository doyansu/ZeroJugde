#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main(){
    int n;
    char str[SIZE],conj[SIZE],temp[SIZE],*p=str,ch;
    scanf("%s",conj);
    fgets(str,SIZE,stdin);
    while(sscanf(p,"%s%c",temp,&ch)!=EOF){
        p+=strlen(temp)+1;
        printf("%s ",temp);
        if(ch!='\n')printf("%s ",conj);
    }
}
