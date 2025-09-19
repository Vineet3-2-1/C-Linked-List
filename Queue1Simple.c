#include<stdio.h>
#define MAX 5

void enqueue(int[],int*,int*);
void dequeue(int[],int*,int*);
void display(int[],int*,int*);
void peek(int[],int*,int*);

int main(){
    int queue[MAX];
    int front=-1, rear=-1;
    int choice;
    do{
        printf("\n..................SIMPLE QUEUE....................\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice here: ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : enqueue(queue,&front,&rear);break;
            case 2 : dequeue(queue,&front,&rear);break;
            case 3 : display(queue,&front,&rear);break;
            case 4 : peek(queue,&front,&rear);break;
            case 5 : printf("\nUser Exited the Program\n");break;
            default : printf("\nEnter valid input between 1 and 5\n");
        }
    }while(choice!=5);
    return 0;
}

void enqueue(int queue[],int* front,int* rear){
    int n;
    if(*front == -1){
        *front = 0;
    }
    if(*rear == MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    else{
        *rear = *rear + 1;
        printf("Enter the element here: ");
        scanf("%d",&n);
        queue[*rear] = n;
        return;
    }
}

void dequeue(int queue[], int* front, int* rear){
    int n;
    if(*rear < *front || *front==-1){
        printf("Queue Underflow\n");
        return;
    }
    else{
        n = queue[*front];
        *front = *front + 1;
        printf("Dequeued Element = %d\n",n);
        if(*rear < *front){
        *front = *rear = -1; //queue becomes empty
        }
        return;
    }
}

void display(int queue[],int* front,int* rear){
    int i;
    if(*rear < *front || *front == -1){
        printf("Queue Underflow\n");
        return;
    }
    else{
        printf("\nQueue is below\n");
        for(i = *front;i<= *rear;i++){
            printf("%d\n",queue[i]);
        }
        return;
    }
}

void peek(int queue[],int* front,int* rear){
    if(*rear < *front || *front == -1){
        printf("Queue Underflow\n");
        return;
    }
    else{
        printf("\nPeeked element = %d\n",queue[*front]);
        return;
    }
}