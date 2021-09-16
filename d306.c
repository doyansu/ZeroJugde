#include <string.h>
#include <math.h>
#define GCD(a,b) gcd(a,b)
#define MOD(a,b) a%b
int gcd(int a,int b){
    if(MOD(a,b)==0)return b;
    return gcd(b,MOD(a,b));
}
int main(){
    int n;
    scanf("%d",&n);
    n++;
    for(int i=1;i<n;i++){
        char s1[31],s2[31];
        scanf("%s",s1);
        scanf("%s",s2);
        int i1=0,i2=0;
        for(int x=0;x<strlen(s1);x++){
            i1=i1<<1;
            if(s1[x]=='1')i1++;
        }
        for(int x=0;x<strlen(s2);x++){
            i2=i2<<1;
            if(s2[x]=='1')i2++;
        }
        if(GCD(i1,i2)>1)printf("Pair #%d: All you need is love!\n",i);
        else printf("Pair #%d: Love is not all you need!\n",i);
    }
}
