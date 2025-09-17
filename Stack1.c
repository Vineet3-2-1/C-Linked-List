#include<stdio.h>
#define MAX 5

void push(int[],int*);
void pop(int[],int*);
void display(int[],int*);
void peek(int[],int*);

int main(){
    int stack[MAX];
    int top = -1;
    int choice;
    do{
        printf("\n....................STACK......................\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice here: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: push(stack,&top);break;
            case 2: pop(stack,&top);break;
            case 3: display(stack,&top);break;
            case 4: peek(stack,&top);break;
            case 5: printf("\nUser Exited the Program\n");break;
            default: printf("Enter correct choice from 1 to 5\n");
        }
    }while(choice!=5);
    return 0;
}

void push(int stack[],int* top){
    int n;
    if(*top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    else{
        *top = *top + 1;
        printf("Enter the element here: ");
        scanf("%d",&n);
        stack[*top] = n;
        return;
    }
}

void pop(int stack[],int* top){
    int n;
    if(*top == -1){
        printf("Stack Underflow\n");
        return;
    }
    else{
        n = stack[*top];
        *top = *top - 1;
        printf("Popped Element = %d\n",n);
        return;
    }
}

void display(int stack[],int* top){
    int i;
    if(*top == -1){
        printf("Stack Underflow\n");
        return;
    }
    else{
        printf("\nStack is Below\n");
        for(i = *top; i>=0; i--){
            printf("%d\n",stack[i]);
        }
        return;
    }
}

void peek(int stack[],int* top){
    if(*top == -1){
        printf("Stack Underflow\n");
        return;
    }
    else{
        printf("Peeked element = %d\n",stack[*top]);
    }
    return;
}