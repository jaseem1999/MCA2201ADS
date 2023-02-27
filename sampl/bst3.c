#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
struct node *root;

struct node *newNode(int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return newNode(value);
    }
    else if (value == root->data)
    {
        printf("Same data can't be stored");
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    return root;
}

// Inorder traversal
void inorderTraversal(struct node *root)
{
    if (root == NULL){
        return;
    }else{
        inorderTraversal(root->left);
        printf("%d ->", root->data);
        inorderTraversal(root->right);
    }
}
void preorder(struct node* root)
{
    if(root == NULL){
        return;
    }else{
        printf("%d ",root->data);
        preorder( root->left);
        preorder( root->right);
    }
}
void postorder(struct node *root)
{
    if(root == NULL){
        return;
    }
    else
    {   
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct node *search(struct node *root,int value){
    if (root == NULL){
        printf("\n No found \n");
    }else if(root->data == value){
        printf("\n%d Found \n", root->data);
    }else{
        if(root->data > value)
            return search(root->left,value);
        return search(root->right, value);
    }
}

struct node *minimum(struct node *root){
    struct node *current = root;
    while (current && current->left != NULL)
    {
        current = current->right;
    }
    return current;
    
}

struct node *delete(struct node *root , int del){
    if (root == NULL)
    {
        return root;
    }else if(root->data > del){
        root-> left = delete(root->left,del);
    }else if(root->data < del){
        root->right = delete (root->right, del);
    }else{
        if (root->left = NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *tmp = minmum(root->right);
        root->data = tmp->data;
        root->right = delete(root->data, tmp->data);
        
    }
    return root;
}
int main()
{
    int opt;
    int value, searchv, key;
    do
    {
        printf("\n1)Create Root Node \n2)Insert Node\n3)Search\n");
        printf("4)inorderTraversal \n5)preorderTraversal \n6)postorderTraversal \n7)Delete \n8)Quiet \n");
        printf("Choose Option :: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter a number : ");
            scanf("%d", &value);
            root = newNode(value);
            break;
        case 2:
            printf("\nEnter a number : ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 3:
            printf("\nEnter a number : ");
            scanf("%d", &searchv);
            search(root, searchv);
            break;
        case 4:
            printf("\n..................................\n");
            inorderTraversal(root);
            printf("\n..................................\n");
            break;
        case 5:
            printf("\n..................................\n");
            preorder(root);
            printf("\n..................................\n");
            break;
        case 6:
            printf("\n..................................\n");
            postorder(root);
            printf("\n..................................\n");
            break;
        case 7:
            printf("\nEnter a number to be deleted : ");
            scanf("%d", &key);
            delete(root, key);
            break;
        defualt:
            printf("Invalid option!");
        }
    } while (opt != 8);
    return 0;
}