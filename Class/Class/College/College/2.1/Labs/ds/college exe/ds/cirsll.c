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
};

struct node *Head=NULL;
struct node *ptr,*cptr;


void main()
{
    int ch;
    printf(" **Circular Single Linked List**\n");
 do
 {
  printf("\n 1.create\n 2.traverse\n 3.insert at begin\n 4.insert at end\n 5.insert at before a node");
  printf("\n 6.insert at after a node\n 7.delete at begin\n 8.delete at end");
  printf("\n 9.delete at specific location\n 10.no of nodes\n 11.reverse of list\n 12.exit\n");

  printf("\nEnter your choice : ");
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
 }while(ch<=12);
}


void create()
{
    char ch;
  ptr=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter first node data : ");
  scanf("%d",&ptr->data);
  ptr->next=NULL;
  Head=ptr;
  do
  {
      cptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter next node data : ");
    scanf("%d",&cptr->data);
    cptr->next=NULL;
    ptr->next=cptr;
    ptr=cptr;
    printf("Do you want another node Y/N  :");
    ch=getche();
  }

  while(ch=='Y'||ch=='y');
  cptr->next=Head;
}


 void traverse()
 {
     struct node *temp;
    temp=Head;
    if(Head==NULL)
        printf("List is empty\n");
    else
    {
        printf("The list elements are\n");
      while(temp->next!=Head)
      {
          printf("%d->",temp->data);
          temp=temp->next;
      }
        printf("%d",temp->data);
    }
}


void insert_at_begin()
{
    struct node *newnode,*temp;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter new node data : ");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(Head==NULL)
  {
      Head=newnode;
     newnode->next=Head;
  }
    else
    {
        temp=Head;
      while(temp->next!=Head)
      {
          temp=temp->next;
      }
       newnode->next=Head;
       Head=newnode;
       temp->next=Head;
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
  if(Head==NULL)
  {
      Head=newnode;
    newnode->next=Head;
  }
   else
   {
        temp=Head;
     while(temp->next!=Head)
     {
         temp=temp->next;
     }
       temp->next=newnode;
       newnode->next=Head;
   }

   traverse();
}



 void insert_node_before()
 {
       int ele;
       struct node *newnode,*temp1,*temp2;
       newnode=(struct node *)malloc(sizeof(struct node));
       printf("Enter new node data : ");
       scanf("%d",&newnode->data);
       newnode->next=NULL;
       if(Head==NULL)
       {
            Head=newnode;
            newnode->next=Head;
       }
       else
       {
            temp2=Head;
             printf("Where you want to insert before of a node : ");
             scanf("%d",&ele);
             while(temp2->data!=ele)
             {
                 temp1=temp2;
                temp2=temp2->next;
             }
               temp1->next=newnode;
               newnode->next=temp2;
       }

       traverse();
}



void insert_node_after()
{
    int ele;
  struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter new node data\n");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(Head==NULL)
  {
        Head=newnode;
        newnode->next=Head;
  }
    else
    {
         temp=Head;
      printf("Where you want to insert after a node : ");
      scanf("%d",&ele);
      while(temp->data!=ele)
      {
          temp=temp->next;
      }
        newnode->next=temp->next;
        temp->next=newnode;
    }

    traverse();
}



void delete_at_begin()
 {
      struct node *temp1,*temp2;
    temp1=Head;
   if(Head==NULL)
     printf("List is empty,deletion is not possible\n");
   else if(Head->next==Head)
   {
       Head=NULL;
     free(temp1);
   }
   else
   {
       temp2=Head;
     while(temp2->next!=Head)
     {
       temp2=temp2->next;
     }
     Head=temp1->next;
     temp2->next=Head;
     free(temp1);
   }
   traverse();
}



 void delete_at_end()
  {
      struct node *temp1,*temp2;
    temp2=Head;
   if(Head==NULL)
     printf("list is empty,deletion is not possible\n");
   else if(Head->next==Head)
   {
       Head=NULL;
     free(temp2);
   }
   else
    {
        while(temp2->next!=Head)
       {
           temp1=temp2;
           temp2=temp2->next;
       }

       temp1->next=Head;
       free(temp2);
    }

    traverse();
  }



  void del()
  {
      struct node*temp2,*temp1;
    int ele;
    temp2=Head;
    if(Head==NULL)
      printf("list is empty,Deletion is not possible\n");
    else if(Head->next==Head)
    {
        Head=NULL;
      free(temp2);
    }
    else
    {
         printf("Which node you want to delete\n");
      scanf("%d",&ele);
      while(temp2->data!=ele)
      {
          temp1=temp2;
         temp2=temp2->next;
      }
       temp1->next=temp2->next;
       free(temp2);
    }

    traverse();
  }



  void count()
  {
      struct node*temp;
    int cnt=0;
    temp=Head;
    if(Head==NULL)
        printf("List is empty,No. of nodes is 0\n");
    else
    {
        while(temp->next!=Head)
      {
           cnt++;
         temp=temp->next;
      }
    }
    printf("No. of nodes in Circular Single Linked List is %d\n",cnt+1);


  }



void reverse()
{
    struct node *temp1,*temp2;
   temp2=Head;
    if(Head==NULL)
       printf("List is empty \n");
       else
       {
           while(temp2->next!=Head)
         {
             temp1=temp2;
           temp2=temp2->next;
         }
         if(Head->next!=Head)
         {
              printf("%d->",temp2->data);
           temp1->next=Head;
           reverse();
         }
         else
            printf("%d->",temp2->data);
       }
}
