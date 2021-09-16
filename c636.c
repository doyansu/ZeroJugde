#include <stdio.h>

int main(){
    int n;
    while(scanf("%d",&n)==1){
        if(n<0)++n;
        switch((n+108)%12){
        case 0:
            puts("½Þ");
            break;
        case 1:
            puts("¹«");
            break;
        case 2:
            puts("¤û");
            break;
        case 3:
            puts("ªê");
            break;
        case 4:
            puts("¨ß");
            break;
        case 5:
            puts("Às");
            break;
        case 6:
            puts("³D");
            break;
        case 7:
            puts("°¨");
            break;
        case 8:
            puts("¦Ï");
            break;
        case 9:
            puts("µU");
            break;
        case 10:
            puts("Âû");
            break;
        case 11:
            puts("ª¯");
            break;
        }
    }
}
