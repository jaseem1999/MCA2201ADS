#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
};

struct node *head = NULL;
struct node *end=NULL;
static int size = 0;

void insert_head(int data){
  struct node *node;
  node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->next = head;
  node->prev = NULL;
  if(head != NULL)
  {
    head->prev = node;
    head = node;
  }
  else
  {
    head = node;
    end = node;
  }
  size++;
}

void insert_end(int data){
  struct node *node;
  node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  if(end == NULL)
  {
    head = node;
    end = node;
  }
  else{
    node->prev = end;
    end->next = node;
    end = node;
  }
  size++;
}
void delete_head(){
  struct node *temp;
  if(head != NULL){
      printf("\n\t\tNode deleted: %d", head->data);
      temp = head;
      head = head->next;
      if(head!=NULL)
        head->prev = NULL;
      else
        end = NULL;
      free(temp);
      size--;
  }
  else
    printf("\n\t\tLinked List is Empty!!");
}

void delete_end(){
  if(head == NULL)
    printf("\t\tLinked list is empty!!");
  else{
    printf("\n\t\tNode deleted: %d", end->data);
    struct node *temp,*nxt_temp;
    temp = end;
    end = end->prev;
    if(end == NULL)
      head = NULL;
    else
      end->next = NULL;
    free(temp);
    size--;
  }
}
void display_forward(){
  if(head == NULL)
    printf("\n\t\tLinked List is Empty!!");
  else{
    struct node *link = head;
    printf("\t\t");
    while(link->next != NULL){
      printf("%d ", link->data);
      link = link->next;
    }
    printf("%d\n", link->data);
  }
}

void display_reverse(){
  if(end == NULL)
    printf("\n\t\tLinked List is Empty!!");
  else{
    struct node *link = end;
    printf("\t\t");
    while(link->prev != NULL){
      printf("%d ", link->data);
      link = link->prev;
    }
    printf("%d\n", link->data);
  }
}
void search(){
  int count = 1;
  if(head == NULL)
    printf("\n\t\tLinked List is Empty!!");
  else{
    int data;
    printf("Enter the number you want to search:");
    scanf("%d", &data);
    struct node *link = head;
    printf("\t\t");
    do{
      if(link->data==data){
        printf("\n\t\tThe number is found in the linked list!! %d and position is %d", link->data, count);
        return;
      }
      count++;
      link = link->next;
    }while(link != NULL);
    printf("\n\t\tThe number is not found in the linked list!!");
  }
}
int main(){
    int choice, data, pos;
    while(1){
        printf("\n 1. Insert at head");
        printf("\n 2. Insert at end");
        printf("\n 3. Delete at head");
        printf("\n 4. Delete at end");
        printf("\n 5. Display forward");
        printf("\n 6. Display reverse");
        printf("\n 7. Search");
        printf("\n 8. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\n Enter the data: ");
                scanf("%d", &data);
                insert_head(data);
                break;
            case 2:
                printf("\n Enter the data: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 3:
                delete_head();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                display_forward();
                break;
            case 6:
                display_reverse();
                break;
            case 7:
                search();
                break;
            case 8:
                exit(0);
            default:
                printf("\n Invalid choice!!");
        }
    }
}



