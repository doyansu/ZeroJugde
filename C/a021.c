#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 500
#define SIGNF 499

int transToint(int *n,char *temp){
    int index=0,length;
    length=strlen(temp);
    if(temp[0]=='-'){
        length-=1;
        n[SIGNF]=1;
    }
    while(temp[index++]!='\0'){
        if(temp[0]=='-')n[length-index]=temp[index]-'0';
        else n[length-index]=temp[index-1]-'0';
    }
    return length;
}

int add(int *result,int *summand,int *addend){
    int carry=0,temp;
    for(int i=0;i<SIGNF;i++){
        temp=summand[i]+addend[i]+carry;
        result[i]=temp%10;
        carry=temp/10;
    }
}

int compment10s(int *number){
    int *one=calloc(SIZE,sizeof(int));
    one[0]=1;
    for(int i=0;i<SIGNF;i++)number[i]=9-number[i];
    add(number,number,one);
}

int shift(int *number,int carry){
    for(int i=SIGNF-1;i>0;i--)number[i]=number[i-1];
    number[0]=carry;
}

int shiftdiv(int *number,int carry){
    for(int i=0;i<SIZE;i++)number[i]=number[i+1];
    number[SIGNF]=carry;
}



/*int intTochar(int *n,char *c){
    for(int i=SIGNF;i>=0;i--)c[i]=n[SIGNF-i]+'0';
}

int moves1(char *s1){
    char *temp=calloc(SIZE,sizeof(char));
    for(int i=0;i<SIZE-1;i++)temp[i]='0';
    for(int i=0;i<strlen(s1);i++)temp[SIZE-strlen(s1)+i]=s1[i];
    strcpy(s1,temp);
}*/



int additionANDsubtraction(int *n1,int *n2,int biglen,int condition){
    if(condition)add(n1,n1,n2);
    else{
        if(n1[SIGNF]==1)compment10s(n1);
        else compment10s(n2);
        add(n1,n1,n2);
        if(n1[biglen]==9){
            compment10s(n1);
            n1[SIGNF]=1;
        }
        else n1[SIGNF]=0;
    }
    if(n1[SIGNF]==1)printf("-");
    int iszero=1;
    for(int i=SIGNF-1;i>=0;i--){
        if(n1[i]!=0)iszero=0;
        if(iszero==0)printf("%d",n1[i]);
    }
    if(iszero==1)printf("0");
}


int multiplication(int *n1,int *n2,int len1){
    int *result=calloc(SIZE,sizeof(int));
    for(int x=0;x<len1;x++){
        for(int y=0;y<n1[x];y++)add(result,result,n2);
        shift(n2,0);
    }
    if(n1[SIGNF]!=n2[SIGNF])printf("-");
    int iszero=1;
    for(int i=SIGNF-1;i>=0;i--){
        if(result[i]!=0)iszero=0;
        if(iszero==0)printf("%d",result[i]);
    }
    if(iszero==1)printf("0");
}

/*int divisionvision1(char *s1,int *n2){
    int result=0;
    int *temp=calloc(SIZE,sizeof(int));
    char *cmp=calloc(SIZE,sizeof(char));
    moves1(s1);
    add(temp,temp,n2);
    intTochar(temp,cmp);
    //printf("s1=%s\n",s1);
    while(strcmp(s1,cmp)>=0){
        //printf("cmp=%s\n",cmp);
        add(temp,temp,n2);
        intTochar(temp,cmp);
        result++;
    }
    printf("%d",result);
}*/

int division(int *n1,int *n2,int len1,int len2){
    int d=len1-len2;
    if(d<0){
        printf("0");
        return 0;
    }
    for(int i=0;i<d;i++)shift(n2,0);
    int *quotient=calloc(SIZE,sizeof(int));
    d++;
    while(d--){
        int tempQuotient=-1;
        compment10s(n2);
        while(n1[len1]!=9){
            add(n1,n1,n2);
            tempQuotient++;
        }
        compment10s(n2);
        add(n1,n1,n2);
        shiftdiv(n2,0);
        int *one=calloc(SIZE,sizeof(int));
        one[0]=1;
        for(int i=0;i<d;i++)shift(one,0);
        for(int i=0;i<tempQuotient;i++)add(quotient,quotient,one);
    }
    int iszero=1;
    for(int i=SIGNF-1;i>=0;i--){
        if(quotient[i]!=0)iszero=0;
        if(iszero==0)printf("%d",quotient[i]);
    }
    if(iszero==1)printf("0");
}

int main(){
    char type;
    int *number1=calloc(SIZE,sizeof(int)),*number2=calloc(SIZE,sizeof(int));
    char *s1=calloc(SIZE,sizeof(char)),*s2=calloc(SIZE,sizeof(char));
    gets(s1);
    s1=strtok(s1," ");
    type=strtok(NULL," ")[0];
    s2=strtok(NULL," ");
    int length1=transToint(number1,s1),length2=transToint(number2,s2);
    int biglen=0,condition=0;
    if(length1>length2)biglen=length1;
    else biglen=length2;
    switch(type){
    case '+':
        if(number1[SIGNF]==number2[SIGNF])condition=1;
        additionANDsubtraction(number1,number2,biglen,condition);
        break;
    case '-':
        if(number1[SIGNF]!=number2[SIGNF])condition=1;
        additionANDsubtraction(number1,number2,biglen,condition);
        break;
    case '*':
        multiplication(number1,number2,length1);
        break;
    case '/':
        division(number1,number2,length1,length2);
        break;
    }
}
