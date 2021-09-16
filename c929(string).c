#include <stdio.h>//AC 1ms
#include <string.h>
#define SIZE 2002

int isTagetWord(char *s1,char *s2,int size){
    for(;size>0;s1++,s2++,size--){
        if(*s1!=*s2)return 0;
    }
    return 1;
}

char* mysplit(char *str,char *word,int wordsize){
    static char *p=NULL;
    if(str!=NULL)p=str;
    else str=p;
    while(*p!='\0'){
        if(isTagetWord(p,word,wordsize))break;
        p++;
    }
    if(*p=='\0'){
        p=str;
        return NULL;
    }
    *p='\0';
    p+=wordsize;
    return str;
}

int main(){
    char str[SIZE],word[SIZE];
    char *p;
    while(gets(word)!=NULL){
        fgets(str,SIZE,stdin);
        int wordSize=strlen(word);
        p=mysplit(str,word,wordSize);
        while(p!=NULL){
            puts(p);
            p=mysplit(NULL,word,wordSize);
        }
        p=mysplit(NULL,"\n",1);
        puts(p);
        //memset(str,0,sizeof(str));
        //memset(word,0,sizeof(word));
    }
}
