#include <stdio.h>
#define SIZE 101

int gcd(int m,int n){
    if(m%n==0)return n;
    return gcd(n,m%n);
}

int extendedEuclid(int a, int n) {
    int si[SIZE]={1,0},ti[SIZE]={0,1};
    int qi[SIZE]={0},ri[SIZE]={a,n};
    int i=0;
    do{
        ++i;
        qi[i]=a/n;
        int temp=a;
        a=n;
        n=temp%a;
        ri[i+1]=ri[i-1]-qi[i]*ri[i];
        si[i+1]=si[i-1]-qi[i]*si[i];
        ti[i+1]=ti[i-1]-qi[i]*ti[i];
    }while(ri[i]!=1);
    return si[i];
}

int main(){
    int a,n,b;
    while(scanf("%d%d",&a,&n)!=EOF){
        if(n!=1 && gcd(a,n)==1)printf("%d\n",(extendedEuclid(a,n)+n)%n);
        else printf("No Inverse\n");
    }
}
