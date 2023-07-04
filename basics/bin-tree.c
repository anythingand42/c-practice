#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void bin_tree_add(struct node **proot, int data)
{
    if(!*proot) {
        *proot = malloc(sizeof(struct node));
        (*proot)->data = data;
        (*proot)->left = (*proot)->right = NULL;
    } 
    if((*proot)->data == data)
        return;
    else if((*proot)->data < data)
        bin_tree_add(&(*proot)->left, data);
    else
        bin_tree_add(&(*proot)->right, data);
}

void bin_tree_print(struct node *root)
{
    if(!root)
        return;
    bin_tree_print(root->left);
    printf("%d ", root->data);
    bin_tree_print(root->right);
}

int main()
{
    struct node *tree = NULL;
    bin_tree_add(&tree, 5);
    bin_tree_add(&tree, 2);
    bin_tree_add(&tree, 7);
    bin_tree_print(tree);
    return 0;
}

