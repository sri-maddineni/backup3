#include<stdio.h>
#include<stdlib.h>

#define size 5



void enq();
void deq();
void display();

int Q[size],front=-1,rear=-1;

void main()
{
    int ch;
    printf("** QUEUE USING ARRAY **\n");

    do
    {
        printf("\n\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("enter your choice\n");
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
            default:printf("invalid choice\n");
        }
    }
    while(ch<=4);
}


//function definition


void enq()
{
    int ele;
    if((front==-1)&&(rear==size-1))
    {
        printf("Queue is full!\n");
    }
    else
    {
       if(front==-1)
       {
        printf("enter element : \n");
        scanf("%d",&ele);
        rear++;
        Q[rear]=ele;
        printf("element inserted successfully!\n");
       }
       else
        printf("You cannot insert once an element is deleted!\n");
    }

}


void deq()
{
    if(front==rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        front++;
        printf("deleted element is %d",Q[front]);

    }

}

void display()
{

    int i;
    if(front==rear)
    {
        printf("no elements available!\n");
    }
    else
    {
         printf("Queue elements are :\n");
        for(i=front+1;i<=rear;i++)
        {
            printf("%d\t",Q[i]);
        }
    }
}
