#include <stdio.h>

int main(){
    int n;
    while(scanf("%d",&n)==1){
        switch((n-1800)%10){
        case 4:
            printf("��");
            break;
        case 5:
            printf("�A");
            break;
        case 6:
            printf("��");
            break;
        case 7:
            printf("�B");
            break;
        case 8:
            printf("��");
            break;
        case 9:
            printf("�v");
            break;
        case 0:
            printf("��");
            break;
        case 1:
            printf("��");
            break;
        case 2:
            printf("��");
            break;
        case 3:
            printf("��");
            break;
        }
        switch((n-1800)%12){
        case 4:
            printf("�l");
            break;
        case 5:
            printf("��");
            break;
        case 6:
            printf("�G");
            break;
        case 7:
            printf("�f");
            break;
        case 8:
            printf("��");
            break;
        case 9:
            printf("�x");
            break;
        case 10:
            printf("��");
            break;
        case 11:
            printf("��");
            break;
        case 0:
            printf("��");
            break;
        case 1:
            printf("��");
            break;
        case 2:
            printf("��");
            break;
        case 3:
            printf("��");
            break;
        }
        putchar('\n');
    }
}
