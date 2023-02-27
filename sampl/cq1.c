// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *rear = NULL;
struct node *front = NULL;
int x = 0;
void enQueue(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    if (rear == NULL && front == NULL)
    {
        rear = front = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("\n Queue inserted data is :: %d\n", newNode->data);
}
void deQueue()
{
    if (rear == NULL && front == NULL)
    {
        printf("\n Queue is UnderFlow\n");
    }
    else if (rear == front)
    {
        struct node *temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    printf("\n Deleted Successfully \n");
}
void display()
{
    if (rear == NULL && front == NULL)
    {
        printf("\n Queue is empty\n");
    }
    else
    {
        struct node *temp = front;
        while (temp->next != front)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
int main()
{
    int choice;
    do{
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter the element to be inserted:");
                scanf("%d\n",&x);
                enQueue(x);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }while (choice != 4);
    
    return 0;
}
