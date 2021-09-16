#include <stdio.h>
#define SIZE 27

int dfs(int *n,char *path,int left,int right,int enter,int level){
    if(enter){
        path[level++]=')';
        ++right;
    }
    else{
        path[level++]='(';
        ++left;
    }
    if(level==2*(*n)){
        if(left==*n && right==*n)printf("%s\n",path);
    }
    else{
        if(left<=*n)dfs(n,path,left,right,0,level);
        if(left>right && right<=*n)dfs(n,path,left,right,1,level);
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        char path[SIZE];
        path[2*n]='\0';
        dfs(&n,path,0,0,0,0);
    }
}


/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 30

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        int start=pow(2,n)-1,end=pow(2,n+n);
        for(int x=start;x<end;x++){
            int left=0,right=0,temp1=x;
            while(left>=right){
                if(temp1%2)left++;
                else right++;
                if(left==n && right==n){
                    int temp2=x;
                    char *s=calloc(SIZE,sizeof(char));
                    for(int i=n+n-1;i>=0;i--){
                        if(temp2%2)s[i]=')';
                        else s[i]='(';
                        temp2/=2;
                    }
                    printf("%s\n",s);
                    break;
                }
                temp1/=2;
            }
        }
    }
}*/



/*int branch(int n,int left,int right){
    if(n==0)return 0;
    else if(left==right && !(left==0 && right==0)){
        printf("(");
        branch(--n,left,--right);
    }
    else{
        printf("(");
        branch(--n,--left,right-1);
        printf(")");
        branch(n,left,--right);
        printf("\n");
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        branch(n+n,n,n);
    }
}*/
