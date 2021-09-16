#include<stdio.h>
int check(int *visited,int n){
    for(int i=0;i<4;i++)if(visited[i]==n)return 1;
    return 0;
}

int namb(int *a,int *b,int *list1,int *list2){
    int visited[4]={-1,-1,-1,-1};
    for(int i=0;i<4;i++)if(list1[i]==list2[i]){
        (*a)++;
        list2[i]=-2;
        visited[i]=i;
    }
    for(int i=0;i<4;i++){
        if(check(visited,i))continue;
        for(int j=0;j<4;j++)if(list1[i]==list2[j]){
            (*b)++;
            list2[j]=-2;
            break;
        }
    }
}

int main(){
    int password[4];
    while(scanf("%d%d%d%d",&password[0],&password[1],&password[2],&password[3])!=-1){
        int n;
        scanf("%d",&n);
        while(n--){
            int a=0,b=0,guess[4];
            scanf("%d%d%d%d",&guess[0],&guess[1],&guess[2],&guess[3]);
            namb(&a,&b,password,guess);
            printf("%dA%dB\n",a,b);
        }
    }
}
