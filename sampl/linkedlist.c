// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insert(int item)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = 0;
    if (head == 0)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display()
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf(" %d \t", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int ch, data;
    do
    {
        printf("1 = insert \n 2 = dispaly \n 3 = exit ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the data");
            scanf("%d", &data);
            insert(data);
        }
        if (ch == 2)
        {
            printf("Dispaly\n");
            display();
        }
    } while (ch != 3);
    return 0;
}
