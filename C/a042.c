#define FUNCTION(n) n*n-n+2
int main(){
    int n;
    while(scanf("%d",&n)!=-1)printf("%d\n",FUNCTION(n));
}

//´ú¸Õwhile(scanf("%s",s)!=-1)
/*#define FUNCTION(n) n*n-n+2
#include <string.h>
#include <math.h>
int sss(char *s){
    int n=0;
    for(int i=0;i<strlen(s);i++)n+=(s[i]-'0')*pow(10,strlen(s)-i-1);
    return n;
}
int main(){
    int n;
    char s[1000];
    while(scanf("%s",s)!=-1)printf("%d\n",FUNCTION(sss(s)));
}*/
