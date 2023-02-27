#include<stdio.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *root;

struct node *newRoot(int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data){
    if (root == NULL){
        return newRoot(data);
    }else if (root->data == data){
        printf("\nits same value we cann't insert %d\n",data);
    }else if (root->data < data){
       root->right = insert(root->right,data);
    }else if (root->data > data){
        root->left = insert(root->left,data);
    }
    return root;
}

void inorderTraversal(struct node *root){
    if (root == NULL) 
        return;
    inorderTraversal(root->left);
    printf("--> %d",root->data);
    inorderTraversal(root->right);
    
    
}

void preorderTraversal(struct node *root){
    if (root == NULL)
        return;
    printf("%d-->",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct node *root){
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d-->",root->data);
}
void search(struct node *root, int key){
    if (root == NULL)
        return;
    if (root->data == key){
        printf("\n%d is found\n",key);
    }else if (root->data < key){
        search(root->right,key);
    }else if (root->data > key){
        search(root->left,key);
    }
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
    }
}

        int main()
        {
            int opt;
            int value;
            int key = 0;
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
                    root = newRoot(value);
                    break;
                case 2:
                    printf("\nEnter a number : ");
                    scanf("%d", &value);
                    root = insert(root, value);
                    break;
                case 3:
                    printf("\nEnter a number : ");
                    scanf("%d", &key);
                    search(root, key);
                    break;
                case 4:
                    printf("\n..................................\n");
                    inorderTraversal(root);
                    printf("\n..................................\n");
                    break;
                case 5:
                    printf("\n..................................\n");
                    preorderTraversal(root);
                    printf("\n..................................\n");
                    break;
                case 6:
                    printf("\n..................................\n");
                    postorderTraversal(root);
                    printf("\n..................................\n");
                    break;
                case 7:
                    printf("\nEnter a number : ");
                    scanf("%d", &key);
                    root = deleteNode(root, key);
                    break;
                default:
                    printf("Invalid option!");
                }
            } while (opt != 8);
            return 0;
        }
