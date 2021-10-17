#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int k,temp=1,indexl=0,*length=calloc(100000,sizeof(int));
    char *s=calloc(100000,sizeof(char));
    scanf("%d",&k);
    scanf("%s",s);
    int index=1,lasttype=2,type;
    if(s[0]>64 && s[0]<91)lasttype=1;
    else if(s[index]>=96 && s[index]<123)lasttype=0;
    do{
        if(s[index]>64 && s[index]<91)type=1;
        else if(s[index]>96 && s[index]<123)type=0;
        if(s[index]=='\0')length[indexl++]=temp;
        if(lasttype!=type){
            length[indexl++]=temp;
            temp=1;
        }
        else temp++;
        lasttype=type;
    }while(s[index++]!='\0');
    temp=0;
    int maxlen=0;
    for(int i=0;i<indexl;i++){
        if(length[i]>k){
            temp+=k;
            if(temp>maxlen)maxlen=temp;
            temp=k;
            }
        else if(length[i]==k)temp+=k;
        else temp=0;
        if(temp>maxlen)maxlen=temp;
    }
    if(strlen(s)==1)printf("1");
    else printf("%d",maxlen);
}
