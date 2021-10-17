#include <stdio.h>
#define SIZE 5005

int main()//AC 11ms
{
    char s[SIZE];
    int n,np;
    scanf("%d", &n);
    getchar();
    np=n+1;
    for (int i = 0; i < n; ++i)
    {
        fgets(s, np, stdin);
        putchar(s[i]);
    }
}


/*int get_int(){
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
  putchar('\n');
}*/

/*int main(){//AC 0.3S
    int n;
    char ch;
    n=get_int();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            ch=getchar();
            if(i==j)putchar(ch);
        }
    }
}*/
