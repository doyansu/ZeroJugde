#define X(M,D) (M*2+D)%3
int main(){
    int m,d;
    scanf("%d %d",&m,&d);
    switch(X(m,d)){
    case 0:
        printf("´¶³q");
        break;
    case 1:
        printf("¦N");
        break;
    case 2:
        printf("¤j¦N");
        break;
    }
}
