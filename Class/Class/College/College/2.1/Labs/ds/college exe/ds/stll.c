#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push();
void pop();
void display();

void main()
{
    int ch;
    printf("\n**STACK USING LINKED LIST**");
    do
    {
        printf("\n1.Insert\n2.delete\n3.display\n4.exit");
        printf("\nEnter your choice : ");
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
            default:printf("\nInvalid choice");

        }
    }
    while(ch<=4);
}



void push()
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));


    if(ptr==NULL)
        printf("\nMemory full, cannot insert");
    else
    {
        printf("\nEnter element : ");
        scanf("%d",&ptr->data);
        ptr->next=NULL;
    }

    if(top==NULL)
        top=ptr;
    else
    {
        ptr->next=top;
        top=ptr;
    }
    printf("\nElement inserted successfully!");


}

void pop()
{
    struct node *temp=top;
    if(top==NULL)
        printf("\nStack empty!");
    else
    {
        printf("\nDeleted element is %d ",temp->data);
        top=top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
        printf("\nStack is empty!");
    else
    {
        printf("\nThe elements are : \n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
