#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head;
void insert(int item){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = 0;
    if(head == 0){
        head = newNode;
    }else{
       struct node *temp = head;
        while(temp->next != 0){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display(){
    struct node *temp = head;
    while(temp != 0){
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}
void main(){
    int ch,item;
    while(1){
        printf("Enter the choice \n 1 = insert \n 2 = display \n 3 = exit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value to insert");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Enter the correct choice");
        }
    }
}
