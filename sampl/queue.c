#include <stdio.h>
#include <stdlib.h>
#define max 5
void enqueue(int);
void dequeue();
void display();
int arr[max];
int rear=-1,front=-1;
void enqueue(int data)
{
    if(rear==max-1){
        printf("\nqueue is full\n");
    }else {
        rear++;
        front=0;
       arr[rear]=data;
    }
    printf("\ninsertion success\n");
    printf("\n rear:%d ,front:%d\n",rear,front);
}
void dequeue(){
    if(front== -1){
       printf("\nqueue is empty\n");
    }else if(rear== front){
        rear= front= -1;
    }else{
        front++;
    }
    if(front!= -1){
        printf("\ndeleted success %d\n",arr[front-1]);
    }
}
void display()
{
    if(rear == -1){
        printf("\nqueue is empty\n");
    }else{
        int i;
        for ( i = front; i <= rear; i++)
        {
            printf("%d<---",arr[i]);
        }
        
    }
    
}
int main()
{
    int choice, value;
    printf("\nImplementation of queue arrar\n");
    while (1)
    {
        printf("\n1. enque\n2. deque \n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
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
