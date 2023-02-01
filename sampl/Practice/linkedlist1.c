#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*top = NULL;

void main() {
    int value,ch;
    struct node *newNode;
    struct node *temp = newNode;
    
    newNode =(struct node*)malloc(sizeof(struct node));
    while(1){
        printf("Enter the choice \n 1 = insert \n 2 = dispay \n 3 = exit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value to insert");
                scanf("%d",&value);
                newNode->data = value;
                newNode->next = top;
                top = newNode;
                break;
            case 2:
                while(temp->next != NULL){
                    printf("%d \n",newNode->data);
                    temp = temp->next;
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Enter the correct choice");
        }
    }
}