#include<stdio.h>//a004
#include <math.h>
#define MOD4(N) N%4
#define MOD100(N) N%100
#define MOD400(N) N%400

int isLeapYear(int year){
    if(MOD4(year)==0 && MOD100(year)!=0 || MOD400(year)==0)return 1;
    return 0;
}

int getLeapYear(int end){
    /*int amount=0;//11ms
    for(int year=4;year<end;year+=4){
        if(isLeapYear(year))++amount;
    }
    return amount;*/
    return (end-1)/4-(end-1)/100+(end-1)/400;//5ms
}

void getDay(int *amount,int year,int month,int date){
    for(int i=1;i<month;++i){
        if(i==2){
            if(isLeapYear(year))++(*amount);
            *amount+=28;
        }
        else if(i==4 | i==6 | i==9 | i==11)*amount+=30;
        else *amount+=31;
    }
    *amount+=365*(year-1)+getLeapYear(year)+date;
}

int main(){
    int year,month,date;
    while(scanf("%d%d%d",&year,&month,&date)!=EOF){
        int amount1=0,amount2=0;
        getDay(&amount1,year,month,date);
        scanf("%d%d%d",&year,&month,&date);
        getDay(&amount2,year,month,date);
        printf("%d\n",abs(amount1-amount2));
    }
}
