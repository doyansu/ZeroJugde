#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

char* turn(char *p,double *z){
    while(*p>='0' && *p<='9'){
        *z=(*z)*10;
        *z+=(*p)-'0';
        ++p;
    }
    return p;
}

int main()
{
    double first;
    while(scanf("%lf",&first)!=EOF){
        char str[SIZE];
        char *p=str;
        double y=0,z=0;
        gets(str);
        switch(*p){
            case 'h':
                ++p;
                switch(*p){
                case 'o':
                    printf("%.0f\n",first*3600000);
                    break;
                default:
                    p=turn(p,&y);
                    ++p;
                    switch(*p){
                    case '\0':
                        printf("%.0f\n",(first*60+y)*60000);
                        break;
                    default:
                        p=turn(p,&z);
                        printf("%.0f\n",(first*60+y)*60000+z*1000);
                        break;
                    }
                    break;
                }
                break;
            case 'm':
                ++p;
                switch(*p){
                case 'i':
                    printf("%.0f\n",first*60000);
                    break;
                case 's':
                    printf("%.0f\n",first);
                    break;
                default:
                    p=turn(p,&z);
                    printf("%.0f\n",(first*60+z)*1000);
                    break;
                }
                break;
            case 's':
                printf("%.0f\n",first*1000);
                break;
        }
    }
}
