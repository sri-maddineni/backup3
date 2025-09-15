#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
struct node *head=NULL,*ptr,*cptr;
void create();
void traverse();

void main()
{
    int ch;
    printf("\n ** Polynomial Creation Using SLL **");
    do
    {
        printf("\n1.Create\n2.Traverse\n3.Exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                   break;
            case 2:traverse();
                   break;
            case 3:exit(0);
                   break;
            default :printf("\n invalid choice");

        }
    }while(ch<=3);

}
void create()
{
    char ch;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\n Enter first term coeff & exp ");
    scanf("%d%d",&ptr->coeff,&ptr->exp);
    ptr->next=NULL;
    head=ptr;
do
{
   cptr=(struct node *)malloc(sizeof(struct node));
   printf("\n Enter next term coeff & exp ");
   scanf("%d%d",&cptr->coeff,&cptr->exp);
   cptr->next=NULL;
   ptr->next=cptr;
   ptr=cptr;
   printf("\nDo you want another node Y/N ");
   ch=getche();
}
while(ch=='Y'||ch=='y');
}
void traverse()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("\n There are no terms");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("  %d x^%d +",temp->coeff,temp->exp);
            temp=temp->next;
        }
    }
}

