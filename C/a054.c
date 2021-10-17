#define F1(x) (x%10)*9+(x/10)
int main(){
    int n,temp,result,c;
    char list[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int listi[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    scanf("%d",&n);
    c=n%10;
    for(int i=0;i<26;i++){
        result=F1(listi[i]);
        temp=n;
        for(int j=1;j<9;j++){
            temp/=10;
            result+=(temp%10)*j;
        }
        if((result%10+c)%10==0)printf("%c",list[i]);
    }
}
