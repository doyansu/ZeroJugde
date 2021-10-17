#include <stdio.h>
#define SIZE 10000
#define MOD(a,b) a%b
#define DIV(a,b) a/b
#define MUL10(a) a+a+(a<<3)
int main(){
    int a,b,n;
    char s[SIZE];
    while(scanf("%d%d%d",&a,&b,&n)!=EOF){
        printf("%d.",DIV(a,b));
        a=MOD(a,b);
        int index=0;
        while(n--){
            a=MUL10(a);
            s[index++]='0'+DIV(a,b);
            a=MOD(a,b);
        }
        s[index]='\0';
        printf("%s\n",s);
    }
}
