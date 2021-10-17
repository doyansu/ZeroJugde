#include <stdio.h>
#define SIZE 5

int main(){
    int n;
    scanf("%d ",&n);
    int x=0,y=0;
    while(n--){
        int oper,d;
        scanf("%d%d",&oper,&d);
        switch(oper){
        case 0:
            y+=d;
            break;
        case 1:
            x+=d;
            break;
        case 2:
            y-=d;
            break;
        case 3:
            x-=d;
            break;
        }
    }
    printf("%d %d\n",x,y);
}
