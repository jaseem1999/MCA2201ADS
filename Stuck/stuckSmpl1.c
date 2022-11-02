#include <stdio.h>
void push(int);
void pop();
void display();
int top = -1,arr[10];
void push(int item){
    if(top == 9){
        printf("Stack is full");
    }
    else{
        top++;
        arr[top] = item;
    }
}
void pop(){
    if(top == -1){
        printf("Stack is empty");
    }
    else{
        top--;
    }
}
void display(){
    int i;
    if(top == -1){
        printf("Stack is empty");
    }
    else{
        for(i = top; i >= 0; i--){
            printf("\n%d",arr[i]);
        }
        //array length is
        printf("\nArray length is %d",sizeof(arr)/sizeof(arr[0]));
    }
}
int main(){
        push(20);
        push(30);
        push(40);
        push(50);
        push(60);
        pop();
        pop();
        display();
    return 0;
}

