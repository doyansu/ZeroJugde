#include <stdio.h>//	AC (0.3s, 100KB)
#include <stdlib.h>
#define SIZE 31

int m, n, next, path[SIZE], data[SIZE];
char ansjugde;


int cmp(const int *a, const int *b){
    return *a - *b;
}

static inline void DFS(int start, int level, int ans){
    for(int i = start; i < n; i++){
        next = ans + data[i];
        if(next > m)
            return;
        if(next == m){
            for(int j = 0; j < level; j++)
                printf("%d ", path[j]);
            printf("%d\n", data[i]);
            ansjugde = 0;
        }
        path[level] = data[i];
        if(next + data[i] <= m)
            DFS(i + 1, level + 1, next);
    }
}

int main(){
    while(scanf("%d%d",&n ,&m) == 2){
        ansjugde = 1;
        for(int i = 0; i < n; i++)
            scanf("%d", data + i);
        qsort(data, n, sizeof(int), cmp);
        DFS(0, 0, 0);
        if(ansjugde)
            puts("-1");
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

int m, n, next, path[SIZE], data[SIZE];
char ansjugde;


int cmp(const int *a, const int *b){
    return *a - *b;
}

static inline void DFS(int start, int level, int ans){
    for(int i = start; i < n; i++){
        next = ans + data[i];
        if(next >= m){
            if(next == m){
                for(int i = 0; i < level; i++)
                    printf("%d ", path[i]);
                printf("%d\n", data[i]);
                ansjugde = 0;
            }
            else
                return;
        }
        path[level] = data[i];
        if(next + data[i] <= m)
            DFS(i + 1, level + 1, next);
    }
}

int main(){
    while(scanf("%d%d",&n ,&m) == 2){
        ansjugde = 1;
        for(int i = 0; i < n; i++)
            scanf("%d", data + i);
        qsort(data, n, sizeof(int), cmp);
        DFS(0, 0, 0);
        if(ansjugde)
            puts("-1");
    }
    return 0;
}
*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

int m, n, path[SIZE], data[SIZE];
char ansjugde;


int cmp(const int *a,const int *b){
    return *a - *b;
}

static inline void DFS(int start, int level, int ans){
    if(ans == m){
        ansjugde = 0;
        for(int i = 0; i < level; i++)
            printf("%d ", path[i]);
        putchar('\n');
        return;
    }
    for(int i = start; i < n; i++){
        path[level] = data[i];
        if(ans + data[i] <= m)
            DFS(i + 1, level + 1, ans + data[i]);
        else
            return;
    }
}

int main(){
    while(scanf("%d%d",&n ,&m) == 2){
        ansjugde = 1;
        for(int i = 0; i < n; i++)
            scanf("%d", data + i);
        qsort(data, n, sizeof(int), cmp);
        DFS(0, 0, 0);
        if(ansjugde)
            puts("-1");
    }
    return 0;
}
*/
/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

int m, n, path[SIZE], data[SIZE];
char ansjugde = 1;


static inline int cmp(const int *a,const int *b){
    return *a - *b;
}

static inline void DFS(int start, int level, int ans){
    if(ans > m)
        return;
    if(ans == m){
        for(int i = 0; i < level; i++)
            printf("%d ", path[i]);
        putchar('\n');
        ansjugde = 0;
        return;
    }
    for(int i = start; i < n; i++){
        path[level] = data[i];
        DFS(i + 1, level + 1, ans + data[i]);
    }
}

int main(){
    scanf("%d%d",&n ,&m);
    for(int i = 0; i < n; i++)
        scanf("%d", data + i);
    qsort(data, n, sizeof(int), cmp);
    DFS(0, 0, 0);
    if(ansjugde)
        puts("-1");
    return 0;
}*/

/*#include <stdio.h>//AC 0.3S
#include <stdlib.h>
#define SIZE 35

int n, m;
int arr[SIZE];
int ans[SIZE][2];
int ansPtr;

void print()
{
    for(int i = 0; i<ansPtr; i++)
        printf("%d ",ans[i][0]);
    printf("\n");
}

void search_seq()
{
    int Bprint = 0;
    int leave;
    int i;

    for(ansPtr = i = 0, leave = m; ansPtr < n ; i++)
    {
        //printf("  i =%2d ansPTR = %d leave =%4d arr[i] =%5d\n",i,ansPtr,leave,arr[i]);
        if(arr[i] <= leave && i<n)
        {
            leave -= arr[i];
            ans[ansPtr][0] = arr[i];
            ans[ansPtr++][1] = i;
            //printf("  i =%2d ansPTR = %d leave =%4d arr[i] =%5d\n",i,ansPtr,leave,arr[i]);
            if(leave == 0)
            {
                print();
                Bprint = 1;
            }

        }
        else
        {
            while( (i==n || leave < arr[i]) && ansPtr > 0)
            {
                leave += ans[--ansPtr][0];
                ans[ansPtr][0] = 0;
                i = ans[ansPtr][1] + 1;
                //printf("w i =%2d ansPTR = %d leave =%4d arr[i] =%5d\n",i,ansPtr,leave,arr[i]);
            }
            if( (leave < arr[i] && ansPtr == 0) || i==0 || i == n)break;
            i--;
        }
    }
    if(Bprint == 0)printf("-1\n");
}

int comp(const void*a,const void*b){return *(int*)a-*(int*)b;}

int main()
{
    scanf("%d%d",&n,&m);
    //while(!=EOF)
    for(int i = 0; i<n; i++)scanf("%d",&arr[i]);
    qsort(arr,n,sizeof(int),comp);
    search_seq();

}*/


/*#include <stdio.h> //AC 1.9S
#include <stdlib.h>
#define SIZE 31

int path[SIZE]={0};
int data[SIZE]={0};
int m,n,jugde=1;

void DFS(int visited,int level,int ans){
    if(ans>m){return;}
    if(ans==m){
        jugde=0;
        for(int i=0;i<level;++i)printf("%d ",path[i]);
        printf("\n");
    }
    for(int i=0;i<n;++i){
        if((visited>>i)&1){
            visited^=(1<<i);
            path[level]=data[i];
            DFS(visited,level+1,ans+data[i]);
        }
    }
}

int comp(const void*a,const void*b)//qsort
{
    return *(int*)a-*(int*)b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&data[i]);
    qsort(data,n,sizeof(int),comp);
    DFS((1<<n)-1,0,0);
    if(jugde)printf("-1");
}
*/


/*#include <stdio.h> //AC 1.9S
#include <stdlib.h>
#include <math.h>
#define SIZE 31

char output[SIZE*SIZE];
int outindex=0;
int path[SIZE]={0};
int data[SIZE]={0};
int m,n,jugde=1;

void DFS(int visited,int level,int ans){
    if(ans>m){return;}
    if(ans==m){
        jugde=0;
        for(int i=0;i<level;++i){
            if(path[i]<10)output[outindex++]='0'+path[i];
            else{
                int temp=path[i];
                int len=0;
                while(temp){
                    ++len;
                    temp/=10;
                }
                temp=path[i];
                while(len--){
                    output[outindex++]='0'+(temp/pow(10,len));
                    temp%=(int)pow(10,len);
                }
            }
            output[outindex++]=' ';
        }
        output[outindex++]='\0';
        puts(output);
        outindex=0;
    }
    for(int i=0;i<n;++i){
        if((visited>>i)&1){
            visited^=(1<<i);
            path[level]=data[i];
            DFS(visited,level+1,ans+data[i]);
        }
    }
}

int comp(const void*a,const void*b)//qsort
{
    return *(int*)a-*(int*)b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&data[i]);
    qsort(data,n,sizeof(int),comp);
    DFS((1<<n)-1,0,0);
    //if(outindex)puts(output);
    if(jugde)printf("-1");
}
*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

int path[SIZE]={0};
int data[SIZE]={0};
int m,n,jugde=1;

void DFS(int visited,int level,int ans){
    //printf("level = %d visited = %d ans = %d\n",level,visited,ans);
    if(ans==m){
        jugde=0;
        //printf("visited = %d\n",visited);
        for(int i=0;i<level;++i)printf("%d ",path[i]);
        printf("\n");
    }
    else if(ans>m){return;}
    for(int i=0;i<n;++i){
        if((visited>>i)&1){
            visited^=(1<<i);
            path[level]=data[i];
            DFS(visited,level+1,ans+data[i]);
        }
    }


}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&data[i]);
        for(int j=i;i>0;--j){
            if(data[j-1]>data[j]){
                int temp=data[j];
                data[j]=data[j-1];
                data[j-1]=temp;
            }
            else break;
        }
    }
    DFS((1<<n)-1,0,0);
    if(jugde)printf("-1");
}*/


/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

int path[SIZE]={0};
int data[SIZE]={0};
int m,jugde=1;

void DFS(int visited,int level,int ans){
    //printf("level = %d visited = %d ans = %d\n",level,visited,ans);
    if(ans==m){
        jugde=0;
        //printf("visited = %d\n",visited);
        for(int i=0;i<level;++i)printf("%d ",path[i]);
        printf("\n");
    }
    else if(ans>m){return;}
    while(visited){
        int enter= visited & (-visited);
        int index=0;
        while(enter){
            ++index;
            enter=enter>>1;
        }
        enter= visited & (-visited);
        //printf("index = %d data = %d\n",index,data[index-1]);
        path[level]=data[index-1];
        DFS(visited^enter,level+1,ans+data[index-1]);
        visited^=enter;
    }

}

int main(){
    int n;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&data[i]);
        for(int j=i;i>0;--j){
            if(data[j-1]>data[j]){
                int temp=data[j];
                data[j]=data[j-1];
                data[j-1]=temp;
            }
            else break;
        }
    }
    //printf("%d\n",(1<<n)-1);
    DFS((1<<n)-1,0,0);
    if(jugde)printf("-1");
    //for(int i=0;i<n;++i)printf("%d ",data[i]);
}*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int cmp(int *list1,int *list2){
    for(int i=0;i<SIZE;++i){
        if(list1[i]>list2[i])return 1;
        else if(list1[i]<list2[i])return 0;
    }
}

