#include <stdio.h>
#define SIZE 5

int main(){
    char answer[SIZE];
    int n;
    gets(answer);
    scanf("%d ",&n);
    while(n--){
        char gus[SIZE];
        int a=0,b=0;
        gets(gus);
        for(int i=0;i<4;++i){
            if(answer[i]==gus[i])++a;
            for(int j=0;j<4;++j){
                if(answer[i]==gus[j] && i!=j)++b;
            }
        }
        printf("%dA%dB\n",a,b);
    }
}
