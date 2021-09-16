#include<stdio.h>//AC 1.4S
#include<stdlib.h>
#define SIZE 10001

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int array[SIZE]={0};
        int a,b;
        int odd=0;
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            ++array[a];
            ++array[b];
        }
        for(int i=1;i<n+1;++i){
            if(array[i]%2==1){
                ++odd;
                if(odd>2)break;
            }
        }
        if(odd!=0 && odd!=2)puts("NO");
        else puts("YES");
    }
}

/*#include<stdio.h>//AC 1.4S
#include<stdlib.h>
#define SIZE 11001

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int array[SIZE]={0};
        int a,b;
        int odd=0;
        //if(n==0)odd=1;
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            ++array[a];
            ++array[b];
        }
        if(array[1]%2 != array[n]%2){
            puts("NO");
            continue;
        }
        for(int i=2;i<n;++i){
            if(array[i]%2==1){
                odd=1;
                break;
            }
        }
        if(odd)puts("NO");
        else puts("YES");
    }
}*/
