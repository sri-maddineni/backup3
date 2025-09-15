#include<stdio.h>
#include<stdlib.h>

#define size 5

int stack[size],top=-1;

void push();
void pop();
void display();


void main()
{

    int ch;
    printf("\n**STACK USING ARRAY**");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
            default:printf("\nInvalid choice");

        }

    }
    while(1);


}


void push()
{
    int n;
    if(top==size-1)
    {
        printf("\nStack overflow");
    }
    else
    {
        printf("\nEnter element :");
        scanf("%d",&n);
        top++;
        stack[top]=n;
        printf("\nelement inserted successfully");
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack underflow");
    }
    else
    {
       printf("deleted element is %d",stack[top]);
       top--;
       printf("\nelement deleted successfully!");
    }
}

void display()
{
    int i;
    if(top!=-1)
    {
        printf("\nelements in stack are :\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
