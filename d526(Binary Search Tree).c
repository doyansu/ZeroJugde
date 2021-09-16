#include <stdio.h>//AC (26ms, 112KB)
#include <stdlib.h>

void putint(int out)
{
  char buf[1000];
  int n=0;
  if(out<0){
    putchar('-');
    out*=-1;
  }
  do
  {
    buf[n++]='0'+(out%10);
    out/=10;
  }while(out>0);
  for(--n;n>=0;--n)putchar(buf[n]);
  putchar(' ');
}

int get_int(){
  int n=0,si=1;
  char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-')tc=getchar();
  if(tc=='-'){
    tc=getchar();
    si=-1;
  }
  while(tc>='0'&&tc<='9'){
    n=(n<<1)+(n<<3)+(tc^'0');
    tc=getchar();
  }
  return n*si;
}

typedef struct node_s{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(nodep_t *root, int data){
    nodep_t pointer = *root;
    while(pointer != NULL){
        if(pointer->data > data){
            if(pointer->left == NULL)
                root = &(pointer->left);
            pointer = pointer->left;
        }
        else{
            if(pointer->right == NULL)
                root = &(pointer->right);
            pointer = pointer->right;
        }
    }
    *root = createNewNode(data);
}

void traval(nodep_t root){
    if(root != NULL){
        putint(root->data);
        traval(root->left);
        traval(root->right);
        free(root->left);
        free(root->right);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        nodep_t root = NULL;
        while(n--)
            insert(&root, get_int());
        traval(root);
        putchar('\n');
    }
}

/*#include <stdio.h> //AC (29ms, 96KB)
#include <stdlib.h>

void putint(int out)
{
  char buf[1000];
  int n=0;
  if(out<0){
    putchar('-');
    out*=-1;
  }
  do
  {
    buf[n++]='0'+(out%10);
    out/=10;
  }while(out>0);
  for(--n;n>=0;--n)putchar(buf[n]);
  putchar(' ');
}

int get_int(){
  int n=0,si=1;
  char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-')tc=getchar();
  if(tc=='-'){
    tc=getchar();
    si=-1;
  }
  while(tc>='0'&&tc<='9'){
    n=(n<<1)+(n<<3)+(tc^'0');
    tc=getchar();
  }
  return n*si;
}

typedef struct node_s{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(nodep_t *root, int data){
    nodep_t pointer = *root;
    while(pointer != NULL){
        if(pointer->data > data){
            if(pointer->left == NULL)
                root = &(pointer->left);
            pointer = pointer->left;
        }
        else{
            if(pointer->right == NULL)root = &(pointer->right);
            pointer = pointer->right;
        }
    }
    *root = createNewNode(data);
}

void traval(nodep_t root){
    if(root != NULL){
        putint(root->data);
        traval(root->left);
        traval(root->right);
        free(root->left);
        free(root->right);
    }
}

int main(){
    int n, data;
    while(scanf("%d", &n) == 1){
        nodep_t root = NULL;
        while(n--){
            data = get_int();
            insert(&root, data);
        }
        traval(root);
        putchar('\n');
    }
}*/
