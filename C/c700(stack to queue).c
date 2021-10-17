#include <stdio.h>
#define SIZE 100

int main(){
    char str[SIZE];
    int lena = 0, lenb = 0;
    while(fgets(str, SIZE, stdin) != NULL){
        if(str[1] == 'u'){
            putchar('1');
            lena++;
        }
        else{
            if(lenb){
                putchar('4');
                lenb--;
            }
            else{
                for(int i = 0; i < lena; i++){
                    putchar('5');
                }
                lenb = lena;
                if(lenb){
                    putchar('4');
                    lenb--;
                }
                lena = 0;
            }

        }
    }
    return 0;
}
