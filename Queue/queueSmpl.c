#include<stdio.h>
void insert(int);
void delete();
void display();
int arr[10], front = -1, rear = -1, element, items, ite,del;
void insert(int item)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    arr[rear] = item;
}
void delete(){
    if(front == -1){
        printf("Queue is empty");
    }else{
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
                front = front + 1;
        }
    }
}
void display(){
    if(front == -1){
        printf("Queue is empty");
    }else{
        printf("\nQueue elements are: ");
        for(int i = front; i <= rear; i++){
            printf("%d ",arr[i]);
        }
    }
}
void main(){
    
        int i;
        int a;
        printf("how many element you want inserted\n");
        scanf("%d",&element);
        printf("Enter the element to be inserted\n");
        for(i=0;i<element;i++){
            scanf("%d",&items);
            insert(items);
        }
        printf("\ndo you want to delete  if \n1 = yes\n 2 = no\n");
        scanf("%d",&a);
        if(a==1){
            printf("\nhow many element do you want to delete\n");
            scanf("%d",&del);
            for ( i = 0; i <del; i++)
            {
                delete();
            }
            display();
        }else if(a==0){
            printf("Thank you");
        }else{
            printf("Invalid input");
        }
    
}