int main(){
    int n,m;
    int list[SIZE]={0};
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&list[i]);
        int tem;
        for(int j=i;j>0;--j){
            if(list[j]<list[j-1]){
                tem=list[j];
                list[j]=list[j-1];
                list[j-1]=tem;
            }
            else break;
        }
    }

    int* total[1000];
    int lent=0;
    for(int i=1;i<(1<<n);++i){
        int *templist=calloc(SIZE,sizeof(int));
        int temp=i;
        int ans=0;
        int index=0;
        int len=0;
        while(temp && index<n){
            if(temp%2){
                templist[len++]=list[index];
                ans+=list[index];
            }
            if(ans>m)break;
            temp/=2;
            ++index;
        }
        if(ans==m){
            int *tempp;
            total[lent++]=templist;
            for(int x=lent-1;x>0;--x){
                if(cmp(total[x-1],total[x])){
                    tempp=total[x-1];
                    total[x-1]=total[x];
                    total[x]=tempp;
                }
                else break;
            }
        }
        else free(templist);
    }

    for(int i=0;i<lent;++i){
        for(int x=0;x<SIZE;++x){
            if(!total[i][x])break;
            printf("%d ",total[i][x]);
        }
        printf("\n");
    }
    if(!lent)printf("-1");
}*/


/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int cmp(int *list1,int *list2){
    for(int i=0;i<SIZE;++i){
        if(list1[i]>list2[i])return 1;
        else if(list1[i]<list2[i])return 0;
    }
}

