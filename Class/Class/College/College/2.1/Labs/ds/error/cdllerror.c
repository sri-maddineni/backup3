#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void insert_begin();
void insert_end();
void insert_before();
void insert_after();
void del_begin();
void del_end();
void del();
void cnt();
void rev();




struct node
{
    int data;
    struct node * pre;
    struct node * next;

};

struct node  *head=NULL,*ptr,*cptr;

void main()
{
    int ch;
    printf("\n**CIRCULAR DOUBLE LINKED LIST**\n");
    do
    {

        printf("\n1.create\n2.traverse\n3.exit\n4.insert at begin\n5.insert at end\n6.insert node before\n7.insert node after");
        printf("\n8.del at begin\n9.del at end\n10.del a node\n11.count no of nodes\n12.reverser the list");
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create();
                    break;
            case 2:traverse();
                    break;
            case 3:exit(0);
                    break;
            case 4:insert_begin();
                    break;
            case 5:insert_end();
                    break;
            case 6:insert_before();
                    break;
            case 7:insert_after();
                    break;
            case 8:del_begin();
                    break;
            case 9:del_end();
                    break;
            case 10:del();
                    break;
            case 11:cnt();
                    break;
            case 12:rev();
                    break;
            default:printf("\nInvalid choice");

        }
    }
    while(ch<=12);
}


void create()
{
     char ch;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data : ");
    scanf("%d",&ptr->data);

    head=ptr;
    ptr->next=NULL;
    ptr->pre=NULL;
    head=ptr;

    do
    {
        cptr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter next node data : ");
        scanf("%d",&cptr->data);
        cptr->next=NULL;
        cptr->pre=NULL;
        ptr->next=cptr;
        cptr->next=head;
        ptr=cptr;

        printf("\nDo you want another node? ");
        ch=getche();

    }
    while(ch=='Y'||ch=='y');
}


void traverse()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nList is empty");
    else
    {
        printf("\n   The list is : ");
        while(temp->next!=head)
        {
            printf("%d<->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }

}

void insert_begin()
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->pre=NULL;

    printf("\nEnter node data : ");
    scanf("%d",&newnode->data);

    if(head==NULL)
    {
        newnode->next=head;
        newnode->pre=head;
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }

        newnode->next=head;
        temp->next=newnode;
        newnode->pre=temp;
        head->pre=newnode;
        head=newnode;

    }
}


void insert_end()
{

    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->pre=NULL;

    printf("\nEnter node data : ");
    scanf("%d",&newnode->data);

    if(head==NULL)
    {
        newnode->next=head;
        newnode->pre=head;
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }

        newnode->next=head;
        temp->next=newnode;
        newnode->pre=temp;
        head->pre=newnode;

    }
}



///not working

void insert_before()
{
    int ele;
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->pre=NULL;
    printf("\nBefore which element you want to enter? ");
    scanf("%d",&ele);


    if(head==NULL)
    {
        printf("\nThe list is empty");
    }
    else
    {
        while(temp->data!=ele)
        {
            temp=temp->next;
        }

        if(temp->data==ele)
        {
            printf("\nEnter node data : ");
            scanf("%d",&newnode->data);

            temp->pre->next=newnode;
            newnode->pre=temp->pre;
            newnode->next=temp;
            temp->pre=newnode;
        }
        else
            printf("\nElement not found!");
    }

}

void insert_after()
{
    int ele;
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->pre=NULL;
    newnode->next=NULL;
    printf("\nAfter which element you want to enter? ");
    scanf("%d",&ele);

    if(head==NULL)
        printf("\nList is empty");
    else
    {
        while(temp->data!=ele)
        {
            temp=temp->next;
        }
        if(temp->data==ele)
        {
            printf("\nEnter node data : ");
            scanf("%d",&newnode->data);
            newnode->next=temp->next;
            newnode->pre=temp;
            temp->next=newnode;
            temp->next->pre=newnode;

        }
        else
            printf("\nElement not found");
    }
}


void del_begin()
{
    struct node *temp1,*temp2;
    temp2=head;

    if(head==NULL)
        printf("\nDeletion not possible");
    else if(head->next==head)
    {
        head=NULL;
        free(temp2);
    }
    else
    {
        temp1=head;
        while(temp1->next!=head)
            temp1=temp1->next;
        head=temp2->next;
        temp2->next->pre=temp1;
        temp1->next=head;
        free(temp2);
    }
}

///not working


void del_end()
{
    struct node *temp;
    temp=head;

    if(head==NULL)
        printf("\nList empty,deletion not possible");
    else if(head->next==head)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=head)
            temp=temp->next;
        temp->pre->next=temp->next;
        head->pre=temp->pre;
        free(temp);

    }
}



///not working

void del()
{
    int ele;
    struct node *temp;
    temp=head;
    printf("\nWhich element you want to delete? ");
        scanf("%d",&ele);
    if(head==NULL)
        printf("\nList is empty,deletion not possible");
    else
    {

        while(temp->data!=ele)
            temp=temp->next;
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        free(temp);
    }


}

void cnt()
{
    struct node *temp;
    temp=head;
    int count=1;
    while(temp->next!=head)
    {
        temp=temp->next;
        count++;
    }
    printf("\nNo of nodes in list are : %d",count);
}


///not working


void rev()
{
    struct node *temp;
    temp=head;

    printf("\nReverse of list is : ");

    while(temp->next!=head)
        temp=temp->next;
    while(temp!=head)
    {
        printf("%d<->",temp->data);
        printf("\n%d",temp->pre->data);
        temp=temp->pre;
    }
    printf("%d",temp->data);
}

