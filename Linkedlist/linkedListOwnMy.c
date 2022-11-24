#include<stdio.h>

void main(){
    struct node{
        int data;
        struct node *next;
    };
    struct node *head,*newNode,*temp;
    int choice =0,count=0;
    head = 0;
    while(choice == 0){
        newNode =(struct node*)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newNode -> data);
        newNode -> next =0;
        if(head ==0){
            head = temp = newNode;
        }else{
            temp -> next = newNode;
            temp = newNode;
        }
        printf("do you want to continue (0,1)");
        scanf("%d",&choice);
    }
    temp = head;
    while (temp !=0)
    {
        printf("%d\n", temp -> data);
        temp = temp -> next;
        count++;
    }      
}