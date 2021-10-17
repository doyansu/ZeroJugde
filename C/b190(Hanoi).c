#include <stdio.h>

int move(int i , char x , char y) {
    static int c=0;
    if(i==-10){
        int temp=c;
        c=0;
        return temp;
    }
    if(i<1)return -1;
    ++c;
    printf("ring %d : %c -> %c\n",i,x,y);
    return -1;
}

void hanoi(int i,char A,char B,char C){
    if(i<0)return;
    if(i==1)
        move(i,A,C);
    else{
        hanoi(i-1,A,C,B);
        move(i,A,C);
        hanoi(i-1,B,A,C);
    }
}

void douhanoi(int n) {
    if(n<0)return;
    if(n==1)
        move(1,'a','b');
    else if(n%2){
        hanoi(n-1,'a','b','c');
        move(n,'a','b');
        hanoi(n-3,'c','b','a');
        move(n-2,'c','b');
        douhanoi(n-3);
    }
    else{
        hanoi(n-1,'a','c','b');
        move(n,'a','c');
        hanoi(n-3,'b','c','a');
        move(n-2,'b','c');
        douhanoi(n-3);
    }
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        douhanoi(n);
        printf("共移動了 %d 步\n",move(-10,'x','x'));
    }
}

/*#include <stdio.h>

int move(int i , char x , char y) {
    static int c=0;
    if(i==-10){
        int temp=c;
        c=0;
        return temp;
    }
    if(i<1)return -1;
    ++c;
    //printf("ring %d : %c -> %c\n",i,x,y);
    putchar('r');
    putchar('i');
    putchar('n');
    putchar('g');
    putchar(' ');
    printf("%d",i);
    putchar(' ');
    putchar(':');
    putchar(' ');
    putchar(x);
    putchar(' ');
    putchar('-');
    putchar('>');
    putchar(' ');
    putchar(y);
    putchar('\n');
    return -1;
}

void hanoi(int i,char A,char B,char C){
    if(i<0)return;
    if(i==1)
        move(i,A,C);
    else{
        hanoi(i-1,A,C,B);
        move(i,A,C);
        hanoi(i-1,B,A,C);
    }
}

void douhanoi(int n) {
    if(n<0)return;
    if(n==1)
        move(1,'a','b');
    else if(n%2){
        hanoi(n-1,'a','b','c');
        move(n,'a','b');
        hanoi(n-3,'c','b','a');
        move(n-2,'c','b');
        douhanoi(n-3);
    }
    else{
        hanoi(n-1,'a','c','b');
        move(n,'a','c');
        hanoi(n-3,'b','c','a');
        move(n-2,'b','c');
        douhanoi(n-3);
    }
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        douhanoi(n);
        printf("共移動了 %d 步\n",move(-10,'x','x'));
    }
}*/


/*void move(int i , char x , char y) {
    static int c=1;
    printf("%d: %d from %c > %c\n", c++ , i , x , y);
}
void hanoi(int i , char A , char C , char B) {
    if(i ==1)
        move(i , A , C);
    else{
        hanoi(i -1 , A , B , C);
        move(i , A , C);
        hanoi(i -1 , B , C , A);
    }
}*/
