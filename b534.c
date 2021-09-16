#include <stdio.h>
#define SIZE 1230
#define MOST 10000
#define GCD(a,b) gcd(a,b)
#define MOD(a,b) a%b

int gcd(int a,int b){
    if(MOD(a,b)==0)return b;
    return gcd(b,MOD(a,b));
}

int isprime(int *list,int index,int n){
    for(int i=0;i<index;i++){
        if(list[i]*list[i]>n)return 1;
        if(n%list[i]==0)return 0;
    }
    return 1;
}

int Factorization(int n){
    int index=1,power=0,list[SIZE]={2};
    for(int i=3;i<MOST;i+=2){
        if(i*i>n)break;
        for(int j=0;j<index;j++){
            if(list[j]*list[j]>i){
                list[index++]=i;
                break;
            }
            else if(i%list[j]==0)break;
        }
    }
    while(!isprime(list,index,n)){
        for(int i=0;i<index;i++){
            power=0;
            while(n%list[i]==0){
                power++;
                n/=list[i];
            }
            if(power>1){
                printf("%d^%d",list[i],power);
                if(n!=1)printf("*");
                break;
            }
            else if(power==1){
                printf("%d",list[i]);
                if(n!=1)printf("*");
                break;
            }
        }
    }
    if(n!=1)printf("%d",n);
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,len=1;
        int prime[SIZE]={2};
        for(int i=3;i<MOST;i+=2)if(isprime(prime,len,i))prime[len++]=i;
        scanf("%d%d",&a,&b);
        Factorization(a);
        printf(" , %d",GCD(a,b));
        if(isprime(prime,len,GCD(a,b))&&GCD(a,b)!=1)printf(" , Y\n");
        else printf(" , N\n");
    }
}
