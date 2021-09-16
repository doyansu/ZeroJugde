#include<stdio.h>//a004
#define MOD4(N) N%4
#define MOD100(N) N%100
#define MOD400(N) N%400
int main(){
    int year;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&year);
        if(MOD4(year)==0 && MOD100(year)!=0 ||MOD400(year)==0)printf("Case %d: a leap year\n",i+1);
        else printf("Case %d: a normal year\n",i+1);
    }
}
