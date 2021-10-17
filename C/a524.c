#include <stdio.h>
#include <math.h>

void dfs(int n,char *path,int *temp,int visited,int level,int enter){
    path[level++]='0'+enter;
    if(level==n)printf("%s\n",path);
    else{
        for(int i=n;i>0;--i){
            if(!((visited>>temp[i])&1))dfs(n,path,temp,visited|(1<<temp[i]),level,temp[i]);
        }
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int temp[9];
        char path[9];
        path[n]='\0';
        for(int i=0;i<9;++i)temp[i]=i;
        for(int i=n;i>0;--i)dfs(n,path,temp,1<<temp[i],0,temp[i]);
    }
}
