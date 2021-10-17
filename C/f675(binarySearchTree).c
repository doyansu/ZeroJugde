#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{// tree node
    int data;
    struct node_s* left, *right; // left, right node
}node_t;

typedef node_t* nodep_t; // node pointer type

nodep_t createNewNode(int data){// create a new node (initial)
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertData(nodep_t *root, int data){// insert data into tree
    if(*root == NULL)
        *root = createNewNode(data);
    else if(data < (*root)->data)
        insertData(&(*root)->left, data);
    else
        insertData(&(*root)->right, data);
}

int searchData(nodep_t root, int data){// search for data in tree
    if(root == NULL)
        return 0;
    if(data == root->data)
        return 1;
    else if(data < root->data)
        return searchData(root->left, data);
    else
        return searchData(root->right, data);
}

void travel(nodep_t root){// Inorder Traversal
    if(root != NULL){
        travel(root->left);
        printf("%d\n", root->data);
        travel(root->right);
    }
}

int main(){
    int n;// n input
    nodep_t root = NULL;
    scanf("%d", &n);
    while(n--){// create tree
        int data;
        scanf("%d", &data);
        insertData(&root, data);
    }

    travel(root);// travel From small to large

    int target;
    scanf("%d", &target);// get search target
    if(searchData(root, target))
        puts("Yes");
    else
        puts("No");
}
