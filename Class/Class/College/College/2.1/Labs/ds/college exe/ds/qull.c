#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;


void enq();
void deq();
void display();

void main()
{
    int ch;
    printf("\nQueue using linked list");
    do
    {
        printf("\n1.enq\n2.deq\n3.display\n4.exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:enq();
                   break;
            case 2:deq();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
            default:printf("\nInvalid choice");
        }
    }
    while(ch<=4);
}



void enq()
{
    struct node *newnode;
     newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter node data : ");
    scanf("%d",&newnode->data);

    newnode->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        newnode->next=NULL;
        rear->next=newnode;
        rear=newnode;
    }
    printf("\nElement inserted successfully!");
}


void display()
{
    struct node *temp;
    temp=front;

    if(front==NULL&&rear==NULL)
        printf("\nQueue empty,display not possible");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }

}


void deq()
{
    struct node *temp;
    temp=front;

    if(front==NULL)
        printf("\nQueue empty!");
    else
    {
        printf("\nDeleted element is %d",temp->data);
        front=front->next;
        free(temp);
    }
}
