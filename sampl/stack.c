#include <stdio.h>
#define MAX 5
void push(int);
void pop();
int arr[MAX];
int top = -1;
void push(int data){
    if(top >= MAX-1){
        printf("\n stack overloading \n");
    }else{
        top++;
        arr[top] = data;
    }
    printf("\n insertion successfully :: %d \n",arr[top]);
    printf("\nTop value::%d\n",top);
}
void pop(){
    if(top<0){
        printf("\n stack undrflow \n");
    }
    else{
        top--;
    }
    printf("deleted data is :: %d\n", arr[top+1]);
    printf("\nTop value :: %d\n", top);
}
void display()
{
    if(top < 0){
        printf("\n stack empty\n");
    }else{
        int i;
        for(i = top; i >= 0;i-- ){
            printf("--> %d",arr[i]);
        }
    }
}

void main(){
    int data;
    int ch;
    do
    {
        printf("\n1. push \n2. pop \n3. dispaly\n4.exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the data\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exit");
            break;
        default:
            printf("invalid choice");
            break;
        }

    } while (ch != 4);
    
}