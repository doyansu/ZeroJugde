#include <stdio.h>
int abs(int a){
    if(a<0)a=-a;
    return a;
}

int main(){
    char s[8];
    while(scanf("%s",&s)!=-1){
        for(int i=0;i<6;i++)printf("%d",abs(s[i+1]-s[i]));
        printf("\n");
    }
}