int main(){
    int n,m;
    int list[SIZE]={0};
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&list[i]);
        int tem;
        for(int j=i;j>0;--j){
            if(list[j]<list[j-1]){
                tem=list[j];
                list[j]=list[j-1];
                list[j-1]=tem;
            }
            else break;
        }
    }

    int* total[1000];
    int lent=0;
    for(int i=1;i<(1<<n);++i){
        int *templist=calloc(SIZE,sizeof(int));
        int temp=i;
        int ans=0;
        int index=0;
        int len=0;
        while(temp && index<n){
            if(temp%2){
                templist[len++]=list[index];
                ans+=list[index];
            }
            if(ans>m)break;
            temp/=2;
            ++index;
        }
        if(ans==m){
            /*for(int x=0;x<len;++x){
                printf("%d ",templist[x]);
            }
            printf("\n");
            int *tempp;
            total[lent++]=templist;
            for(int x=lent-1;x>0;--x){
                if(cmp(total[x-1],total[x])){
                    tempp=total[x-1];
                    total[x-1]=total[x];
                    total[x]=tempp;
                }
                else break;
            }
        }
        else free(templist);
    }

    for(int i=0;i<lent;++i){
        //printf("%d- ",i);
        for(int x=0;x<SIZE;++x){
            if(!total[i][x])break;
            printf("%d ",total[i][x]);
        }
        printf("\n");
    }
    if(!lent)printf("-1");
}*/









/*int check(int *visits,int visited,int *index){
    for(int i=*index-1;i>=0;--i)if(visits[i]==visited)return 1;
    return 0;
}

void dfs(int *list,int *path,int *visits,int m,int n,int *index,int first,int visited,int enter,int ans,int level){
    if(ans>m || check(visits,visited,index))return;
    path[level++]=list[enter];
    ans+=list[enter];
    if(ans==m){
        for(int i=0;i<level;++i)printf("%d ",path[i]);
        visits[(*index)++]=visited;
        printf("\n");
    }
    else{
        for(int i=first+1;i<n;++i){
            if(!((visited>>i)&1)){
                dfs(list,path,visits,m,n,index,first,visited|(1<<i),i,ans,level);
            }
        }
    }

}

int main(){
    int n,m;
    int list[30];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&list[i]);
        int temp;
        for(int j=i;j>0;--j){
            if(list[j]<list[j-1]){
                temp=list[j];
                list[j]=list[j-1];
                list[j-1]=temp;
            }
            else break;
        }
    }
    int path[SIZE];
    int index=0;
    int visits[100000]={0};
    for(int i=0;i<n;++i)dfs(list,path,visits,m,n,&index,i,1<<i,i,0,0);
    if(!index)printf("-1");
    //for(int i=0;i<n;++i)printf("%d\n",list[i]);
}*/
