#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 3000
int main(){
    char data[SIZE];

    while(gets(data)!=NULL){
        double answer=0;
        char *split=strtok(data," ");
        while(split!=NULL){
            //printf("s %s\n",split);
            int index=0;
            int number=0;
            int real=0;
            while(split[index]!=':'){
                number*=10;
                number+=split[index]-'0';
                ++index;
            }
            //printf("n %d\n",number);

            double sign=1;
            if(split[index+1]=='-'){
                sign=-1;
                ++index;
            }

            while(split[++index]!='.'){
                if(split[index]=='\0')break;
                real*=10;
                real+=split[index]-'0';
            }
            //printf("r %d\n",real);

            double temp=0;
            int temppow=0;
            if(split[index]!='\0')while(split[++index]!='\0'){
                temp*=10;
                temp+=split[index]-'0';
                --temppow;
            }
            //printf("f %.5f\n\n",temp);

            if(number%2)answer+=sign*(real+temp*pow(10,temppow));
            else answer-=sign*(real+temp*pow(10,temppow));
            split=strtok(NULL," ");
        }
        printf("%g\n",answer);
    }
}
