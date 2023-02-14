#include <stdio.h>
int arr[10], top = -1, items, i, size, d,elementDelete;
void push();
void pop();
void display();
int main()
{
    if (top = -1)
    {
        printf("your stack is empty\n");
        push();  
        display();
        printf("\ndo you want to delete element from stack\n");
        printf("1 = yes\n2 = no\n");
        scanf("%d", &d);
        if (d == 1)
        {
            pop();
        }else{
            printf("thank you");
        }
        display();
    }
    else
    {
        printf("your stack is full\n");
    }
    return 0;
}
void push()
{
    top = 0;
    printf("enter how many elments you want\n");
    scanf("%d", &size);
    printf("enter the element to be inserted\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &items);
        arr[top] = items;
        top++;
    }   
}
void pop(){
    if(top == -1){
        printf("Stack is empty");
    }else{
        printf("how many element you want to delete\n");
        scanf("%d",&elementDelete);
        for(i = 0; i < elementDelete; i++){
            top--;    
        }
    }
}
void display()
{
    for (i = top-1; i >= 0; i--)
    {
        printf(" %d ,", arr[i]);
    }
}