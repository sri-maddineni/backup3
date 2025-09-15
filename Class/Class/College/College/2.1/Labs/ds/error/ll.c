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
void count();
void rev();


struct node
{
    int data;
    struct node *next;
};

struct node* head=NULL;


void main()
{
    int ch;

    do
    {
        printf("\n1.create\n2.traverse\n3.exit\n4.insert at begin\n5.insert at end");
        printf("\n6.insert before an ele\n7.insert after an ele\n8.delete at begin\n9.del at end\n10.delete a node");
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
            case 4:insert_at_begin();
                    break;
            case 5:insert_at_end();
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
    int ele;
    char ch;
    struct node * ptr,*cptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter new node data");
    scanf("%d",&ele);
    ptr->data=ele;
    head=ptr;
    ptr->next=NULL;



    do
    {
        cptr=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter next node data");
        scanf("%d",&ele);

        cptr->data=ele;
        cptr->next=NULL;
        ptr->next=cptr;
        cptr->next=NULL;
        ptr=cptr;

        printf("\nYou want another node or not?(y or n )");
        ch=getch();
    }
    while(ch=='y'||ch=='Y');

}


void traverse()
{
    struct node* temp;
    temp=head;
    if(head==NULL)
        printf("\nLinked list empty,traverse not possible");
    else
        do
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        while(temp->next!=NULL);


    printf("%d",temp->data);

}



void insert_at_begin()
{
    int ele;
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data");
    scanf("%d",&ele);
    ptr->data=ele;

    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
    }

    else
    {
        ptr->next=head;
        head=ptr;
    }

}


void insert_at_end()
{
    int ele;
    struct node * ptr,*tmp1,*tmp2;
    ptr=(struct node*)malloc(sizeof(struct node ));
    printf("\nEnter node data");
    scanf("%d",&ele);
    ptr->data=ele;
    tmp1=head;

    while(tmp1->next!=NULL)
        {
            tmp1=tmp1->next;
            tmp2=tmp1;
        }


    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
    }
    else
    {
        ptr->next=NULL;
        tmp2->next=ptr;

    }
}

void insert_before()
{
    int ele;
    struct node *newnode,*temp1,*temp2;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter element to insert before");
    scanf("%d",&ele);
    temp1=head;


    while(temp1->data!=ele)
    {
        temp2=temp1;
        temp1=temp1->next;

    }

   if(temp1->data==ele)
   {
    printf("\nenter new node data");
    scanf("%d",&newnode->data);
    newnode->next=temp1;
    temp2->next=newnode;
   }
   else
   {
    printf("\nelement not found");
   }

}


void insert_after()
{
    int ele;
    printf("\nEnter element to insert after");
    scanf("%d",&ele);
    struct node *newnode,*temp1,*temp2;
    newnode=(struct node*)malloc(sizeof(struct node));

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
        printf("\nEnter new node data");
        scanf("%d",&newnode->data);
        newnode->next=temp1;
        temp2->next=newnode;
    }
    else
    {
        printf("\nElement not found");
    }

}


void del_begin()
{
    struct node*temp;
    temp=head;

    if(head==NULL)
    {
            printf("\nlist is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
    }
    else
    {
        head=temp->next;
    free(temp);
    }
}

void del_end()
{
    struct node *temp1,*temp2;
    temp1=head;

    if(head==NULL)
        printf("\nList is empty");
    else if(head->next==NULL)
        free(head);
    else
    {
        while(temp1->next==NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
    }
}

void del()
{
    int ele;
    struct node* temp1,*temp2;
    printf("\nenter element you want to delete");
    scanf("%d",&ele);
    temp1=head;


    while(temp1->data!=ele)
    {
        temp2=temp1;
        temp1=temp1->next;
    }

    temp2->next=temp1->next;
    free(temp1);


}

