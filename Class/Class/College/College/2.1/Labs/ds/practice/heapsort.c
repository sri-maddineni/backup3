#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void heapsort();
void insert(int num,int loc);
void del(int last);

int a[20];

void display()
{

    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}


void main()
{
    int i,n;
    printf("\nEnter no of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("\nThe list is: ");
    display();

    create();
    printf("\nThe heap is : ");
    display();

    heapsort();

}
