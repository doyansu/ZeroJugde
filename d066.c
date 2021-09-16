#include <stdio.h>

int main(){
    int hour,min;
    scanf("%d%d",&hour,&min);
    if(hour>6 && hour<17){
        if(hour==7 && min<30)printf("Off School");
        else printf("At School");
    }
    else printf("Off School");
}
