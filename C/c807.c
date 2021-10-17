#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001
#define BUFSIZE 2097152
#define MAXINF 0x7fffffff

typedef struct node_s{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newnode = malloc(sizeof(node_t));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insertBtree(nodep_t *root, int data){
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

void myfree(nodep_t freenode, int *elements){
    nodep_t temp;
    while(freenode != NULL){
        temp = freenode;
        freenode = freenode->right;
        (*elements)--;
        //free(temp);
    }
}

/*void popInterval(nodep_t root){
    if(*root == NULL)return;
    int min, max;
    nodep_t pointer = *root;
    scanf("%d%d", &min, &max);
}*/

/*void popInterval(nodep_t *root, int *elements){
    if(*root == NULL)return;
    int min, max;
    nodep_t pointer = *root , temp, freeNode, newLeft, newRight;
    scanf("%d%d", &min, &max);

    while((pointer != NULL) && (pointer->data > max)){
        temp = pointer;
        pointer = pointer->left;
    }
    if(pointer == NULL)return;
    else if(pointer == *root)*root = newLeft = pointer->left;
    newRight = pointer;

    while((newRight != NULL) && (newRight->data > max)){
        freeNode = newRight;
        newRight = newRight->right;
        free(freeNode);
        (*elements)--;
    }

}*/

int getMax(nodep_t root){
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int getMin(nodep_t root){
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

void traval(nodep_t root){
    if(root != NULL){
        //putint(root->data);
        traval(root->left);
        traval(root->right);
        free(root->left);
        free(root->right);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int max = -1, min = MAXINF, elements = 0;
        nodep_t root = NULL;
        while(n--){
            int oper, data;
            scanf("%d", &oper);
            switch(oper){
            case 1:
                scanf("%d", &data);
                if(data > max)max = data;
                if(data < min)min = data;
                insertBtree(&root, data);
                elements++;
                break;
            case 2:
                popInterval(&root, &elements);
                max = getMax(root);
                min = getMin(root);
                break;
            default:
                puts("input error");
                return 0;
                break;
            }
            if(elements == 0)puts("0");
            else if(elements == 1)printf("out1 %d\n", max);
            else printf("out2 %d %d\n", min, max);
        }
        //traval(root);
    }
}


/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001
#define BUFSIZE 2097152
#define MAXINF 0x7fffffff

typedef struct node_s{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newnode = malloc(sizeof(node_t));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insertBtree(nodep_t *root, int data){
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

void myfree(nodep_t freenode, int *elements){
    nodep_t temp;
    while(freenode != NULL){
        temp = freenode;
        freenode = freenode->right;
        (*elements)--;
        //free(temp);
    }
}

void popInterval(nodep_t *root, int *elements){
    if(*root == NULL)return;
    int min, max;
    scanf("%d%d", &min, &max);
    nodep_t pointer = *root , temp, freeNode;
    while((pointer != NULL) && (pointer->data > max)){
        root = &pointer;
        printf("p %d\n", pointer->data);
        pointer = pointer->left;
    }

    temp = pointer;
    puts("in0");

    while((pointer != NULL) && (pointer->data >= min)){
        printf("p %d\n", pointer->data);
        pointer = pointer->left;
    }

    if(*root != temp)(*root)->left = pointer;
    else *root = pointer;
    puts("in1");

    while((temp != NULL) && (temp->data <= max)){
        freeNode = temp;
        printf("p %d\n", temp->data);
        temp = temp->right;
        myfree(freeNode, elements);
    }

    puts("in2");

    while((pointer->right != NULL) && (pointer->data >= min)){
        printf("p %d\n", pointer->data);
        pointer = pointer->right;
    }


    myfree(pointer->right, elements);
    pointer->right = temp;
    puts("in3");
}

int getMax(nodep_t root){
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int getMin(nodep_t root){
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

void traval(nodep_t root){
    if(root != NULL){
        //putint(root->data);
        traval(root->left);
        traval(root->right);
        free(root->left);
        free(root->right);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int max = -1, min = MAXINF, elements = 0;
        nodep_t root = NULL;
        while(n--){
            int oper, data;
            scanf("%d", &oper);
            switch(oper){
            case 1:
                scanf("%d", &data);
                if(data > max)max = data;
                if(data < min)min = data;
                insertBtree(&root, data);
                elements++;
                break;
            case 2:
                popInterval(&root, &elements);
                max = getMax(root);
                min = getMin(root);
                break;
            default:
                puts("input error");
                return 0;
                break;
            }
            if(elements == 0)puts("0");
            else if(elements == 1)printf("out1 %d\n", max);
            else printf("out2 %d %d\n", min, max);
        }
        //traval(root);
    }
}
*/
