#include <stdio.h>
#define SIZE 17

int n;
char path[SIZE];

void dfs(int level){
    if(level==n){
        //printf("%s\n",path);
        puts(path);
        return;
    }
    for(int i=0;i<2;++i){
        path[level]='0'+i;
        dfs(level+1);
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        path[n]='\0';
        dfs(0);
    }
}
