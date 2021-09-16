#define GCD(a,b) gcd(a,b)
#define MOD(a,b) a%b
int gcd(int a,int b){
    if(MOD(a,b)==0)return b;
    return gcd(b,MOD(a,b));
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",GCD(a,b));
}
