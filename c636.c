#include <stdio.h>

int main(){
    int n;
    while(scanf("%d",&n)==1){
        if(n<0)++n;
        switch((n+108)%12){
        case 0:
            puts("��");
            break;
        case 1:
            puts("��");
            break;
        case 2:
            puts("��");
            break;
        case 3:
            puts("��");
            break;
        case 4:
            puts("��");
            break;
        case 5:
            puts("�s");
            break;
        case 6:
            puts("�D");
            break;
        case 7:
            puts("��");
            break;
        case 8:
            puts("��");
            break;
        case 9:
            puts("�U");
            break;
        case 10:
            puts("��");
            break;
        case 11:
            puts("��");
            break;
        }
    }
}
