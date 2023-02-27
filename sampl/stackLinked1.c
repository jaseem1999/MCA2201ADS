#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if(top == NULL){
        newnode->next = NULL;
        top = newnode;
    }else{
        newnode -> next = top;
        top = newnode;
    }
    printf("\ninsertion successfully:: %d\n", newnode->data);
}
void pop(){
    if(top == NULL){
        printf("\n stack is underflow\n");
    }else{
        struct node *tmp = top;
        int data = tmp->data;
        top = top->next;
        free(tmp);
        printf("\nDeleted successfully:: %d\n", data);
    }
   
}
void display()
{
    // Display the elements of the stack
    if (top == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("The stack is \n");
        struct node *temp = top;
        printf("NULL-->");
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d\n\n", temp->data);
    }
}
int main()
{
    int top = NULL;
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
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
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
