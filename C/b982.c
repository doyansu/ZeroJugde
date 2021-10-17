#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

char* turn(char *p,int *z){
    while(*p>='0' && *p<='9'){
        *z=(*z)*10;
        *z+=(*p)-'0';
        ++p;
    }
    return p;
}

int main()
{
    int first;
    while(scanf("%d",&first)!=EOF){
        char str[SIZE];
        char *p=str;
        int y=0,z=0;
        gets(str);
        switch(*p){
            case 'k':
                printf("%d\n",first*8000);
                break;
            case 'b':
                ++p;
                switch(*p){
                case 'i':
                    printf("%d\n",first);
                    break;
                case 'y':
                    printf("%d\n",first*8);
                    break;
                }
                break;
            case '.':
                ++p;
                p=turn(p,&y);
                switch(*p){
                case 'k':
                    printf("%d\n",first*8000+y*800);
                    break;
                case 'b':
                    printf("%d\n",first*8+y);
                    break;
                }
                break;
            case 'm':
                ++p;
                switch(*p){
                case 'b':
                    if(first*8==0)puts("0");
                    else printf("%d000000\n",first*8);
                    break;
                default:
                    p=turn(p,&y);
                    if(first*8000+y*8==0)puts("0");
                    else printf("%d000\n",first*8000+y*8);
                    break;
                }
                break;
            case 'g':
                ++p;
                switch(*p){
                case 'b':
                    if(first*8==0)puts("0");
                    else printf("%d000000000\n",first*8);
                    break;
                default:
                    p=turn(p,&y);
                    ++p;
                    switch(*p){
                    case '\0':
                        if(first*8000+y*8==0)puts("0");
                        else printf("%d000000\n",first*8000+y*8);
                        break;
                    default:
                        p=turn(p,&z);
                        first*=8;
                        y*=8;
                        z*=8;
                        y+=z/1000;
                        z%=1000;
                        first+=y/1000;
                        y%=1000;
                        if(first==0 && y==0 && z==0)puts("0");
                        else printf("%d%d%d000\n",first,y,z);
                        break;
                    }
                    break;
                }
                break;
        }
    }
}
