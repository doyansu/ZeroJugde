#include <stdio.h>

int main(){
    int n;
    while(scanf("%d",&n)==1){
        switch((n-1800)%10){
        case 4:
            printf("¥Ò");
            break;
        case 5:
            printf("¤A");
            break;
        case 6:
            printf("¤þ");
            break;
        case 7:
            printf("¤B");
            break;
        case 8:
            printf("¥³");
            break;
        case 9:
            printf("¤v");
            break;
        case 0:
            printf("©°");
            break;
        case 1:
            printf("¨¯");
            break;
        case 2:
            printf("¤Ð");
            break;
        case 3:
            printf("¬Ñ");
            break;
        }
        switch((n-1800)%12){
        case 4:
            printf("¤l");
            break;
        case 5:
            printf("¤¡");
            break;
        case 6:
            printf("±G");
            break;
        case 7:
            printf("¥f");
            break;
        case 8:
            printf("¨°");
            break;
        case 9:
            printf("¤x");
            break;
        case 10:
            printf("¤È");
            break;
        case 11:
            printf("¥¼");
            break;
        case 0:
            printf("¥Ó");
            break;
        case 1:
            printf("¨»");
            break;
        case 2:
            printf("¦¦");
            break;
        case 3:
            printf("¥è");
            break;
        }
        putchar('\n');
    }
}
