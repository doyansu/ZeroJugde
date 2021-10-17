#define SIZE 101//AC 86ms 0.3S

void putint(int out)
{
  char buf[1000];
  int n=0;
  if(out<0) putchar('-'),out=out*-1;
  do
  {
    buf[n++]='0'+(out%10);
    out=out/10;
  }while(out>0);
  for(n=n-1;n>=0;n--)putchar(buf[n]);
  putchar(' ');
}

int get_int(){
  int n=0,si=1; char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-') tc=getchar();
  if(tc=='-') tc=getchar(),si=-1;
  while(tc>='0'&&tc<='9') n=n*10+(tc-'0'),tc=getchar();
  return n*si;
}

int main()
{
    int n,data;
    int list[SIZE]={0};
    n=get_int();
    for(int i=0;i<n;++i){
        data=get_int();
        ++list[data];
    }
    for(int i=1;i<101;++i){
        for(int x=0;x<list[i];++x){
            putint(i);
        }
    }
}
