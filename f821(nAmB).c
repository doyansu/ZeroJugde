#include<stdio.h>
#define SIZE 20

int namb(char *list1,char *list2,int size){
    int a = 0, b = 0;
    int visited=0;
    for(int i=0;i<size;i++)
        if(list1[i]==list2[i]){
            a++;
            list2[i]='\0';
            visited ^= (1<<i);
        }
    for(int i=0;i<size;i++){
        if((visited>>i)&1)continue;
        for(int j=0;j<size;j++)
            if(list1[i]==list2[j]){
                b++;
                list2[j]='\0';
                break;
            }
    }
    printf("%dA%dB\n", a, b);
}

int main(){
    char password[SIZE], guess[SIZE];
    int temp;
    while(fgets(password, SIZE, stdin)!=NULL){
        int size = 0 ,n = 0;
        while(password[size++] != ' ');
        temp = size;
        size--;
        while(password[temp] != '\n'){
            n = (n<<3) + (n<<1) + (password[temp] ^ '0');
            temp++;
        }
        while(n--){
            fgets(guess, SIZE, stdin);
            namb(password, guess, size);
        }
    }
}
