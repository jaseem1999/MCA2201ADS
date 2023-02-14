#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data){
    struct node *newNode= malloc(sizeof(struct node));
    newNode->data = data;
    if(top == NULL){
        newNode->next=NULL;
    }else{
        newNode->next = top;
    }
    top = newNode;
    printf("\ninserted successfully :: %d \n",newNode->data);
}
void pop(){
    if(top==NULL){
        printf("\n Stack is underflow");
    }else{
        struct node *temp = top;
        int data = temp->data;
        top = top->next;
        free(temp);
        printf("\n Elemet is deleted :: %d ", data);
    }
    
}
void desplay(){
    if (top==NULL)
    {
        printf("\nStack is empty\n");
    }else{
        struct node *temp = top;
        printf("NULL-->");
        while (temp->next != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

int main()
{
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            desplay();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
    return 0;
}
