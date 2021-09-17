#include <stdio.h>//AC (2.6s, 114.5MB)
#define MAXINPUT 10000010
#define MAXINF 0x7fffffff

typedef struct node_s{
    int left, right;
}node_t;

static inline void reisei(int *p, int n, unsigned int a, unsigned int c, unsigned int m){
    for(int i=1; i<=n; i++) p[i] = i;
    unsigned int x = 0;
    for(int i=1; i<=n-1; i++){
        x = ((unsigned long long)a*x+c)%m;
        int j = i + x%(n-i+1);
        int t = p[i];
        p[i] = p[j];
        p[j] = t;
    }
}

int min(int a, int b){
    return a < b ? a : b;
}

int pi[MAXINPUT];
node_t list[MAXINPUT];

void solve(){
    int n;
    unsigned int a, c, m;
    while(scanf("%d", &n) == 1){
        scanf("%u%u%u", &a, &c, &m);
        reisei(pi, n, a, c, m);
        for(int i = 1; i <= n; i++){
            list[i].left = i - 1;
            list[i].right = i + 1;
        }
        list[1].left = -MAXINF + 10;
        list[n].right = MAXINF;
        int ans = 0;
        for(int i = n; i > 1; i--){
            int deleteNode = pi[i], left = list[deleteNode].left, right = list[deleteNode].right;
            ans ^= (i + min(deleteNode - left, right - deleteNode));
            if(left > 0)list[left].right = right;
            if(right < n + 1)list[right].left = left;
        }
        printf("%d\n", ans);
    }
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000100
#define MAXINF 0x7fffffff

int array[SIZE]={0};

typedef struct node_s{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void createList(nodep_t *origin,nodep_t *end,int n){
    *origin=createNewNode(-MAXINF+SIZE);
    nodep_t pointer=*origin;
    ++n;
    for(int i=1;i<n;++i){
        pointer->right=createNewNode(i);
        pointer->right->left=pointer;
        pointer=pointer->right;
    }
    pointer->right=createNewNode(MAXINF);
    pointer->right->left=pointer;
    *end=pointer->right;
}

void deleteNode(nodep_t pointer){
    nodep_t leftp=pointer->left;
    nodep_t rightp=pointer->right;
    if(rightp!=NULL)rightp->left=leftp;
    if(leftp!=NULL)leftp->right=rightp;
    free(pointer);
}

nodep_t searchNodeFR(nodep_t origin,int index){
    while(origin->data!=index)origin=origin->right;
    return origin;
}

nodep_t searchNodeFL(nodep_t end,int index){
    while(end->data!=index)end=end->left;
    return end;
}


void reisei(int *p, int n, unsigned int a, unsigned int c, unsigned int m){
     for(int i=1; i<=n; i++) p[i] = i;
     unsigned int x = 0;
     for(int i=1; i<=n-1; i++){
            x = ((unsigned long long)a*x+c)%m;
            int j = i + x%(n-i+1);
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
     }
}

int main(){
    int n;
    unsigned int a,c,m;
    while(scanf("%d",&n)==1){
        scanf("%u%u%u",&a,&c,&m);
        reisei(array,n,a,c,m);
        nodep_t origin;
        nodep_t end;
        createList(&origin,&end,n);
        int ans=0;
        for(int i=n;i>1;--i){
            nodep_t pointer;
            if(array[i]<n/2)pointer=searchNodeFR(origin,array[i]);
            else pointer=searchNodeFL(end,array[i]);
            int leftd=MAXINF,rightd=MAXINF;
            //if(pointer->left!=NULL)
            leftd=pointer->data-pointer->left->data;
            //if(pointer->right!=NULL)
            rightd=pointer->right->data-pointer->data;
            if(rightd<leftd)leftd=rightd;
            //printf("leftd %d rightd %d\n",leftd,rightd);
            ans^=leftd+i;
            deleteNode(pointer);
        }
        free(origin);
        free(end);
        printf("%d\n",ans);
    }
}
*/
/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000100
#define MAXINF 0x7fffffff

int array[SIZE]={0};

typedef struct node_s{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

nodep_t createList(int n){
    nodep_t origin=createNewNode(-MAXINF+SIZE);
    nodep_t pointer=origin;
    ++n;
    for(int i=1;i<n;++i){
        pointer->right=createNewNode(i);
        pointer->right->left=pointer;
        pointer=pointer->right;
    }
    return origin;
}

void deleteNode(nodep_t pointer){
    nodep_t leftp=pointer->left;
    nodep_t rightp=pointer->right;
    if(rightp!=NULL)rightp->left=leftp;
    if(leftp!=NULL)leftp->right=rightp;
    free(pointer);
}

nodep_t searchNode(nodep_t origin,int index){
    while(origin->data!=index)origin=origin->right;
    return origin;
}


void reisei(int *p, int n, unsigned int a, unsigned int c, unsigned int m){
     for(int i=1; i<=n; i++) p[i] = i;
     unsigned int x = 0;
     for(int i=1; i<=n-1; i++){
            x = ((unsigned long long)a*x+c)%m;
            int j = i + x%(n-i+1);
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
     }
}

int main(){
    int n;
    unsigned int a,c,m;
    while(scanf("%d",&n)==1){
        scanf("%u%u%u",&a,&c,&m);
        reisei(array,n,a,c,m);
        nodep_t origin=createList(n);
        int ans=0;
        for(int i=n;i>1;--i){
            nodep_t pointer=searchNode(origin,array[i]);
            int leftd=MAXINF,rightd=MAXINF;
            if(pointer->left!=NULL)leftd=pointer->data-pointer->left->data;
            if(pointer->right!=NULL)rightd=pointer->right->data-pointer->data;
            if(rightd<leftd)leftd=rightd;
            //printf("leftd %d rightd %d\n",leftd,rightd);
            ans^=leftd+i;
            deleteNode(pointer);
        }
        printf("%d\n",ans);
    }
}*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000100
#define MAXINF 0x7fffffff

int array[SIZE]={0};
int list[SIZE]={0};

typedef struct node_s{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

nodep_t createList(int n){
    nodep_t origin=createNewNode(1);
    nodep_t pointer=origin;
    ++n;
    for(int i=2;i<n;++i){
        pointer->right=createNewNode(i);
        pointer->right->left=pointer;
        pointer=pointer->right;
    }
    return origin;
}

void deleteNode(nodep_t origin,int data){
    while(origin->data!=data)origin=origin->right;
    nodep_t leftp=origin->left;
    nodep_t rightp=origin->right;
    rightp->left=rightp;
    leftp->right=leftp;
    free(origin);
}

nodep_t searchNode(nodep_t origin,int index){
    while(origin->data!=index)origin=origin->right;
    return origin;
}


void reisei(int *p, int n, unsigned int a, unsigned int c, unsigned int m){
     for(int i=1; i<=n; i++) p[i] = i;
     unsigned int x = 0;
     for(int i=1; i<=n-1; i++){
            x = ((unsigned long long)a*x+c)%m;
            int j = i + x%(n-i+1);
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
     }
}

int main(){
    int n;
    unsigned int a,c,m;
    while(scanf("%d",&n)==1){
        scanf("%u%u%u",&a,&c,&m);
        reisei(array,n,a,c,m);
        nodep_t origin=createList(n);
        int ans=0;
        for(int i=n;i>1;--i){
            nodep_t pointer=searchNode(origin,array[i]);
            int leftd=1,rightd=1;
            if(pointer->left!=NULL)leftd=pointer->data-pointer->left->data;
            if(pointer->right!=NULL)rightd=pointer->right->data-pointer->data;
            if(rightd>leftd)leftd=rightd;
            ans^=i+leftd;
            deleteNode(origin,array[i]);
        }

        printf("%d\n",ans);
    }
}*/

/*#include <stdio.h>
#define SIZE 10000100
#define MAXINF 0x7fffffff

int array[SIZE]={0};
int list[SIZE]={0};

void reisei(int *p, int n, unsigned int a, unsigned int c, unsigned int m){
     for(int i=1; i<=n; i++) p[i] = i;
     unsigned int x = 0;
     for(int i=1; i<=n-1; i++){
            x = ((unsigned long long)a*x+c)%m;
            int j = i + x%(n-i+1);
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
     }
}

int main(){
    int n;
    unsigned int a,c,m;
    while(scanf("%d",&n)==1){
        scanf("%u%u%u",&a,&c,&m);
        reisei(array,n,a,c,m);
        for(int i=0; i<=n;++i)list[i]=i;
        int ans=0;
        for(int i=n;i>1;--i){
            int min;
            int index=array[i];
            int temp=1;
            list[index]=-1;
            while(list[index+temp]<=0 && list[index-temp]<=0)++temp;
            ans^=temp+i;
        }
        printf("%d\n",ans);
    }
}*/


/*#include <stdio.h>
#define SIZE 10000001
#define MAXINF 0x7fffffff

int array[SIZE];
int list[SIZE];

int myabs(int a){
    return a>0?a:-a;
}

void reisei(int *p, int n, unsigned int a, unsigned int c, unsigned int m){
     for(int i=1; i<=n; i++) p[i] = i;
     unsigned int x = 0;
     for(int i=1; i<=n-1; i++){
            x = ((unsigned long long)a*x+c)%m;
            int j = i + x%(n-i+1);
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
     }
}

int main(){
    int n;
    unsigned int a,c,m;
    while(scanf("%d",&n)==1){
        scanf("%u%u%u",&a,&c,&m);
        reisei(array,n,a,c,m);
        int ans=0;
        ++n;
        for(int i=2;i<n;++i){
            int min=MAXINF;
            for(int j=i-1;j>0;--j){
                int temp=myabs(array[i]-array[j]);
                if(temp<min){
                    min=temp;
                    if(min==1)break;
                }
            }
            ans^=min+i;
        }
        printf("%d\n",ans);
    }
}*/
