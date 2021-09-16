#include <stdio.h>

int get_int(){
  int n=0,si=1;
  char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-')tc=getchar();
  if(tc=='-'){
    tc=getchar();
    si=-1;
  }
  while(tc>='0'&&tc<='9'){
    n=(n<<1)+(n<<3)+(tc^'0');
    tc=getchar();
  }
  return n*si;
}

int main(){
    int n,data,ans=0;
    scanf("%d",&n);
    while(--n){
        data=get_int();
        ans^=data;
    }
    printf("%d",ans);
    return 0;
}
