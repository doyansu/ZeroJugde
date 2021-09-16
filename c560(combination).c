#include <stdio.h>//AC 12ms
#define SIZE 100001

void putllint(long long int out)
{
  char buf[1000];
  int n=0;
  if(out<0){
    putchar('-');
    out*=-1;
  }
  do
  {
    buf[n++]='0'+(out%10);
    out/=10;
  }while(out>0);
  for(--n;n>=0;--n)putchar(buf[n]);
  putchar('\n');
}


int main(){
    int n,m;
    long long int array[SIZE]={1,1,1,2};
    for(int i=4;i<SIZE;++i)array[i]=(array[i-1]+array[i-3])%1000000007;
    while(scanf("%d%d",&n,&m)!=EOF){
        long long int total=1;
        int last=0;
        int restfloor;
        while(m--){
            scanf("%d",&restfloor);
            total=(total*array[restfloor-last])%1000000007;
            last=restfloor;
        }
        total=(total*array[n-restfloor])%1000000007;
        putllint(total);
    }
}
