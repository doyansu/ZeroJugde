
int main(){
    unsigned long n;
    int data;
    scanf("%d",&data);
    while(data--){
        scanf("%lld",&n);
        if(n==0){
            printf("0");
            return 0;
        }
        unsigned long result=1;
        while(n){
            result*=n%10;
            n/=10;
        }
        printf("%lld\n",result);
    }
}
