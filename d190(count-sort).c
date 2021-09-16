#include <stdio.h>
#define SIZE 100

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
  putchar(' ');
}

int get_int(){
  int n=0,si=1;
  char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-')tc=getchar();
  if(tc=='-'){
    tc=getchar();
    si=-1;
  }
  while(tc>='0'&&tc<='9'){
    n=(n<<1)+(n<<3)+(tc-'0');
    tc=getchar();
  }
  return n*si;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n){
        int array[SIZE]={0};
        while(n--){
            int age;
            age=get_int();
            ++array[age];
        }
        for(int i=0;i<SIZE;++i){
            while(array[i]){
                putint(i);
                --array[i];
            }
        }
        putchar('\n');
    }
}
