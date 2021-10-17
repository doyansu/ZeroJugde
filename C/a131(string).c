#include <stdio.h>
#include <string.h>
#define SIZE 21

void mystrcpy(char *s1, char *s2){
    while(*s2 != '\0')
        *s1++ = *s2++;
}

char deCode(char ch){
    switch(ch){
    case 'A':case 'E':case 'I':case 'O':
    case 'U':case 'Y':case 'W':case 'H':
        ch = '\0';
        break;
    case 'B':case 'P':case 'F':case 'V':
        ch = '1';
        break;
    case 'C':case 'S':case 'K':case 'G':
    case 'J':case 'Q':case 'X':case 'Z':
        ch = '2';
        break;
    case 'D':
    case 'T':
        ch = '3';
        break;
    case 'L':
        ch = '4';
        break;
    case 'M':
    case 'N':
        ch = '5';
        break;
    case 'R':
        ch = '6';
        break;
    default:
        ch = '\0';
        break;
    }
    return ch;
}

static inline void solve(){
    char name[SIZE];
    register char *p, *code, *end, temp;
    puts("NAME                     SOUNDEX CODE");
    while(gets(name) != NULL){
        char output[39] = "                                   000";
        mystrcpy(output + 9, name);
        p = name;
        end = output + 38;
        code = output + 34;
        *code++ = *p++;
        while(*p != '\0'){
            temp = deCode(*p);
            if(temp && (temp != deCode(*(p - 1)))){
                *code++ = temp;
                if(code == end)break;
            }
            p++;
        }
        puts(output);
    }
    puts("                   END OF OUTPUT");
}

int main(){
    solve();
    return 0;
}
