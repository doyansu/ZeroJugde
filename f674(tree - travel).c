#include <stdio.h>
#define MAXSIZE 31 // MAX tree nodes

typedef struct node_s{// node
    int left, right; // left node, right node
}node_t;

void travel(node_t *tree, char type, int root){
    if(root != -1){
        if(type == 'L')
            printf("%d ", root);
        travel(tree, type, tree[root].left);
        if(type == 'M')
            printf("%d ", root);
        travel(tree, type, tree[root].right);
        if(type == 'R')
            printf("%d ", root);
    }
}

int main(){
    int n; // n nodes
    node_t tree[MAXSIZE];
    scanf("%d", &n);
    while(n--){// create tree
        int root;
        scanf("%d", &root);
        scanf("%d%d", &tree[root].left, &tree[root].right);
    }
    travel(tree, 'L', 0);// Preorder Traversal  form node 0
    putchar('\n');
    travel(tree, 'M', 0);// Inorder Traversal   form node 0
    putchar('\n');
    travel(tree, 'R', 0);// Postorder Traversal form node 0
    putchar('\n');
}
