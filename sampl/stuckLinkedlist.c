// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *top = NULL;
void push(int);
void pop();
void dispaly();

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
    printf("newNode is created");
}
void pop()
{
    if (top == NULL)
    {
        printf("Stuck is empty");
    }
    else
    {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
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
    push(50);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}