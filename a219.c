#include <stdio.h>//AC 0.5S
#include <string.h>
#include <stdlib.h>
#define MAXINF 0x7fffffff
#define SIZE 27

int list[SIZE]={0};
//char lastoutput[SIZE*SIZE]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lastoutput[SIZE];
char output[SIZE];
int n;

void swap(int *n1,int *n2){
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}

void derectorder(int check[SIZE]){
    int print=1;
    for(int x=0;x<n;++x){
        if((check[x]>>list[x])&1){
            memset(lastoutput,0,sizeof(lastoutput));
            print=0;
            break;
        }
    }
    if(print==1)puts(lastoutput);

    for(int i=n-1;i>0;i--){
        if(list[i]>list[i-1]){
            int min=MAXINF;
            int index;
            print=1;
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
            i=n;

            for(int x=0;x<n;++x){
                if((check[x]>>list[x])&1){
                    print=0;
                    break;
                }
            }
            if(print==0)continue;

            for(int x=0;x<n;++x){output[x]='A'+list[x];}
            for(int x=0;x<n;++x){if(output[x]!=lastoutput[x])putchar(output[x]);}
            putchar('\n');
            strcpy(lastoutput,output);
            //puts(output);
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        int check[SIZE]={0};
        for(int i=0;i<n;++i){
            list[i]=i;
            lastoutput[i]='A'+i;
            int temp;
            while(scanf("%d",&temp)){
               if(temp==0)break;
               check[temp-1]|=(1<<i);
            }
        }
        derectorder(check);
    }
}

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 27

char path[SIZE];
char lastpath[SIZE];
int n;

void dfs(int *list,int visited,int level){
    if(level==n){
        //printf("%s\n",path);
        for(int i=0;i<level;++i){
            if(path[i]!=lastpath[i])printf("%c",path[i]);
            lastpath[i]=path[i];

        }
        printf("\n");
        return;
    }
    for(int i=0;i<n;++i){
        if(!((visited>>i)&1) && !((list[level]>>i)&1)){
            //printf("%c",'A'+i);
            path[level]='A'+i;
            dfs(list,visited|(1<<i),level+1);

        }
    }

}

int main(){
    while(scanf("%d",&n)!=EOF){
        path[n]='\0';
        int *list=calloc(SIZE,sizeof(int));
        for(int i=0;i<n;++i){
            int temp;
            while(scanf("%d",&temp)){
               if(temp==0)break;
               list[temp-1]|=(1<<i);
               //printf("list%d\n",list[i]);
            }
        }
        dfs(list,0,0);
        free(list);
    }
}*/
