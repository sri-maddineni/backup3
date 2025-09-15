#include<stdio.h>
#include<stdlib.h>

struct node
{
    int co;
    int ex;
    struct node *next;
};

struct node *ptr,*cptr,*head=NULL;

void create();
void traverse();

void main()
{
    char ch;
    printf("\n**POLYNOMIAL CREATION**\n");

    do
    {
        printf("\n1.create\n2.traverse\n3.exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                    break;
            case 2:traverse();
                    break;
            case 3:exit(0);
                    break;
            default:printf("\nInvalid choice");
        }
    }
    while(ch<=3);

}



void create()
{
    char ch;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter first node coefficient and exponent : ");
    scanf("%d%d",&ptr->co,&ptr->ex);

    ptr->next=NULL;
    head=ptr;

    do
    {
        cptr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter next node coefficient and exponent : ");
        scanf("%d%d",&cptr->co,&cptr->ex);
        cptr->next=NULL;
        ptr->next=cptr;
        ptr=cptr;

        printf("\nDo you want another term (y/n)? ");
        ch=getche();
    }
    while(ch=='Y'||ch=='y');



}

void traverse()
{
    struct node *temp;
    temp=head;
    printf("\nThe polynomial is : ");
    while(temp->next!=NULL)
    {
        printf("%dx^%d+",temp->co,temp->ex);
        temp=temp->next;

    }

    printf("%dx^%d",temp->co,temp->ex);

}
