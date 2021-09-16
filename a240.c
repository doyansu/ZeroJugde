#include <stdio.h>
#define MOD(a,b) a%b
#define DIV(a,b) a/b
#define MUL10(a) a+a+(a<<3)
int main(){
    int x;
    scanf("%d",&x);
    while(x--){
        int n;
        scanf("%d",&n);
        int a=1,result=0;
        while(n--){
            a=MOD(a,17);
            a=MUL10(a);
            result+=DIV(a,17);
        }
        printf("%d %d\n",DIV(a,17),result);
    }
}
