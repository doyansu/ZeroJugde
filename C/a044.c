#define FUNCTION(n) (n*n*n+5*n+6)/6
int main(){
    int n;
    while(scanf("%d",&n)!=-1)printf("%d\n",FUNCTION(n));
}
