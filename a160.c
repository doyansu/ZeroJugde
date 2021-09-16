#include <stdio.h>
#define SIZE 144

void print(char *list,int size){
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(list[i*size+j]==' ')printf("x");
            else printf("Q");
        }
        printf("\n");
    }
    printf("\n");
}

int checkStraight(char *list,int size,int enter){
    for(int i=0;i<size;++i){
        if(list[i*size+enter]!=' ')return 0;
    }
    return 1;
}

int checkSlash(char *list,int size,int level,int enter){
    for(int i=enter+1,j=level+1;i<size && j<size;++i,++j){
        if(list[j*size+i]!=' ')return 0;
    }
    for(int i=enter-1,j=level+1;i>=0 && j<size;--i,++j){
        if(list[j*size+i]!=' ')return 0;
    }
    for(int i=enter+1,j=level-1;i<size && j>=0;++i,--j){
        if(list[j*size+i]!=' ')return 0;
    }
    for(int i=enter-1,j=level-1;i>=0 && j>=0;--i,--j){
        if(list[j*size+i]!=' ')return 0;
    }
    return 1;
}

void dfs(int m,int size,char *list,int *ans,int level){
    //print(list,size);
    if(!m){
        for(int i=0;i<size;++i){
            for(int j=0;j<size;++j){
                if(list[i*size+j]=='*'){
                    if(!checkSlash(list,size,i,j)){
                        //printf("ERROR i=%d j=%d\n",i,j);
                        return;
                    }
                }
            }
        }
        print(list,size);
        ++(*ans);
        //printf("++ans %d\n",*ans);
    }
    else{
        for(int i=0;i<size;++i){
            if(checkStraight(list,size,i) && checkSlash(list,size,level,i)){
                //printf("level=%d enter %d m\n",level,i);
                list[level*size+i]='*';
                dfs(m-1,size,list,ans,level+1);
                list[level*size+i]=' ';
            }
        }
    }
}

int main(){
    int m;
    scanf("%d",&m);
    while(m){
        char list[SIZE];
        for(int i=0;i<SIZE;++i)list[i]=' ';
        int ans=0;
        dfs(m,m,list,&ans,0);
        //if(!ans)printf("\n");
        printf("%d\n\n",ans);
        scanf("%d",&m);
    }

}
