#include <stdio.h>//AC 84ms

void putint(int out)
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
    int n;
    while(scanf("%d",&n)){
        if(n==0)break;
        int total=0;
        while(n&1){
            n>>=1;
            ++total;
        }
        putint(total);
    }
}
