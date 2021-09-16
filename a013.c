#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int myabs(int n){
    return n>0?n:-n;
}

int cmp(char ch1,char ch2){
    int n1=0,n2=0;
    switch(ch1){
    case 'M':++n1;
    case 'D':++n1;
    case 'C':++n1;
    case 'L':++n1;
    case 'X':++n1;
    case 'V':++n1;
    case 'I':++n1;
    break;
    }
    switch(ch2){
    case 'M':++n2;
    case 'D':++n2;
    case 'C':++n2;
    case 'L':++n2;
    case 'X':++n2;
    case 'V':++n2;
    case 'I':++n2;
    break;
    }
    if(n1<=n2)return 0;
    return 1;
}


int chToPoint(char ch){
   switch(ch){
    case 'M' :return 1000;
    case 'D' :return 500;
    case 'C' :return 100;
    case 'L' :return 50;
    case 'X' :return 10;
    case 'V' :return 5;
    case 'I' :return 1;
    }
    return 0;
}

int turnToInt(char *str){
    int ans=0;
    while(*str!='\0'){
        if(cmp(*(str+1),*str)){
            ans+=chToPoint(*(str+1))-chToPoint(*str);
            str++;
        }
        else ans+=chToPoint(*str);
        str++;
    }
    return ans;
}

int modn(int n,char *output,int *index,int mod,char ch){
    while(n/mod){
        n-=mod;
        output[(*index)++]=ch;
    }
    return n;
}



char* check4(char *list){
    char *output=calloc(SIZE,sizeof(char));
    char *temp=list;
    int index=0;
    while(*temp!='\0'){
        if(*temp==*(temp+1) && *(temp+1)==*(temp+2) && *(temp+2)==*(temp+3)){
            if(*temp=='I'){
                if(*(temp-1)=='V'){
                    --index;
                    output[index++]='I';
                    output[index++]='X';
                }
                else{
                    output[index++]='I';
                    output[index++]='V';
                }
            }
            else if(*temp=='X'){
                if(*(temp-1)=='L'){
                    --index;
                    output[index++]='X';
                    output[index++]='C';
                }
                else{
                    output[index++]='X';
                    output[index++]='L';
                }
            }
            else if(*temp=='C'){
                if(*(temp-1)=='D'){
                    --index;
                    output[index++]='C';
                    output[index++]='M';
                }
                else{
                    output[index++]='C';
                    output[index++]='D';
                }
            }
            temp+=4;
        }
        else {
            output[index++]=*temp;
            temp++;
        }
    }
    output[index]='\0';
    free(list);
    return output;
}

char* turnToRome(int n){
    char *output=calloc(SIZE,sizeof(char));
    int index=0;
    n=modn(n,output,&index,1000,'M');
    n=modn(n,output,&index,500,'D');
    n=modn(n,output,&index,100,'C');
    n=modn(n,output,&index,50,'L');
    n=modn(n,output,&index,10,'X');
    n=modn(n,output,&index,5,'V');
    n=modn(n,output,&index,1,'I');
    output=check4(output);
    printf("%s\n",output);
    free(output);
}

int main(){
    char s1[SIZE],s2[SIZE];
    while(scanf("%s",s1)){
        if(*s1=='#')break;
        scanf("%s",s2);
        if((turnToInt(s1)-turnToInt(s2))!=0)turnToRome(myabs(turnToInt(s1)-turnToInt(s2)));
        else printf("ZERO\n");
    }
}
