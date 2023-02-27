#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value, int size)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}

int dequeue(int size)
{
    int value;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        value = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return value;
    }
}

void display(int size)
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        if (rear >= front)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else
        {
            for (i = front; i < size; i++)
            {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int size, value, choice;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    do
    {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value, size);
            break;
        case 2:
            dequeue(size);
            break;
        case 3:
            display(size);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}