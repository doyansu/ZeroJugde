#include <stdio.h>//AC 0.3S
#define MAXINF 0x7fffffff
#define SIZE 11

int list[SIZE]={0};
char output[SIZE*SIZE];
int outindex=0;
int n;

void swap(int *n1,int *n2){
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}

void derectorder(){
    for(int i=n-1;i>0;i--){
        if(list[i]>list[i-1]){
            int min=MAXINF;
            int index;
            for(int x=n-1;x>i-1;x--){
                if(list[x]>list[i-1] && list[x]<min){
                    index=x;
                    min=list[x];
                }
            }
            swap(&list[i-1],&list[index]);
            for(int x=i,y=n-1;x<y;++x,--y){
                swap(&list[x],&list[y]);
            }
            for(int x=0;x<n;++x){
                if(list[x]==10){
                    output[outindex++]='1';
                    output[outindex++]='0';
                    output[outindex++]=' ';
                }
                else{
                    output[outindex++]='0'+list[x];
                    output[outindex++]=' ';
                }
            }
            //output[outindex++]='\n';
            //if(outindex>n){
                puts(output);
                outindex=0;
            //}
            i=n;
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i){
            list[i]=i+1;
            printf("%d ",i+1);
        }
        printf("\n");
        derectorder();
        if(outindex)puts(output);
    }
}

/*#include <stdio.h>//AC 5.5S
#define MAXINF 0x7fffffff
#define SIZE 11

int list[SIZE]={0};
int n;

void swap(int *n1,int *n2){
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}

void derectorder(){
    for(int i=n-1;i>0;i--){
        if(list[i]>list[i-1]){
            int min=MAXINF;
            int index;
            for(int x=n-1;x>i-1;x--){
                if(list[x]>list[i-1] && list[x]<min){
                    index=x;
                    min=list[x];
                }
            }
            swap(&list[i-1],&list[index]);
            for(int x=i,y=n-1;x<y;++x,--y){
                swap(&list[x],&list[y]);
            }
            for(int x=0;x<n;++x)printf("%d ",list[x]);
            printf("\n");
            i=n;
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i){
            list[i]=i+1;
            printf("%d ",i+1);
        }
        printf("\n");
        derectorder();
    }
}*/



/*#include <stdio.h>//AC 5.7S
#define SIZE 10

int path[SIZE];
int n;

void dfs(int visited,int level,int enter){
    path[level++]=enter+1;
    if(level==n){
        for(int i=0;i<level;++i)printf("%d ",path[i]);
        printf("\n");
    }
    else{
        for(int i=0;i<n;++i){
            if(!((visited>>i)&1))
                dfs(visited|(1<<i),level,i);
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)dfs(1<<i,0,i);
    }
}*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

int path[SIZE]={0};
int n;

void DFS(int visited,int level){
    if(level==n){
        for(int i=0;i<level;++i)printf("%d ",path[i]);
        printf("\n");
    }
    for(int i=0;i<n;++i){
        if((visited>>i)&1){
            visited^=(1<<i);
            path[level]=i+1;
            DFS(visited,level+1);
        }
    }
}

int main(){
    scanf("%d",&n);
    DFS((1<<n)-1,0);
    /*for(int i=0;i<n;++i){
        path[0]=i+1;
        DFS(((1<<n)-1)^(1<<i),1);
    }
}*/
