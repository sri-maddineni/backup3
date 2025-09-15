
#include<stdio.h>

void main()
{
    int a[10],i,j,n,temp,k;
    printf("\n**Shell sort**");
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

    for(i=n/2;i>0;i--)
    {
        for(j=1;j<n;j++)
        {
            for(k=j-1;k>=0;k=k-i)
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

        printf("\nafter sorting elements are:  ");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);


}
