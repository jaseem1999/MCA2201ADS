// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int item)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }
    top = newNode;
    printf("\nNode Is Created\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("\n Stuck is Underflow");
    }
    else
    {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);

        printf("\ndeleted successfully\n");
    }
}
void display()
{
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
    push(10);
    push(20);
    push(30);
    display();

    return 0;
}