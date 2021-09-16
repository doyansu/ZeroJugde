#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main(){
    int d;
    scanf("%d",&d);
    while(d--){
        int x,y,z,w,n,m;
        scanf("%d%d%d%d%d%d",&x,&y,&z,&w,&n,&m);
        getchar();
        char s[SIZE];
        int debuff=0;
        gets(s);
        for(int i=0;i<strlen(s);++i){
            if(s[i]!=' ')m+=debuff;
            if(m<=0){
                m=0;
                printf("bye~Rabbit\n");
                break;
            }
            switch(s[i]){
            case '1':
                m+=x;
                break;
            case '2':
                m+=y;
                break;
            case '3':
                m-=z;
                break;
            case '4':
                m-=w;
                debuff-=n;
                break;
            default:
                break;
            }
        }
        if(m)printf("%dg\n",m);
    }
}
