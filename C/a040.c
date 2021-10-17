#include<stdio.h>

int power(int n,int e){
    int r=1;
    while(e--)r*=n;
    return r;
}

int isArmstrongnumber(int i){
    int n=0,temp=i,len=0;
    while(temp){
        temp/=10;
        len++;
    }
    temp=i;
    while(temp){
        n+=power(temp%10,len);
        temp/=10;
    }
    if(i==n)return 1;
    return 0;
}

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    m++;
    int none=1;
    for(int i=n;i<m;i++){
        if(isArmstrongnumber(i)){
            none=0;
            printf("%d ",i);
        }
    }
    if(none==1)printf("none");
}
