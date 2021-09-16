int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a==1)printf("%d\n",b+c);
        else if(a==2)printf("%lld\n",b-c);
        else if(a==3)printf("%lld\n",b*c);
        else if(a==4)printf("%lld\n",b/c);
    }
}
