#include<stdio.h>//a004
#define MOD4(N) N%4
#define MOD100(N) N%100
#define MOD400(N) N%400
int main(){
    int year;
    scanf("%d",&year);
    if(MOD4(year)==0 && MOD100(year)!=0 ||MOD400(year)==0)printf("a leap year");
    else printf("a normal year");
}
