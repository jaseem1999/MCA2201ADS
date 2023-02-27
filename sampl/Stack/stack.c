#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void push(int);
void pop();
int arr[MAX];
int top = -1;
int choice;
int data;
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
            printf("\nEnter data :: ");
            scanf(" %d", &data);
            push(data);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            displayA();
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
void push(int value) {

    if(top >= MAX-1){
        printf("\n stack overloading \n");
    }else{
        top++;
        arr[top] = value;
    }
    printf("\n insertion successfully :: %d \n", arr[top]);
    printf(" \n %d top\n",top);
}
void pop(){
    if(top <= -1){
        printf("\n stack undrflow \n");
    }
    else{
        top--;
    }
    printf("deleted data is :: %d\n", arr[top+1]);
    printf("%d\n index array\n", top);
}
void displayA()
{
    if(top >= 0){
        int i;
        for (i = top; i >= 0; i--)
        {
            printf("--> %d", arr[i]);
        }
    }else{
        
        printf("\n stack empty\n");
    }
}

