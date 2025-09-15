#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void insert_at_begin();
void insert_at_end();
void insert_node_before();
void insert_node_after();
void delete_at_begin();
void delete_at_end();
void delete_at_specific();
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
{ int ch;
  printf(" * Circular Double Linked List *\n");
 do
 {
  printf("\n 1.create\n 2.traverse\n 3.insert at begin\n 4.insert at end\n 5.insert at before a node\n 6.insert at after a node\n 7.delete at begin\n 8.delete at end\n 9.delete at specific location\n 10.no of nodes\n 11.reverse of list\n 12.exit\n");
  printf("Enter your choice\n");
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
   case 7: delete_at_begin();
           break;
   case 8: delete_at_end();
           break;
   case 9: delete_at_specific();
           break;
   case 10: count();
            break;
   case 11: reverse();
            break;
   case 12: exit(0);
           break;
   default: printf("Invalid choice\n");
   }
 }while(ch<=12);
}
void create()
{ char ch;
 ptr=(struct node *)malloc(sizeof(struct node));
 printf("Enter first node data\n");
 scanf("%d",&ptr->data);
 ptr->next=NULL;
 ptr->prev=NULL;
 Head=ptr;
 do
 { cptr=(struct node *)malloc(sizeof(struct node));
   printf("\nEnter next node data\n");
  scanf("%d",&cptr->data);
  cptr->next=NULL;
  cptr->prev=NULL;
  ptr->next=cptr;
  cptr->prev=ptr;
  ptr=cptr;
 printf("Do you want another node Y/N\n");
 ch=getche();
 }while(ch=='Y'||ch=='y');
 cptr->next=Head;
 Head->prev=cptr;
}
void traverse()
{ struct node *temp;
  temp=Head;
 if(Head==NULL)
 printf("List is empty\n");
 else
 {  printf("The list elements are\n");
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
 printf("Enter new node data\n");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 newnode->prev=NULL;
 if(Head==NULL)
{ Head=newnode;
  newnode->next=Head;
  newnode->prev=Head;
}
 else
 {temp=Head;
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
}
void insert_at_end()
{ struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter new node data\n");
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
    while(temp->next!=Head)
    {
     temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=Head;
    Head->prev=newnode;
   }
}
void insert_node_before()
{ int ele;
  struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter new node data\n");
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
  printf("Where you want insert before of a node\n");
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
}
void insert_node_after()
{ int ele;
 struct node *newnode,*temp;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter new node data\n");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 newnode->prev=NULL;
if(Head==NULL)
 {Head=newnode;
  newnode->next=Head;
  newnode->prev=Head;
 }
 else
 {  temp=Head;
     printf("Where you want insert after a node\n");
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
}
void delete_at_begin()
{ struct node *temp1,*temp2;
  temp2=Head;
  if(Head==NULL)
 printf("List is empty,deletion is not possible\n");
 else if(Head->next==Head)
 { Head=NULL;
  free(temp2);
 }
 else
 { temp1=Head;
  while(temp1->next!=Head)
  {
      temp1=temp1->next;
  }
  Head=temp2->next;
  temp2->next->prev=temp1;
  temp1->next=Head;
  free(temp2);
 }
}
void delete_at_end()
{ struct node *temp;
  temp=Head;
if(Head==NULL)
 printf("list is empty,deletion not possible\n");
  else if(Head->next==Head)
 { Head=NULL;
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
}
void delete_at_specific()
{ int ele;
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
{ printf("where you want to delete\n");
 scanf("%d",&ele);
 while(temp->data!=ele)
 {
   temp=temp->next;
 }
 temp->prev->next=temp->next;
 temp->next->prev=temp->prev;
 free(temp);
}
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
     printf("no of nodes are %d\n",cnt+1);
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
