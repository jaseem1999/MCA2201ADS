#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *rear = NULL;
struct node *front = NULL;

void enQueue(int data){
   struct node *newNode = malloc(sizeof(struct node));
   newNode->data = data;
   if(rear == NULL && front == NULL){
        rear = front = newNode;
        rear->next =front;
   }else{
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
   }
   printf("\n Queue inserted data is :: %d\n", newNode->data);
}

void dequeue(){
    if(rear == NULL && front == NULL){
        printf("\n Queue is UnderFlow\n");
    }else if(rear == front){
        struct node * temp = front;
        front = rear = NULL;
        free(temp);
    }else{
        struct node *temp = front;
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
    
}
void displayNode(){
    if (rear == NULL && front == NULL)
    {
        printf("\n Queue is empty\n");
    }
    else
    {
        struct node *temp = front;
        while (temp->next != front){
            printf("%d-->",temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

int main(){
    int choice, x;
    while (1)
    {
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d", &x);
            enQueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayNode();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
