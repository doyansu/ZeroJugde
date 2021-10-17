#include <stdio.h>//AC 2ms
#define SIZE 101

int path[SIZE]={0};

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

void dfs(int n,int start,int level){
    if(n>0){
        for(int i=start;i>0;--i){
            path[level]=i;
            dfs(n-i,i,level+1);
        }
    }
    else if(n==0){
        for(int i=0;i<level;++i)putint(path[i]);
        putchar('\n');
    }

}

int main(){
    int size;
    while(scanf("%d",&size)!=EOF)dfs(size,size,0);
}
