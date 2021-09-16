#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1253

void add(int *num1,int *num2,int len1,int len2,int carry){
    int temp=0;
    if(carry){
        while(carry){
            temp=num1[len1]+carry;
            num1[len1--]=temp%10;
            carry=temp/10;
        }
        return;
    }
    while(len1>=0){
        temp=num1[len1]+num2[len2--]+carry;
        num1[len1--]=temp%10;
        carry=temp/10;
    }
}

void shift(int *num,int size,int carry){
    for(int i=size-1;i>0;--i)num[i]=num[i-1];
    num[0]=0;
}

void compment10s(int *num,int len){
    int temp=len;
    while(temp>=0)num[temp--]=9-num[temp];
    add(num,num,len,len,1);
}

void division(int *num1,int *num2,int len1,int len2){
    int d=len1-len2;
    int templen2=len2;
    int lenq=d+1;
    int quoti[lenq];
    memset(quoti,0,sizeof(quoti));
    ++d;
    while(d){
        int tempQ=0;
        compment10s(num2,templen2);
        do{
            add(num1,num2,templen2,templen2,0);
            if(*num1==9)break;
            ++tempQ;
        }while(1);
        compment10s(num2,templen2);
        add(num1,num2,templen2,templen2,0);
        shift(num2,len1+1,0);
        ++templen2;
        int one[lenq];
        memset(one,0,sizeof(one));
        one[0]=1;
        for(int i=0;i<lenq-d;++i)shift(one,lenq,0);
        for(int i=0;i<tempQ;i++)add(quoti,one,lenq-1,lenq-1,0);
        --d;
    }
    int iszero=1;
    for(int i=0;i<lenq;++i){
        if(quoti[i])iszero=0;
        if(!iszero)printf("%d",quoti[i]);
    }
    if(iszero)printf("0");
    printf("    ");
    iszero=1;
    for(int i=0;i<len1+1;++i){
        if(num1[i])iszero=0;
        if(!iszero)printf("%d",num1[i]);
    }
    if(iszero)printf("0");
    printf("\n");
}

int main(){
    char s1[SIZE],s2[SIZE];
    while(scanf("%s",s1)!=EOF){
        scanf("%s",s2);
        int len1=strlen(s1),len2=strlen(s2);
        int num1[len1+1],num2[len1+1];
        if(len1<len2){
            printf("0    %s\n",s1);
            continue;
        }
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        for(int i=1;i<len1+1;++i)num1[i]=s1[i-1]-'0';
        for(int i=1;i<len2+1;++i)num2[i]=s2[i-1]-'0';
        division(num1,num2,len1,len2);
    }
}





/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 1253
#define SIGNF 1252

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

void add(int *result,int *summand,int *addend){
    int carry=0,temp;
    for(int i=0;i<SIGNF;i++){
        temp=summand[i]+addend[i]+carry;
        result[i]=temp%10;
        carry=temp/10;
    }
}

void compment10s(int *number){
    int *one=calloc(SIZE,sizeof(int));
    one[0]=1;
    for(int i=0;i<SIGNF;i++)number[i]=9-number[i];
    add(number,number,one);
    free(one);
}

void shift(int *number,int carry){
    for(int i=SIGNF-1;i>0;i--)number[i]=number[i-1];
    number[0]=carry;
}

void shiftdiv(int *number,int carry){
    for(int i=0;i<SIZE;i++)number[i]=number[i+1];
    number[SIGNF]=carry;
}


int division(int *n1,int *n2,int len1,int len2){
    int d=len1-len2;
    int iszero=1;
    if(d<0){
        printf("0    ");
        for(int i=SIGNF-1;i>=0;i--){
            if(n1[i]!=0)iszero=0;
            if(iszero==0)printf("%d",n1[i]);
        }
        if(iszero==1)printf("0");
        printf("\n");
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
        free(one);
    }
    iszero=1;
    for(int i=SIGNF-1;i>=0;i--){
        if(quotient[i]!=0)iszero=0;
        if(iszero==0)printf("%d",quotient[i]);
    }
    if(iszero==1)printf("0");
    printf("    ");
    iszero=1;
    for(int i=SIGNF-1;i>=0;i--){
        if(n1[i]!=0)iszero=0;
        if(iszero==0)printf("%d",n1[i]);
    }
    if(iszero==1)printf("0");
    printf("\n");
    free(quotient);
}

int main(){
    char s1[SIZE],s2[SIZE];
    while(scanf("%s",s1)!=EOF){
        s1=calloc(SIZE,sizeof(char));
        s2=calloc(SIZE,sizeof(char));
        scanf("%s",s2);
        int *number1=calloc(SIZE,sizeof(int)),*number2=calloc(SIZE,sizeof(int));
        int length1=transToint(number1,s1);
        int length2=transToint(number2,s2);
        division(number1,number2,length1,length2);
        free(number1);
        free(number2);
    }
}*/
