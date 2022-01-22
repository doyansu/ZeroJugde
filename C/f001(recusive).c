#include <stdio.h>
#include <string.h>

char CB[10];//checkerboard
char output[209], *p;// output checkerboard


int checkWin(char *board){//check 'O' or 'X' win return 1 else 0
    for(int i = 0; i < 3; i++)
        if(board[3 * i] == board[3 * i + 1] && board[3 * i + 1] == board[3 * i + 2] || board[i] == board[3 + i] && board[3 + i] == board[6 + i])
            return 1;
    return board[0] == board[4] && board[4] == board[8] || board[2] == board[4] && board[4] == board[6] ? 1 : 0;
}

int permutations(char symbol, int start, int level){// ±Æ¦C
    if(level == 0){
        char temp[10];
        strcpy(temp, CB);
        for(int i = 0; i < 9; i++)
            if(temp[i] == '-')
                temp[i] = (symbol ^ 23);
        if(!checkWin(temp)){
            for(int i = 0; i < 9; i++){
                *p++ = temp[i];
                if((i + 1) % 3 == 0)
                    *p++ = '\n';
            }
            *p++ = '\n';
            return 1;
        }
        return 0;
    }

    int sum = 0;
    for(int i = start; i < 9; i++){
        if(CB[i] == '-'){
            CB[i] = symbol;
            sum += permutations(symbol, i + 1, level - 1);
            CB[i] = '-';
        }
    }
    return sum;
}

int main(){
    while(gets(CB)){
        int dash = 0;
        for(int i = 0; i < 9; i++)
            if(CB[i] == '-')
                dash++;
        p = output;
        memset(output, 0, sizeof(output));
        printf("%d\n", permutations('O', 0, (dash + 1) / 2));//first 'O'
        p = '\0';
        puts(output);
    }
    return 0;
}

