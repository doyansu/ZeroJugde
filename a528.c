#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

int mystrcmp(char *s1,char *s2){
    if(*s1=='-' && *s2!='-')return 0;
    else if(*s1!='-' && *s2=='-')return 1;
    else if(*s1!='-' && *s2!='-'){
        if(strlen(s1)>strlen(s2))return 1;
        else if(strlen(s1)<strlen(s2))return 0;
        else{
            for(;*s1!='\0' || *s2!='\0';s1++,s2++){
                if(*s1>*s2 || *s2=='\0')return 1;
                else if(*s2>*s1 || *s1=='\0')return 0;
            }
        }
    }
    else{
        if(strlen(s1)>strlen(s2))return 0;
        else if(strlen(s1)<strlen(s2))return 1;
        else{
            for(;*s1!='\0' || *s2!='\0';s1++,s2++){
                if(*s1>*s2 || *s2=='\0')return 0;
                else if(*s2>*s1 || *s1=='\0')return 1;
            }
        }
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        char* list[SIZE];
        for(int i=0;i<n;++i){
            char *s=calloc(101,sizeof(char));
            scanf("%s",s);
            list[i]=s;
            for(int j=i;j>0;--j){
                char *temp;
                if(mystrcmp(list[j],list[j-1]))break;
                else {
                    temp=list[j];
                    list[j]=list[j-1];
                    list[j-1]=temp;
                }
            }
        }
        for(int i=0;i<n;++i)printf("%s\n",list[i]);
        for(int i=0;i<n;++i)free(list[i]);
    }
}
