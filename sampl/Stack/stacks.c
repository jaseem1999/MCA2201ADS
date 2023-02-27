#include <stdio.h>
#include <stdlib.h>
#define n 5
int stack[n], choice, top= -1, x, i;
void push(void);
void pop(void);
void display(void);
int main()
{
    printf("\n\t--------------------------------");
    
    do
    {
        printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT\n");
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 4);
    return 0;
}
void push()
{
    if (top >= n - 1)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--){
            printf("\n%d", stack[i]);
        }
    }
    else
    {
        printf("\n The STACK is empty");
    }
}