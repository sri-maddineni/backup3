#include<stdio.h>
#include<stdlib.h>


void create();
void traverse();
void insert_at_begin();
void insert_at_end();
void insert_node_before();
void insert_node_after();
void del_at_begin();
void del_at_end();
void del();
void count();
void reverse();


struct node
{
 int data;
 struct node *next;
 struct node *prev;
};


struct node *Head=NULL;
struct node *ptr,*cptr;


void main()
{
    int ch;
  printf(" * Circular Double Linked List *");
 do
 {
  printf("\n\n1.create\n2.traverse\n3.insert at begin\n4.insert at end\n");
  printf("5.insert at before a node\n6.insert at after a node\n");
  printf("7.delete at begin\n8.delete at end\n9.delete at specific location\n");
  printf("10.no of nodes\n11.reverse of list\n12.exit\n\n");

  printf("Enter your choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: create();
           break;
   case 2: traverse();
            break;
   case 3: insert_at_begin();
            break;
   case 4: insert_at_end();
            break;
   case 5: insert_node_before();
           break;
   case 6: insert_node_after();
           break;
   case 7: del_at_begin();
           break;
   case 8: del_at_end();
           break;
   case 9: del();
           break;
   case 10: count();
            break;
   case 11: reverse();
            break;
   case 12: exit(0);
           break;
   default: printf("Invalid choice\n");
   }
 }
 while(ch<=12);
}



void create()
{
    char ch;
 ptr=(struct node *)malloc(sizeof(struct node));
 printf("Enter first node data : ");
 scanf("%d",&ptr->data);
 ptr->next=NULL;
 ptr->prev=NULL;
 Head=ptr;
 do
 {
      cptr=(struct node *)malloc(sizeof(struct node));
   printf("\nEnter next node data : ");
  scanf("%d",&cptr->data);
  cptr->next=NULL;
  cptr->prev=NULL;
  ptr->next=cptr;
  cptr->prev=ptr;
  ptr=cptr;
 printf("Do you want another node Y/N : ");
 ch=getche();
 }

 while(ch=='Y'||ch=='y');
 cptr->next=Head;
 Head->prev=cptr;
}



void traverse()
{
    struct node *temp;
  temp=Head;
 if(Head==NULL)
    printf("List is empty\n");
 else
 {
     printf("\nThe list elements are : ");
  while(temp->next!=Head)
  {
   printf("%d<->",temp->data);
   temp=temp->next;
  }
  printf("%d<->",temp->data);
 }
}


void insert_at_begin()
{
 struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter new node data : ");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 newnode->prev=NULL;
 if(Head==NULL)
{
    Head=newnode;
  newnode->next=Head;
  newnode->prev=Head;
}
 else
 {
     temp=Head;
  while(temp->next!=Head)
  {
      temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;
  Head->prev=newnode;
  newnode->next=Head;
  Head=newnode;
 }
 traverse();
}



void insert_at_end()
{
    struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter new node data : ");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 newnode->prev=NULL;
 if(Head==NULL)
 {
     Head=newnode;
    newnode->next=Head;
  newnode->prev=Head;
 }
 else
   {
    temp=Head;
    while(temp->next!=Head)
    {
     temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=Head;
    Head->prev=newnode;
   }
   traverse();
}



void insert_node_before()
{
    int ele;
  struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter new node data : ");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 newnode->prev=NULL;
 if(Head==NULL)
  { Head=newnode;
    newnode->next=Head;
    newnode->prev=Head;
  }
 else
 {
  temp=Head;
  printf("Where you want insert before of a node : ");
 scanf("%d",&ele);
  while(temp->data!=ele)
  {
   temp=temp->next;
  }
  temp->prev->next=newnode;
  newnode->prev=temp->prev;
  newnode->next=temp;
  temp->prev=newnode;
 }

 traverse();
}


void insert_node_after()
{
     int ele;
 struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter new node data : ");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 newnode->prev=NULL;
if(Head==NULL)
 {
     Head=newnode;
  newnode->next=Head;
  newnode->prev=Head;
 }
 else
 {
      temp=Head;
     printf("Where you want insert after a node : ");
    scanf("%d",&ele);
     while(temp->data!=ele)
     {
      temp=temp->next;
     }
     temp->next->prev=newnode;
     newnode->next=temp->next;
     newnode->prev=temp;
     temp->next=newnode;
 }
 traverse();
}



void del_at_begin()
{
    struct node *temp1,*temp2;
  temp2=Head;
  if(Head==NULL)
    printf("List is empty,deletion is not possible\n");
 else if(Head->next==Head)
 {
      Head=NULL;
  free(temp2);
 }
 else
 {
      temp1=Head;
  while(temp1->next!=Head)
  {
      temp1=temp1->next;
  }
  Head=temp2->next;
  temp2->next->prev=temp1;
  temp1->next=Head;
  free(temp2);
 }

 traverse();
}



void del_at_end()
{
    struct node *temp;
  temp=Head;
if(Head==NULL)
 printf("list is empty,deletion not possible\n");
  else if(Head->next==Head)
 {
     Head=NULL;
   free(temp);
 }
else
{
 while(temp->next!=Head)
 {
   temp=temp->next;
 }
 temp->prev->next=Head;
 Head->prev=temp->prev;
 free(temp);
}

traverse();
}



void del()
{
    int ele;
  struct node *temp;
 temp=Head;
 if(Head==NULL)
    printf("List is empty,deletion is not possible\n");
  else if(Head->next==Head)
 {
    Head=NULL;
  free(temp);
}
else
{
    printf("which one you want to delete : ");
 scanf("%d",&ele);
 while(temp->data!=ele)
 {
   temp=temp->next;
 }
 temp->prev->next=temp->next;
 temp->next->prev=temp->prev;
 free(temp);
}

traverse();
}



void count()
{
    int cnt=0;
    struct node *temp;
    temp=Head;
    if(Head==NULL)
    printf(" List is empty,no of nodes is 0\n");
    else
    {
     while(temp->next!=Head)
     {
      cnt++;
      temp=temp->next;
     }
     printf("no of nodes are %d",cnt+1);
    }
}



void reverse()
{
  struct node *temp;
  temp=Head;
  printf("reverse in double linked list\n");
  while(temp->next!=Head)
  {
      temp=temp->next;
  }
  while(temp!=Head)
  {
    printf("%d<->",temp->data);
    temp=temp->prev;
  }
  printf("%d<->",temp->data);

}

