#include <stdio.h>
#define SIZE 100

static inline char* mysplit(char* s, char ch){
    int temp = 0;
    while(*s){
        if(*s == '(')++temp;
        else if(*s == ')')--temp;
        if(temp == 0 && *s == ch){
            *s = '\0';
            return s + 1;
        }
        s++;
    }
    return NULL;
}

static inline int checkIsNumber(char* s){
    while(*s){
        if(*s > '9' || *s < '0')
            return 0;
        s++;
    }
    return 1;
}

static inline int turnToInt(char* s){
    int n = 0;
    while(*s)
        n = (n << 3) + (n << 1) + ('0' ^ *s++);
    return n;
}

static inline int solve(char *string){
    char *temp;
    if(checkIsNumber(string))return turnToInt(string);
    if(temp = mysplit(string, '+'))return solve(string) + solve(temp);
    if(temp = mysplit(string, '-'))return solve(string) - solve(temp);
    if(temp = mysplit(string, '*'))return solve(string) * solve(temp);
    if(temp = mysplit(string, '/'))return solve(string) / solve(temp);
    if(temp = mysplit(string, '%'))return solve(string) % solve(temp);
    if(*string == '('){
        mysplit(string, ')');
        *string = '\0';
        return solve(string + 1);
    }
}

int main(){
    int n;
    char s[SIZE], ch, *p;
    while(scanf("%c", &ch) == 1){
        p = s;
        while(ch != '\n'){
            if(ch != ' ')
                *p++ = ch;
            scanf("%c", &ch);
        }
        *p = '\0';
        printf("%d\n",solve(s));
    }
}

/*#include <stdio.h>
#define SIZE 100

char* mysplit(char* s,char ch){
    int temp=0;
    while(*s!='\0'){
        if(*s=='(')++temp;
        else if(*s==')')--temp;
        if(temp==0 && *s==ch){
            *s='\0';
            return s+1;
        }
        s++;
    }
    return 0;
}

int checkIsNumber(char* s){
    while(*s!='\0'){
        if((*s-'0')>9 || (*s-'0')<0)return 0;
        s++;
    }
    return 1;
}

int turnToInt(char* s){
    int n=0;
    while(*s!='\0'){
        n*=10;
        n+=*s-'0';
        s++;
    }
    return n;
}

int solve(char *string){
    char *temp;
    if(checkIsNumber(string))return turnToInt(string);
    if(temp=mysplit(string,'+'))return solve(string)+solve(temp);
    if(temp=mysplit(string,'-'))return solve(string)-solve(temp);
    if(temp=mysplit(string,'*'))return solve(string)*solve(temp);
    if(temp=mysplit(string,'/'))return solve(string)/solve(temp);
    if(temp=mysplit(string,'%'))return solve(string)%solve(temp);
    if(*string=='('){
        mysplit(string,')');
        *string='\0';
        return solve(string+1);
    }
}

int main(){
    int n;
    char s[SIZE],ch;
    while(scanf("%c",&ch)!=-1){
        int index=0;
        while(ch!='\n'){
            if(ch!=' ')s[index++]=ch;
            scanf("%c", &ch);
        }
        s[index]='\0';
        printf("%d\n",solve(s));
    }
}
*/

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000
//wa line7
int f(char *s){
    //printf("input: %s\n",s);
    int i=-1,ch=0,index=1;
    if(strlen(s)==1){
        //printf("return int(%d)\n",s[0]-'0');
        return s[0]-'0';
    }
    else if(s[0]=='\0')return 1;
    char *list=calloc(SIZE,sizeof(char));
    while(s[++i]!='\0'){
        if(s[i]=='(')ch++;
        if(s[i]==')')ch--;
        if(ch)continue;
        if(s[i]=='+'){
            s[i]='\0';
            list[i]='+';
        }
        else if(s[i]=='-'){
            s[i]='\0';
            list[i]='-';
        }
    }
    for(i=0;i<SIZE;i++){
        if(list[i]=='+')ch+=f(s+i+1);
        else if (list[i]=='-')ch-=f(s+i+1);
    }
    if(ch)return ch+f(s);
    int n1=0,temp=0;
    for(i=0;i<strlen(s)+1;i++){
        if(s[i]=='('){
            /*if(s[i+1]=='-'){
                index=1;
                n1=0;
                while(s[i+1+index]>47 && s[i+1+index]<58){
                    n1*=10;
                    n1+=(s[i+1+(index++)]-'0');
                }
                //printf("return -n1=int(%d)\n",-n1);
                //return -n1;
                n1=-n1;
            }
            if(ch==0)temp=i;
            ch++;
        }
        else if(s[i]==')'){
            ch--;
            if(ch==0&&n1>=0){
                s[i]='\0';
                //printf("return %s (?) %s\n",s+1,s+i+2);
                if(s[i+1]=='*'){
                    s[i+1]='\0';
                    return f(s+1)*f(s+i+2);
                }
                else if(s[i+1]=='/'){
                    s[i+1]='\0';
                    return f(s+1)/f(s+i+2);
                }
                else if(s[i+1]=='%'){
                    s[i+1]='\0';
                    return f(s+1)%f(s+i+2);
                }
                else return f(s+1);
            }

        }
        if(!ch){
            if(s[i]=='*'){
                s[i]='\0';
                //printf("return int(%d) * %s\n",n1,s+i+1);
                return n1*f(s+i+1);
            }
            else if(s[i]=='/'){
                s[i]='\0';
                //printf("return int(%d) / %s\n",n1,s+i+1);
                return n1/f(s+i+1);
            }
            else if(s[i]=='%'){
                s[i]='\0';
                //printf("return int(%d) mod %s\n",n1,s+i+1);
                return n1%f(s+i+1);
            }
            else if(s[i]=='\0'){
                //printf("return n1=int(%d)\n",n1);
                return n1;
            }
            else if(n1>=0){
                n1*=10;
                n1+=(s[i]-'0');
            }
        }
    }
    return 1;
}

int main(){
    char c;
    while(scanf("%c",&c)!=-1){
        char *s=calloc(SIZE,sizeof(char));
        int index=0;
        do{
            char temp;
            if(c!=' '){
                /*if(c>47 && c<58 && s[index-1]=='-'){
                    s[index-1]='(';
                    s[index++]='-';
                    do{
                        s[index++]=c;
                        scanf("%c",&c);
                    }while(c>47 && c<58);
                    s[index++]=')';
                }
                else s[index++]=c;
            }
            scanf("%c",&c);
        }while(c!='\n');
        s[index]='\0';
        printf("%d\n",f(s));
    }
}*/


