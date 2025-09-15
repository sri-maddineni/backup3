#include<stdio.h>


void main()
{
    int a[10],i,j,temp,n;
    printf("\n**Selection sort**");
    printf("\nenter how many elements you want to sort : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nenter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nelements before sorting are :");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }

     printf("\nelements after sorting are :");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
