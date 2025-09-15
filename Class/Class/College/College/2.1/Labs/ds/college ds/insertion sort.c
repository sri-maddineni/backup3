
#include<stdio.h>

void main()
{
    int a[10],i,j,n,temp;
    printf("\n**Insertion sort**");
    printf("\nEnter no of elements you want to sort: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n Before sorting elements are: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&temp<=a[j])
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;

    }

   printf("\nafter elements sorting are: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
