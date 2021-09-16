#define F1(x) (x%10)*9+(x/10)
int turn(char c){
    char list[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int listi[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    for(int i=0;i<26;i++)if(c==list[i])return listi[i];
}

int main(){
    char c;
    int n,result;
    scanf("%c%d",&c,&n);
    result=F1(turn(c))+n%10;
    for(int i=1;i<9;i++){
        n/=10;
        result+=(n%10)*i;
    }
    if(result%10)printf("fake");
    else printf("real");
}
