#include <stdio.h>
#include <string.h>
#define SIZE 60

int main(){
    int r,c;
    int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    char cdir[8][3]={{'N'},{'N','E'},{'E'},{'S','E'},{'S'},{'S','W'},{'W'},{'N','W'}};
    char map[SIZE][SIZE];
    int badplan[SIZE][SIZE]={0};
    memset(map,'H',sizeof(map));
    scanf("%d%d ",&r,&c);
    for(int x=1;x<=r;x++){
        for(int y=1;y<=c;y++)map[x][y]=getchar();
        getchar();
    }
    int nowx,nowy,finish=0;
    char oper;
    while(scanf("%d%d %c ",&nowx,&nowy,&oper)!=EOF){
        int nowdir=0;
        switch(oper){
        case 'W':
            nowdir+=2;
        case 'S':
            nowdir+=2;
        case 'E':
            nowdir+=2;
        case 'N':
            break;
        }
        char str[301];
        fgets(str,302,stdin);
        char *p=str;
        if(finish)puts("I think I don't need to move anymore.");
        else{
            while(*p!='\0'){
                int temp=0;
                if(*p=='R'){
                    p++;
                    while(*p>='0' && *p<='9'){
                        temp=(temp<<3)+(temp<<1)+((*p)^'0');
                        p++;
                    }
                    //printf("%d %c\n",temp,*p);
                    nowdir=(nowdir+temp/45)&7;
                }
                else if(*p=='L'){
                    p++;
                    while(*p>='0' && *p<='9'){
                        temp=(temp<<3)+(temp<<1)+((*p)^'0');
                        p++;
                    }
                    nowdir=(8+nowdir-temp/45)&7;
                }
                else if(*p=='M'){
                    nowx+=dir[nowdir][1];
                    nowy+=dir[nowdir][0];
                    if(map[nowy][nowx]=='T'){
                        finish=1;
                        printf("%d %d",nowx,nowy);
                        puts(" FINISHED!");
                        break;
                    }
                    else if(map[nowy][nowx]=='H'){
                        nowx-=dir[nowdir][1];
                        nowy-=dir[nowdir][0];
                        if(((badplan[nowy][nowx]>>nowdir)&1)==0){
                            badplan[nowy][nowx]|=1<<nowdir;
                            printf("%d %d %s BAD PLAN!\n",nowx,nowy,cdir[nowdir]);
                            break;
                        }
                    }
                    p++;
                }
                else p++;
                if(*p=='\0'){
                    printf("%d %d ",nowx,nowy);
                    puts(cdir[nowdir]);
                }
            }
        }
    }
}

/*#include <stdio.h>
#include <string.h>
#define SIZE 60

void printmap(char map[SIZE][SIZE],int r,int c){
    for(int x=0;x<=r+1;x++){
        for(int y=0;y<=c+1;y++)
            printf("%c",map[x][y]);
        putchar('\n');
    }
}

int main(){
    int r,c;
    int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    char cdir[8][3]={{'N'},{'N','E'},{'E'},{'S','E'},{'S'},{'S','W'},{'W'},{'N','W'}};
    char map[SIZE][SIZE];
    int badplan[SIZE][SIZE]={0};
    memset(map,'H',sizeof(map));
    scanf("%d%d ",&r,&c);
    for(int x=1;x<=r;x++){
        for(int y=1;y<=c;y++)scanf("%c",&map[x][y]);
        getchar();
    }
    int nowx,nowy,finish=0;
    char oper;
    while(scanf("%d%d %c ",&nowx,&nowy,&oper)!=EOF){
        //printmap(map,r,c);
        int nowdir=0;
        switch(oper){
        case 'W':
            nowdir+=2;
        case 'S':
            nowdir+=2;
        case 'E':
            nowdir+=2;
        case 'N':
            break;
        }
        char str[301];
        fgets(str,302,stdin);
        char *p=str;
        if(finish)puts("I think I don't need to move anymore.");
        else{
            while(*p!='\0'){
                int temp=0;
                if(*p=='R'){
                    p++;
                    while(*p>='0' && *p<='9'){
                        temp=(temp<<3)+(temp<<1)+((*p)^'0');
                        p++;
                    }
                    //printf("%d %c\n",temp,*p);
                    nowdir=(nowdir+temp/45)&7;
                }
                else if(*p=='L'){
                    p++;
                    while(*p>='0' && *p<='9'){
                        temp=(temp<<3)+(temp<<1)+((*p)^'0');
                        p++;
                    }
                    //printf("%d\n",temp);
                    nowdir=(8+nowdir-temp/45)&7;
                }
                else if(*p=='M'){
                    nowx+=dir[nowdir][1];
                    nowy+=dir[nowdir][0];
                    if(map[nowy][nowx]=='T'){
                        finish=1;
                        printf("%d %d FINISHED!\n",nowx,nowy);
                        break;
                    }
                    else if(map[nowy][nowx]=='H'){
                        nowx-=dir[nowdir][1];
                        nowy-=dir[nowdir][0];
                        if(((badplan[nowy][nowx]>>nowdir)&1)==0){
                            badplan[nowy][nowx]|=1<<nowdir;
                            printf("%d %d %s BAD PLAN!\n",nowx,nowy,cdir[nowdir]);
                            break;
                        }
                    }
                    p++;
                }
                else p++;
                if(*p=='\0')printf("%d %d %s\n",nowx,nowy,cdir[nowdir]);
            }
        }
    }
}*/
