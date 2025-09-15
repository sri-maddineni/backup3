#include<stdio.h>
#include<stdlib.h>


#define size 20


int prec(char op);
void infix(char str[20]);
int stack[size],top=-1;
char post[20];

int i=0,j=0,k;
int cr,st;

void main()
{
    char str[20];
    printf("Enter infix expression\n");
    scanf("%s",str);
    infix(str);

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
                    top--;
                    j++;
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
            printf("invalid expression\n");
    }
//heart of the program
    for(k=0;k>=top;k--)
    {
        post[j]=stack[k];
        printf("\n%s",stack[k]);
        j++;
    }
    printf("postfix expression is %s",post);
}


int prec(char op)
{
    if(op=='^')
        return 3;
    else if(op=='*'||op=='/')
        return 2;
    else if(op=='+'||op=='-')
        return 1;
    else
        return 0;
}








