#include <stdio.h>
#include <string.h>
#define SIZE 27

void Initialize(int list[SIZE][SIZE],int AccumulateC26[SIZE]){
    for(int i=0;i<SIZE;i++)
        list[0][i]=list[i][0]=1;
    for(int i=2;i<SIZE;i++)
        for(int j=1,k=i-1;j!=i;j++,k--)
            list[j][k]=list[j-1][k]+list[j][k-1];
    for(int i=1;i<SIZE;i++)AccumulateC26[i]=list[i][26-i]+AccumulateC26[i-1];
}

int isCurrCode(char* str){
    str++;
    while(*str!='\n'){
        if(*(str-1)>=*str)return 0;
        str++;
    }
    return 1;
}

int main(){
    char str[SIZE+1];
    int list[SIZE][SIZE]={0};
    int AccumulateC26[SIZE]={1};
    Initialize(list,AccumulateC26);
    //for(int i=0;i<SIZE;i++)printf("%d ",AccumulateC26[i]);
    /*for(int i=0;i<27;++i){
        for(int j=0;j<27;++j)printf("%8d",list[i][j]);
        putchar('\n');
    }*/
    while(fgets(str,SIZE+1,stdin)){
        if(*str=='0')break;
        if(isCurrCode(str)){
            int len=strlen(str)-1;
            int code=AccumulateC26[--len];
            for(char *p=str,last='a';*p!='\n';p++,last++,len--)
                for(;last!=*p;last++)
                    code+=list[25-(last-'a')-len][len];
            printf("%d\n",code);
        }
        else puts("0");
    }
}
