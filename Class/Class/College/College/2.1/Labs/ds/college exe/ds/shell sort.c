#include<stdio.h>

void main()
{
    int a[10],i,j,n,temp,k;
    printf("**shell sort**\n");
    printf("Enter no of elements to be sorted:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n Before sorting");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);

    for(i=n/2;i>0;i--)
    {
        for(j=i;j<n;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if(a[k]>a[k+1])
                {
                    temp=a[k];
                    a[k]=a[k+1];
                    a[k+1]=temp;
                }
                else
                    break;

            }
        }

    }

        printf("\nAfter sorting elements are:  ");
        for(i=0;i<n;i++)
            printf("\t%d",a[i]);


}
