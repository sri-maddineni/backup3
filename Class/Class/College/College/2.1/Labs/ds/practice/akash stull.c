#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void push();
void pop();
void display();
struct node
{
    int data;
    struct node*next;
};
struct node*top=NULL,*ptr;
void main()
{
    int ch;
    printf("\n stack using linked list");
    do
    {
        printf("\n 1.push\n2.pop\n3.display\n4.exit");
        printf("\n enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
           default:printf("\n invalid choice");
        }

        }while(ch<=4);
    }
void push()
{
  ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
{
    printf("\n memory is full");
} else
printf("\n which element do you want to insert");
scanf("\n %d",&ptr->data);
ptr->next=NULL;
if (top==NULL)
{
    top=ptr;
}else
{
    ptr->next=top;
    top=ptr;
}
}
void pop()
{
    struct node*temp;
    temp=top;
    if(top==NULL)
    {
        printf("\n stack is empty,deletion is not possible");
    }else
    {
        printf("\n deleted element is %d",top->data);
        top=top->next;
        free(temp);
    }
}
void display()
{
    struct node*temp;
    temp=top;
    if (top==NULL)
    {

        printf("\n stack is empty you cannot insert");
    }else
    printf("\n stack elements are");
    while(temp!=NULL)
    {
        printf("\n %d",temp->data);
        temp=temp->next;
    }
}
