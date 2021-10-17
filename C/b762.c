#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(){
    int n,kill=0,assist=0,die=0,conti=0;
    char input[SIZE];
    scanf("%d",&n);
    while(n--){
        scanf("%s",input);
        if(strcmp(input,"Get_Kill")==0){
            ++kill;
            if(conti<8)++conti;
        }
        else if(strcmp(input,"Get_Assist")==0){
            ++assist;
            continue;
        }
        else{
            ++die;
            if(conti<3)puts("You have been slained.");
            else puts("SHUTDOWN.");
            conti=0;
        }
        switch(conti){
        case 1:case 2:
            puts("You have slain an enemie.");
            break;
        case 3:
            puts("KILLING SPREE!");
            break;
        case 4:
            puts("RAMPAGE~");
            break;
        case 5:
            puts("UNSTOPPABLE!");
            break;
        case 6:
            puts("DOMINATING!");
            break;
        case 7:
            puts("GUALIKE!");
            break;
        case 8:
            puts("LEGENDARY!");
            break;

        }
    }
    printf("%d/%d/%d\n",kill,die,assist);
}
