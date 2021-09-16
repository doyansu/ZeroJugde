//2ms
/*int main(){
    char s[1000];
    int index=0;
    gets(s);
    while(s[index]!='\0')s[index++]=s[index]-7;
    printf("%s",s);
}*/

int main(){//1ms
    char c;
    while(scanf("%c",&c)){
        printf("%c",c-7);
        if(c=='\n')break;
    }
}
