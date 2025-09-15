#include<stdio.h>
#include<conio.h>
#define size 20


int prec(char op);
void infix(char str[20]);

char stack[size];
char post[20];

int top=-1;
int j=0,i=0,k;
int cr,st;


void main()
{
    char str[20];
    printf("\n enter infix expression : ");
    scanf("%s",str);
    infix(str);
    getch();
}


void infix(char str[20])
{
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
        {
            top++;
            stack[top]=str[i];
        }
        else if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'||str[i]>='0'&&str[i]<='9')
        {
            post[j]=str[i];
            j++;
        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
        {
            cr=prec(str[i]);
            st=prec(stack[top]);
        if(top==-1)
        {
            top++;
            stack[top]=str[i];
        }
        else
        {
            while(cr<=st)
            {
                post[j]=stack[top];
                j++;
                top--;
                st=prec(stack[top]);
            }
        top++;
        stack[top]=str[i];
        }
    }
    else if(str[i]==')')
    {
        while(stack[top]!='(')
        {
            post[j]=stack[top];
            j++;
            top--;
        }
    top--;
    }
    else
    {
        printf("\n invalid expression");
    }
}

    for(k=top;k>=0;k--)
    {
        post[j]=stack[k];
        j++;
    }
    printf("\n postfix expression is %s",post);
}


int prec(char op)
{
    if(op=='+'||op=='-')
        return 1;
    else if(op=='*'||op=='/')
        return 2;
    else if(op=='^')
        return 3;
    else
        return 0;
}
