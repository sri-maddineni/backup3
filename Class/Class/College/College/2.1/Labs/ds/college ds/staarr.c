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
    do
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit");
        printf("\nEnter your choice ");
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
    while(ch<=4);
}



void push()
{
    int ele;

    if(top==size-1)
        printf("\nstack overflow,cannot insert element");
    else
    {
        printf("\nenter element you want to insert ");
        scanf("%d",&ele);
        top++;
        stack[top]=ele;
        printf("\nelement inserted successfully!");
    }
}

void pop()
{
    if(top==-1)
        printf("\nstack underflow, cannot delete");
    else
    {
        printf("\ndeleted element is %d :",stack[top]);
        top--;
    }
}


void display()
{
    int i;
    if(top!=-1)
    {
        printf("\nstack elements are: ");
        for(i=top;i>=0;i--)
            printf("%d\t",stack[i]);
    }
    else
        printf("\nstack empty");
}
