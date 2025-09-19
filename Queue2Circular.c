#include<stdio.h>
#define MAX 5

void enqueue(int[],int*,int*);
void dequeue(int[],int*,int*);
void display(int[],int*,int*);
void peek(int[],int*);

int main(){
    int queue[MAX];
    int front=-1, rear=-1;
    int choice;
    do{
        printf("\n.................CIRCULAR QUEUE.......................\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice here: ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : enqueue(queue,&front,&rear);break;
            case 2 : dequeue(queue,&front,&rear);break;
            case 3 : display(queue,&front,&rear);break;
            case 4 : peek(queue,&front);break;
            case 5 : printf("User Exited\n");break;
            default : printf("\nEnter valid input\n");
        }
    }while(choice!=5);
    return 0;
}

void enqueue(int queue[],int* front,int* rear){
    int n;
    if((*front==0 && *rear==MAX-1) || *front==*rear+1){
        printf("Queue Overflow\n");
        return;
    }
    if(*front==-1){
        *front=*rear=0;
    }
    else{
        *rear = (*rear + 1) % MAX;
    }
    printf("Enter the element here: ");
    scanf("%d",&n);
    queue[*rear] = n;
    return;
}

void dequeue(int queue[],int* front,int* rear){
    int n;
    if(*front==-1){
        printf("Queue Underflow\n");
        return;
    }
    n = queue[*front];
    if(*front == *rear){     // one element in the circular queue
        *front=*rear=-1;
    }
    else{
        *front = (*front + 1) % MAX;
    }
    printf("Dequeued Element = %d\n",n);
    return;
}

void display(int queue[],int* front,int* rear){
    if(*front==-1){
        printf("Queue Underflow\n");
        return;
    }
    int i = *front;
    printf("Queue is Below\n");
    while(1){
        printf("%d\n",queue[i]);
        if(i == *rear) break;
        i = (i+1) % MAX;
    }
    return;
}

void peek(int queue[],int* front){
    if(*front==-1){
        printf("Queue Underflow\n");
        return;
    }
    printf("Peeked element = %d\n",queue[*front]);
}