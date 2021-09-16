#include <stdio.h>

long long int goal,step=0;

void hanoi(int n,char A,char B,char C) {
    if(step<0)return;
    if(n==1)
        printf("move %d from %c to %c\n",n,A,C);
    else{
        long long int temp=1;
        temp<<=(n-1);
        if(step+temp>goal)
            hanoi(n-1,A,C,B);
        else if(step+temp==goal)
            printf("move %d from %c to %c\n",n,A,C);
        else{
            step+=temp;
            hanoi(n-1,B,A,C);
        }
    }
}

int main(){
    int n;
    while(scanf("%d%lld",&n,&goal)!=EOF){
        step=0;
        hanoi(n,'1','2','3');
    }
}

/*#include <stdio.h>

long long int step;

void move(int i , char x , char y) {
    static long long int c=0;
    ++c;
    if(step==c){
        printf("move %d from %c to %c",i,x,y);
        step=-1;
    }
}
void hanoi(int i,char A,char B,char C) {
    if(step<0)return;
    if(i==1)
        move(i,A,C);
    else{
        hanoi(i-1,A,C,B);
        move(i,A,C);
        hanoi(i-1,B,A,C);
    }
}

int main(){
    int n;
    scanf("%d%lld",&n,&step);
    hanoi(n,'1','2','3');
}*/
