#include<stdio.h>
void insert(int);
void delete();
void display();
int arr[10], front = -1, rear = -1, element, items, ite;
void insert(int item)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == 9){
        printf("Queue is full");
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
            printf("how many items you want to delete");
            scanf("%d",&ite);
            for(int i=0;i<ite;i++){
                front = front + 1;
            }
        }
        printf("Deleted element is %d",element);
    }
}
void display(){
    if(front == -1){
        printf("Queue is empty");
    }else{
        printf("Queue elements are: ");
        for(int i = front; i <= rear; i++){
            printf("%d ",arr[i]);
        }
    }
}
void main(){
    
        int i;
        char d;
        printf("how many element you want inserted\n");
        scanf("%d",&element);
        printf("Enter the element to be inserted\n");
        for(i=0;i<element;i++){
            scanf("%d",&items);
            insert(items);
        }
        display();
        printf("\ndo you want to delete\n");
        scanf("%c",&d);
        printf("%c",d);
        if(d=='y' || d=='Y'){
            delete();
            display();
        }else if(d=='n' || d=='N'){
            printf("Thank you");
        }else{
            printf("Invalid input");
        }
    
}