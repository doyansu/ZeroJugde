#include <stdio.h>
#define SIZE 21


int get_int(){
  int n=0,si=1; char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-') tc=getchar();
  if(tc=='-') tc=getchar(),si=-1;
  while(tc>='0'&&tc<='9') n=n*10+(tc-'0'),tc=getchar();
  return n*si;
}

void putint(int out)
{
  char buf[SIZE];
  int n=0;
  if(out<0) putchar('-'),out=out*-1;
  do
  {
    buf[n++]='0'+(out%10);
    out=out/10;
  }while(out>0);
  for(n=n-1;n>=0;n--)
    putchar(buf[n]);
  putchar('\n');  //視情況加入
}

int main(){
    int n,k,w;
    n=get_int();
    k=get_int();
    w=get_int();
    int x=n;
    while(x/k){
        n+=w;
        x+=w-k;
    }
    putint(n);
}
