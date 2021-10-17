#include <stdio.h>//NA #3 43%
#define SIZE 21


long long int get_llint(){
  long long int n=0,si=1; char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-') tc=getchar();
  if(tc=='-') tc=getchar(),si=-1;
  while(tc>='0'&&tc<='9') n=n*10+(tc-'0'),tc=getchar();
  return n*si;
}

void putllint(long long int out)
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
    int t;
    scanf("%d",&t);
    ++t;
    for(int cas=1;cas<t;++cas){
        long long int n,s1,v1,s2,v2,temp;
        n=get_llint();
        s1=get_llint();
        v1=get_llint();
        s2=get_llint();
        v2=get_llint();
        putchar('C');
        putchar('a');
        putchar('s');
        putchar('e');
        putchar(' ');
        putchar('#');
        printf("%d",cas);
        putchar(':');
        putchar(' ');
        if((double)v1/s1<(double)v2/s2){
            temp=s1;
            s1=s2;
            s2=temp;
            temp=v1;
            v1=v2;
            v2=temp;
        }
        long long int x=n/s1,y=0,counts1=v1*x,max=0;
        if(n-s1*x==0){
            putllint(counts1);
            continue;
        }
        while(x>=0){
            y=(n-s1*x)/s2;
            temp=counts1+y*v2;
            //printf("%lld %lld %lld\n",temp,x,(n-s1*x)/s2);
            if(temp>max)max=temp;
            //if(n-x*s1-y*s2<s2-1)break;
            counts1-=v1;
            --x;
        }
        putllint(max);
        //printf("%g %g\n",(double)v1/s1,(double)v2/s2);
    }
}


