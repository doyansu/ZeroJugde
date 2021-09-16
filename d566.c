#include <stdio.h>
#define SIZE 40000

int getNumber(char *p){
    int number = 0;
    int i = 1;
    while(*p != '\0')
        number += (*p++ - '/') * i++;// don't need * i++
    return number;
}

int main(){
    char name[31];
    char state[4];
    char visited[SIZE], killjugde[SIZE];
    int n, number, kill = 0, AC = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%s%s", name, state);
        number = getNumber(name);
        if(*state == 'A'){
            if(visited[number] == 0)AC++;
            if(killjugde[number] == 0){
                kill++;
                killjugde[number] = 1;
            }
            visited[number] = 1;
        }
        else if(killjugde[number] == 1){
            kill--;
            killjugde[number] = 0;
        }
    }
    printf("%d%%\n",(kill*100)/AC);
}
