#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *p;
    struct Node *left;
    struct Node *right;
    int key;
} Node;

typedef struct BST {
    Node *root;
} BST;

void inorder_tree_walk(Node *x);

BST* gen_bst(int* arr, int arr_size);

int main() {
    int arr[6] = { 6, 7, 5, 8, 5, 2 };

    BST *bst = gen_bst(arr, 6);

    inorder_tree_walk(bst->root);
    printf("\n");

    return 0;
}

void inorder_tree_walk(Node *x) {
    if (x != NULL) {
        inorder_tree_walk(x->left);
        printf("%d ", x->key);
        inorder_tree_walk(x->right);
    }
}

void insert_tree_node(Node *root, Node *node) {
        if (root->key >= node->key) {
            if (root->left == NULL) {
                node->p = root;
                root->left = node;
            } else {
                insert_tree_node(root->left, node);
            }
        } else {
            if (root->right == NULL) {
                node->p = root;
                root->right = node;
            } else {
                insert_tree_node(root->right, node);
            }
        }
}

BST* gen_bst(int* arr, int arr_size) {
    BST *bst = NULL;
    bst = malloc(sizeof (BST));


    if (arr_size < 1) {
        return bst;
    }

    Node *root = malloc(sizeof (Node));
    root->key = arr[0];
    root->p = NULL;
    root->left = NULL;
    root->right = NULL;

    bst->root = root;
    
    for (int i = 1; i < arr_size; i++) {
        Node *node = malloc(sizeof (Node));
        
        node->key = arr[i];

        insert_tree_node(root, node);
    }

    return bst;
}
