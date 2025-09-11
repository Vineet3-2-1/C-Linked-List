//Single Linked List (traditional linked list)

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* head;
void Insert(int);
void Print();
int main()
{
    head = NULL;
    int n,i,d;
    printf("How many nodes do you want. Enter here: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the data here: ");
        scanf("%d",&d);
        Insert(d);
        Print();
    }
    return 0;
}

void Insert(int d)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    if(head==NULL){
    head = temp;
    return;
    }

    struct node* temp1 = head;
    while(temp1->link!=NULL){
        temp1 = temp1->link;
    }
    temp1->link = temp;
    return;
}

void Print(){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
    return;
}