#include<stdio.h>//AC 2ms
#include<math.h>
int solve(int n){
    if(n==1)return 1;
    return 1+solve(n/2);
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",solve(n));
        //printf("%d\n",(int)log2(n)+1);
    }
}

/*#include<stdio.h>//AC 2ms
#include<math.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",(int)log2(n)+1);
    }
}*/
