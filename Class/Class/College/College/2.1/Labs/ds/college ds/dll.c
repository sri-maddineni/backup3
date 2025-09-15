#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void insert_at_begin();
void insert_at_end();
void insert_before();
void insert_after();
void del_begin();
void del_end();
void del();



struct node
{

    int data;
    struct node *pre;
    struct node *next;

};

struct node *head=NULL,*ptr,*cptr;

void main()
{

    int ch;
    printf("**DOUBLE LINKED LIST**\n");
    do
    {
        printf("\n1.create\n2.traverse\n3.insert at begin\n4.insert at end\n5.Exit\n6.Insert node before\n");
        printf("7.Insert node after\n8.delete at begin\n9.delete at end\n10.del a node");
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create();
                    break;
            case 2:traverse();
                    break;
            case 3:insert_at_begin();
                    break;
            case 4:insert_at_end();
                    break;
            case 5:exit(0);
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
            default:printf("\nInvalid choice");

        }
    }
    while(ch<=10);

}


void create()
{

    char c;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter new node data :");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    ptr->pre=NULL;
    head=ptr;

    do
    {
        cptr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter next node data: ");
        scanf("%d",&cptr->data);
        printf("\nYou want another node or not?");
        c=getche();
        cptr->next=NULL;
        cptr->pre=ptr;
        ptr->next=cptr;

        ptr=cptr;
    }
    while(c=='Y'||c=='y');

}


void traverse()
{

    struct node * temp;
    if(head==NULL)
    {
        printf("\nList empty");

    }
    else
    {
        temp=head;
        printf("\nThe list is: ");
        while(temp!=NULL)
        {
            printf("%d<->",temp->data);
            temp=temp->next;
        }
    }

}


void insert_at_begin()
{

    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->pre=NULL;

    if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=head;
        head->pre=newnode;
        head=newnode;
    }


}



void insert_at_end()
{

    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->pre=NULL;

    if(head==NULL)
        head=newnode;
    else if(head->next==NULL)
    {
        head->next=newnode;
        newnode->pre=head;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        newnode->pre=temp;
        temp->next=newnode;
    }


}


void insert_before()
{

    int ele;
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nBefore which element you want to insert? ");
    scanf("%d",&ele);
    newnode->next=NULL;
    newnode->pre=NULL;
    temp=head;

    while(temp->data!=ele)
    {
        temp=temp->next;
    }

    if(temp->data==ele)
    {
        printf("\nEnter node data : ");
        scanf("%d",&newnode->data);

        if(temp!=head)
        {

        newnode->next=temp;
        newnode->pre=temp->pre;
        temp->pre->next=newnode;
        temp->pre=newnode;
        }
        else
        {
            newnode->next=temp;
            newnode->pre=NULL;
            temp->pre=newnode;
            head=newnode;
        }
    }
    else
        {
            printf("\nElement not found!");
        }

}


void insert_after()
{
    int ele;
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    temp=head;
    newnode->pre=NULL;
    newnode->next=NULL;

    printf("\nAfter which element you want to enter? ");
    scanf("%d",&ele);

    while(temp->data!=ele)
        temp=temp->next;

    if(temp->data==ele)
    {
        printf("\nEnter node data : ");
        scanf("%d",&newnode->data);
        newnode->pre=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->pre=newnode;
    }
    else
        printf("\nElement not found");


}


void del_begin()
{
    if(head==NULL)
        printf("\nList is empty");
    struct node *temp;
    temp=head;
    temp->next->pre=NULL;
    head=temp->next;
    free(temp);

}

void del_end()
{

    struct node* temp;
    temp=head;
    if(head==NULL)
        printf("\nList is empty");
    else
    {
        while(temp->next!=NULL)
        temp=temp->next;

        temp->pre->next=NULL;
        free(temp);

    }
}

void del()
{
    int ele;
    struct node*temp;
    temp=head;


    printf("\nWhich node you want to delete? ");
    scanf("%d",&ele);

    while(temp->data!=ele)
        temp=temp->next;

    if(temp->data==ele)
    {
        if(temp==head)
        {
            temp->next->pre=NULL;
            head=temp->next;
            free(temp);
        }
        else if(temp->next==NULL)
        {
            temp->pre->next=NULL;
            free(temp);
        }
        else
        {
            temp->pre->next=temp->next;
            temp->next->pre=temp->pre;
            free(temp);
        }

    }
    else
        printf("\nElement not found");


}

void rev()
{

}
