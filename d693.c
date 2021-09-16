#define GCD(a,b) gcd(a,b)
#define MOD(a,b) a%b
int gcd(int a,int b){
    if(MOD(a,b)==0)return b;
    return gcd(b,MOD(a,b));
}

int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==0)break;
        int a=1,b;
        for(int i=0;i<n;i++){
            scanf("%d",&b);
            a*=b/GCD(a,b);
        }
        printf("%d\n",a);
    }
}


/*int isprime(int *list,int index,int n){
    if(n==1)return 0;
    else if(n==2 || n==3)return 1;
    int m=n%6;
    if(m!=1 && m!=5)return 0;
    for(int i=2;i<index;i++){
        if(list[i]*list[i]>n)return 1;
        if(n%list[i]==0)return 0;
    }
    return 1;
}

int main(){
    int n;
    int prime[100]={2},len=1;
    for(int i=3;i<10;i+=2)if(isprime(prime,len,i))prime[len++]=i;
    while(scanf("%d",&n)){
        if(n==0)break;
        int list[SIZE],result=1;
        for(int i=0;i<n;i++)scanf("%d",&list[i]);
        int conti=1;
        while(conti){
            conti=0;
            for(int i=0;i<len;i++){
                for(int j=0;j<n;j++){
                    if(list[j]%prime[i]==0){
                        list[j]/=prime[i];
                        conti=prime[i];
                    }
                }
                if(conti){
                    result*=conti;
                    break;
                }
            }

        }
        for(int i=0;i<n;i++)result*=list[i];
        printf("%d\n",result);
    }
}*/
