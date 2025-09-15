#include<stdio.h>
#include<stdlib.h>


struct node
{
    int co;
    int ex;
    struct node *next;

};


struct node *head=NULL,*poly1=NULL,*poly2=NULL,*sum=NULL,*ptr,*cptr;

void create();
void traverse(struct node*);
void add(struct node *,struct node *);

void main()
{
    int ch;
    printf("\n*POLYNOMIAL ADDITION*\n");
    printf("\nEnter first polynomial details: ");
    create();
    poly1=head;
    printf("\nEnter second polynomial details: ");
    create();
    poly2=head;
    printf("\nFirst polynomial is :");
    traverse(poly1);
    printf("\nSecond polynomial is :");
    traverse(poly2);
    printf("\nAddition of polynomials is :");
    add(poly1,poly2);
    traverse(sum);


}

void create()
{
    char ch;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter first term coefficient and exponent : ");
    scanf("%d%d",&ptr->co,&ptr->ex);
    ptr->next=NULL;
    head=ptr;

    do
    {
        cptr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter next term coefficient and exponent : ");
        scanf("%d%d",&cptr->co,&cptr->ex);
        cptr->next=NULL;
        ptr->next=cptr;
        ptr=cptr;
        printf("\nDo you want to insert another term ");
        ch=getche();
    }
    while(ch=='Y'||ch=='y');
}



void traverse(struct node * poly)
{
    struct node *temp;
    temp=poly;
    while(temp->next!=NULL)
    {
        printf("%dx^%d + ",temp->co,temp->ex);
        temp=temp->next;

    }

    printf("%dx^%d",temp->co,temp->ex);

}



void add(struct node * poly1,struct node * poly2)
{
    ptr=(struct node *)malloc(sizeof(struct node));

    if(poly1->ex > poly2->ex)
    {
        ptr->co=poly1->co;
        ptr->ex=poly1->ex;
        poly1=poly1->next;
    }
    else if(poly2->ex > poly1->ex)
    {
        ptr->co=poly1->co;
        ptr->ex=poly1->ex;
        poly2=poly2->next;
    }
    else
    {
        ptr->co=poly1->co+poly2->co;
        ptr->ex=poly1->ex;
        poly1=poly1->next;
        poly2=poly2->next;
    }
    sum=ptr;

    while(poly1!=NULL&&poly2!=NULL)
    {
        cptr=(struct node*)malloc(sizeof(struct node));

        if(poly1->ex > poly2->ex)
        {
            cptr->co=poly1->co;
            cptr->ex=poly1->ex;
            poly1=poly1->next;
        }
        else if(poly2->ex > poly1->ex)
        {
            cptr->co=poly2->co;
            cptr->ex=poly2->ex;
            poly2=poly2->next;

        }
        else
        {
            cptr->co=poly1->co+poly2->co;
            cptr->ex=poly1->ex;
            poly1=poly1->next;
            poly2=poly2->next;
        }

        ptr->next=cptr;
        ptr=cptr;
    }

    while(poly1!=NULL)

    {
        struct node *cptr;
        cptr=(struct node *)malloc(sizeof(struct node));

        cptr->co=poly1->co;
        cptr->ex=poly1->ex;

        ptr->next=cptr;
        ptr=cptr;

        poly1=poly1->next;
    }

    while(poly2!=NULL)
    {
        struct node *cptr;
        cptr=(struct node *)malloc(sizeof(struct node));

        cptr->co=poly2->co;
        cptr->ex=poly2->ex;
        ptr->next=cptr;
        ptr=cptr;
        poly2=poly2->next;
    }

}
