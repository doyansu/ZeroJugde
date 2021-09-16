// internet AC 1.8S

#include<stdio.h>

int Ans;

void backtracking(int n, int y, int x, int slash1, int slash2) {
    if(y == n) {++Ans; return ;}
    int judge = x & (slash1 >> y) & (slash2 >> (n-y-1));
    int xput;
    while(judge) {
        xput = judge & (-judge); //lowbit
        backtracking(n, y+1, x^xput, slash1^(xput<<y), slash2^(xput<<(n-y-1)));
        judge ^= xput;
    }
}

int main() {
    int n, i;
    while(scanf("%d",&n) == 1 && n){
        Ans = 0;
        backtracking(n, 0, (1<<n)-1, (1<<(2*n-1))-1, (1<<(2*n-1))-1);
        printf("%d\n", Ans);
    }
    return 0;
}

/*#include<stdio.h>
#define MAX_INPUT_NUMBER 16

int y_row[MAX_INPUT_NUMBER], Ans;

void backtracking(int n, int y, int x, int slash1, int slash2) {
    if(y == n) {++Ans; return ;}

    int nowslash1 = slash1 >> y;
    int nowslash2 = slash2 >> (n-y-1);
    int judge = y_row[y] & x & nowslash1 & nowslash2;
    int xput;

    while(judge) {
        xput = judge & (-judge); //lowbit
        backtracking(n, y+1, x^xput, slash1^(xput<<y), slash2^(xput<<(n-y-1)));
        judge ^= xput;
    }
}

int main() {
    int n, i;
    while(scanf("%d",&n) == 1 && n) {
        for(i = 0; i < n; ++i) {
            y_row[i] = (1<<n)-1;
        }
        Ans = 0;
        backtracking(n, 0, (1<<n)-1, (1<<(2*n-1))-1, (1<<(2*n-1))-1);
        printf("%d\n", Ans);
    }
    return 0;
}*/


//lnternet  AC 5.6S

/*#include <stdio.h>
#define SIZE 25

int A[SIZE+2], B[SIZE*SIZE], C[SIZE*SIZE],number,amount;
int *b = &B[SIZE], *c = &C[SIZE];


void Queens(int index) {
	int j = 1;
	while (j++ <= number){
        if ((A[j] | b[j - index] | c[j + index]) == 0){
			A[j] = b[j - index] = c[j + index] = 1;
			if(index < number)Queens(index + 1);
			else ++amount;
			A[j] = b[j - index] = c[j + index] = 0;
		}
	}
}

int main() {
	while (scanf("%d",&number)!=EOF){
        amount = 0;
        Queens(1);
        printf("%d\n",amount);
	}
}*/




//my tle

/*#include <stdio.h>
#define SIZE 400
#define INDEX(col,size,row) col*size+row

char checkerBoard[SIZE];
int amount=0;

int checkSlash(int size,int level,int enter){
    for(int i=enter-1,j=level+1;i>=0 && j<size;--i,++j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    for(int i=enter+1,j=level+1;i<size && j<size;++i,++j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    for(int i=enter-1,j=level-1;i>=0 && j>=0;--i,--j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    for(int i=enter+1,j=level-1;i<size && j>=0;++i,--j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    return 1;
}

void dfs(int m,int size,int visited,int level){
    if(m==0)++amount;
    else{
        for(int i=0;i<size;++i){
            if(!((visited>>i)&1) && checkSlash(size,level,i)){
                checkerBoard[INDEX(level,size,i)]='*';
                dfs(m-1,size,visited|(1<<i),level+1);
                checkerBoard[INDEX(level,size,i)]=' ';
            }
        }
    }
}

int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        for(int i=0;i<SIZE;++i)checkerBoard[i]=' ';
        amount=0;
        dfs(m,m,0,0);
        printf("%d\n",amount);
    }
}*/



/*#include <stdio.h>
#define SIZE 400
#define INDEX(col,size,row) col*size+row

char checkerBoard[SIZE];
int ans=0;

int checkSlash(int size,int level,int enter){
    for(int i=enter-1,j=level+1;i>=0 && j<size;--i,++j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    for(int i=enter+1,j=level+1;i<size && j<size;++i,++j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    for(int i=enter-1,j=level-1;i>=0 && j>=0;--i,--j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    for(int i=enter+1,j=level-1;i<size && j>=0;++i,--j)if(checkerBoard[INDEX(j,size,i)]!=' ')return 0;
    return 1;
}

void dfs(int m,int size,int visited,int level){
    if(m==0)++ans;
    else{
        for(int i=0;i<size;++i){
            if(!((visited>>i)&1) && checkSlash(size,level,i)){
                checkerBoard[INDEX(level,size,i)]='*';
                dfs(m-1,size,visited|(1<<i),level+1);
                checkerBoard[INDEX(level,size,i)]=' ';
            }
        }
    }
}

int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        for(int i=0;i<SIZE;++i)checkerBoard[i]=' ';
        ans=0;
        dfs(m,m,0,0);
        printf("%d\n",ans);
    }
}*/
