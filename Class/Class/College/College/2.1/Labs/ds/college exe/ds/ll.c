#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head=NULL;

void create();
void traverse();
void insert_at_begin();
void insert_at_end();
void insert_node_before();
void insert_node_after();
void del_at_begin();
void del_at_end();
void del();
void cnt();
void rev();





void main()
{
    int ch;
    printf(" **Linked list**\n");
    do
    {
        printf("\n1.create\n2.traverse\n3.exit\n4.insert at begin");
        printf("\n5.insert at end\n6.insert node before");
        printf("\n7.insert node after\n8.delete at begin\n9.delete at end");
        printf("\n10.delete\n11.count no of nodes\n12.reverse linked list\n");
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
            case 4:insert_at_begin();
                    break;
            case 5:insert_at_end();
                    break;
            case 6:insert_node_before();
                    break;
            case 7:insert_node_after();
                    break;
            case 8:del_at_begin();
                    break;
            case 9:del_at_end();
                    break;
            case 10:del();
                    break;
            case 11:cnt();
                    break;
            case 12:rev();
                    break;
            default:printf("\ninvalid choice");
        }
    }
    while(ch<=12);
}

void create()
{

    struct node *ptr,*cptr;
    char c;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter new node data : ");
    scanf("%d",&ptr->data);
    head=ptr;
    ptr->next=NULL;


    do
    {
        cptr=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter next node data : ");
        scanf("%d",&cptr->data);
        cptr->next=NULL;
        ptr->next=cptr;
        ptr=cptr;
        printf("\nyou want another node or not(y or n) ");
        c=getche();
    }
        while(c=='Y'||c=='y');



}



void traverse()
{
    struct node *temp1,*temp2;
    temp1=head;
    printf("\nThe list elements are : ");
    while(temp1->next!=NULL)
    {
        printf("%d->",temp1->data);
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("%d",temp1->data);
}



void insert_at_begin()
{
   struct node * newnode,*temp;
   newnode=(struct node *)malloc(sizeof(struct node));
   printf("\nEnter new node data: ");
   scanf("%d",&newnode->data);
   newnode->next=NULL;

   temp=head;
   if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=head;
        head=newnode;
    }

    traverse();

}



void insert_at_end()
{
    struct node* newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter new node data: ");
    scanf("%d",&newnode->data);

    newnode->next=NULL;
    temp=head;

    if(head==NULL)
        head=newnode;
    else
    {
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
    }
        traverse();
}


void insert_node_before()
{
    struct node* newnode,*temp1,*temp2;
    int ele;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nbefore which element you want to enter: ");
    scanf("%d",&ele);

    temp1=head;

    while(temp1->data!=ele)
    {
        temp2=temp1;
        temp1=temp1->next;
    }

    if(temp1->data==ele)
        {
            printf("\nEnter new node data : ");
            scanf("%d",&newnode->data);
            newnode->next=temp1;
            temp2->next=newnode;
        }
        else
            printf("\nElement not found!");

    traverse();
}

void insert_node_after()
{
    int ele;
    struct node* newnode,*temp1,*temp2;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nafter which element you want to enter: ");
    scanf("%d",&ele);
    newnode->next=NULL;
    temp1=head;

    while(temp1->data!=ele)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2=temp1;
    temp1=temp1->next;

    if(temp2->data==ele)
    {
        printf("\nEnter new node data: ");
        scanf("%d",&newnode->data);
        newnode->next=temp1;
        temp2->next=newnode;
    }
    else
        printf("\nElement not found!");

    traverse();

}


void del_at_begin()
{
    struct node *temp;
    temp=head;

    if(head==NULL)
        printf("\nLinked list empty,deletion not possible!");
    else if(head->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        head=temp->next;
        free(temp);
    }

    traverse();

}


void del_at_end()
{
    struct node *temp1,*temp2;
    temp1=head;

    if(head==NULL)
        printf("\nLinked list empty,deletion not possible!");
    else if(head->next==NULL)
    {
        head=NULL;
        free(temp1);
    }
    else
    {
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
    temp2->next=NULL;
    free(temp1);
    }

    traverse();
}


void del()
{
    struct node *temp1,*temp2;
    int ele;

    temp1=head;

    if(head==NULL)
        printf("\nLinked list empty,delete not possible!");
    else if(head->next==NULL)
    {
        head=NULL;
        free(temp1);
    }
    else
    {
        printf("\nEnter element you want to delete : ");
        scanf("%d",&ele);
        while(temp1->data!=ele)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1->data==ele)
        {
            temp2->next=temp1->next;
            free(temp1);
        }
        else
            printf("\nElement not found");

    }

    traverse();

}



void cnt()
{
    int count;
    if(head==NULL)
        count=0;
    else
        count=1;
    struct node *temp;

    temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }


    printf("\n No of nodes are: %d",count);
}


void rev()
{
    struct node *temp1,*temp2;

    temp1=head;

    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }

    if(head->next!=NULL)
    {
        printf("%d<-",temp1->data);
        temp2->next=NULL;
        free(temp1);
        rev();
    }
    else
        printf("%d",temp1->data);
}

