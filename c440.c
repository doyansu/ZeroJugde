#include <stdio.h>//AC 2ms
#define SIZE 100003

void putllint(long long int out)
{
  char buf[1000];
  int n=0;
  if(out<0) putchar('-'),out=out*-1;
  do
  {
    buf[n++]='0'+(out%10);
    out=out/10;
  }while(out>0);
  for(n=n-1;n>=0;n--)putchar(buf[n]);
}

int main()
{
    char str[SIZE];
    char newstr[SIZE];
    char *p=str,*np=newstr;
    fgets(str,SIZE,stdin);
    long long int sum=0,rightQ=0,leftQ=0;
    while(*p!='\0'){
        if(*p=='Q'){
            *(np)++ = 'Q';
            ++rightQ;
        }
        else if(*p=='A'){
            *(np)++ = 'A';
        }
        ++p;
    }
    *np='\0';
    np=newstr;
    while(*np!='\0'){
        if(*np=='Q'){
            ++leftQ;
            --rightQ;
        }
        else{
            sum+=leftQ*rightQ;
        }
        ++np;
    }
    putllint(sum);
}
