#include <stdio.h>
#define SIZE 51

int main(){
    int input;
    char ch;
    while(scanf("%d%c", &input, &ch) != EOF){
        int list[SIZE] = {0};
        int number = 2;
        list[input] = 1;
        if(ch!='\n')
            while(scanf("%d%c", &input ,&ch)){
                int index=-1;
                input++;
                while(input)
                    if(list[++index] == 0)input--;
                list[index] =  number++;
                if(ch == '\n')break;
            }
        number--;
        for(int i = 0; i < number; i++)printf("%d ", list[i]);
        putchar('\n');
    }
    return 0;
}
