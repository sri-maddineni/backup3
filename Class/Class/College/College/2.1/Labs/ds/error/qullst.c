#include<stdio.h>
#include<stdlib.h>
void enq();
void deq();
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*ptr;

void main()
{
    int ch;
    printf("*queue using linked list *\n");
    do
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: enq();
                break;

        case 2: deq();
                break;
        case 3: display();
                break;
        case 4: exit(0);
                break;
       default: printf("invalid choice\n");
        }
    } while(ch<=4);
    getch();
}
void enq()
{
ptr=(struct node *)malloc(sizeof(struct node));
printf("Enter data : ");
scanf("%d",&ptr->data);
ptr->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
    {
    rear->next=ptr;
    rear=ptr;
    }
    }
  void deq()
    {
    struct node *tmp;
    if(front==NULL)
    printf("queue is empty,deletion is not possible\n");
    else
    {
     tmp=front;
     printf("deleted element is %d\n",front->data);
     front=front->next;
     free(tmp);
    }
    }
    void display()
    {
     struct node *tmp;
     tmp=front;
     if(front==NULL&&rear==NULL)
     printf("queue is empty\n");
     else
     {
      while(tmp!=NULL)
      {
       printf("%d\t",tmp->data);
       tmp=tmp->next;
      }
     }
}
