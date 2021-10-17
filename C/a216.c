#define f(n) n*(n+1)/2
#define g(n) (n*(n+1)*(n+2))/6

int main(){
    unsigned long long n;
    while(scanf("%lld",&n)!=-1)printf("%lld %lld\n",f(n),g(n));
}

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 500
#define SIGNF 499
#define f(n) n*(n+1)/2
#define g(n) (n*(n+1)*(n+2))/6

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

int multiplication(int *n1,int *n2,int len1){
    int *result=calloc(SIZE,sizeof(int));
    for(int x=0;x<len1;x++){
        for(int y=0;y<n1[x];y++)add(result,result,n2);
        shift(n2,0);
    }
    for(int x=0;x<len1;x++)shiftdiv(n2,0);
    int len=0;
    for(int i=SIGNF;i>=0;i--){
        n1[i]=result[i];
        if(len==0 && result[i]!=0)len=i+1;
    }
    return len;
}

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
    printf("\n");
}

int main(){
    unsigned n;
    while(scanf("%d",&n)!=-1){
        printf("%d ",f(n));
        int len=0,temp;
        int *n1=calloc(SIZE,sizeof(int));
        int *n2=calloc(SIZE,sizeof(int));
        int *one=calloc(SIZE,sizeof(int));
        *one=1;
        temp=n;
        while(temp){
            n1[len++]=temp%10;
            temp/=10;
        }
        add(n2,n1,one);
        len=multiplication(n1,n2,len);
        add(n2,n2,one);
        len=multiplication(n1,n2,len);
        *one=6;
        division(n1,one,len,1);
    }
}
*/
