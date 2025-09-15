#include<stdio.h>

void main()
{
    int a[10],i,j,n,temp;
    printf("\n**Bubble sort**");
    printf("\nEnter no of elements you want to sort: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n before sorting elements are: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("\nElements after sorting are: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);


}
