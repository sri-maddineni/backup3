#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define size 5

float stack[size];
int top=-1;

void main()
{
    int i;
    char str[15];
    float x,y;
    printf("Enter a valid postfix expression\n");
    scanf("%s",str);


    for(i=0;str[i]!='\0';i++)
    {
        switch(str[i])
        {
            case '+':x=stack[top];
                     y=stack[top-1];
                     x=y+x;
                     top--;
                     stack[top]=x;
                     break;
            case '-':x=stack[top];
                     y=stack[top-1];
                     x=y-x;
                     top--;
                     stack[top]=x;
                     break;
            case '*':x=stack[top];
                     y=stack[top-1];
                     x=y*x;
                     top--;
                     stack[top]=x;
                     break;
            case '/':x=stack[top];
                     y=stack[top-1];
                     x=y/x;
                     top--;
                     stack[top]=x;
                     break;
            case '^':x=stack[top];
                     y=stack[top-1];
                     x=pow(y,x);
                     top--;
                     stack[top]=x;
                     break;
            default:if(str[i]>=48&&str[i]<=57)
                    {
                        top++;
                        stack[top]=str[i]-48;
                    }
                    else
                    {
                        printf("Invalid expression\n");
                    }
        }

    }

     if(top==0)
        {
            printf("Result is %0.2f\n",stack[top]);
        }
        else
        {
            printf("invalid expression\n");
        }


}
