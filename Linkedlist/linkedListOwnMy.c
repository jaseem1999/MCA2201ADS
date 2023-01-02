#include<stdio.h>

void main(){
    struct node{
        int data;
        struct node *next;
    };//DEFINING NODE STRUCTURE
    struct node *head,*newNode,*temp; //DECLARING NODE POINTER
    int choice =0,count=0; //DECLARING VARIABLES FOR CHOICE AND COUNT CHOISE IS FOR CHOICE OF USER AND COUNT IS FOR COUNTING NODES
    head = 0;//INITIALISING HEAD TO NULL
    while(choice == 0){
        newNode =(struct node*)malloc(sizeof(struct node));//SIZE DECLARING FOR NEW NODE
        printf("enter data");
        scanf(" %d",&newNode -> data);//ENTRING DATA IN NEW NODE
        newNode -> next =0;//AFTER ADDING THE DATA AND DECLARING NEW NODE NEXT IS SET TO NULL
        if(head ==0){
            head = temp = newNode;//IF HEAD IS NULL THEN NEW NODE IS ADDED TO HEAD
        }else{
            temp -> next = newNode;//IF HEAD IS NOT NULL THEN NEW NODE IS ADDED TO NEXT OF TEMP
            temp = newNode;//THEN TEMP IS SET TO NEW NODE
        }
        printf("do you want to continue (0,1)");//ASKING USER TO CONTINUE OR NOT
        scanf("%d",&choice);//READING USER CHOICE
    }
    temp = head;//AFTER ADDING ALL THE NODES TEM    P IS SET TO HEAD
    while (temp !=0)//DISPALYING ALL THE NODE
    {
        printf("%d\n", temp -> data);//PRINTING DATA OF NODE
        temp = temp -> next;//CALLING NEW NODE
        count++;
    }      
}