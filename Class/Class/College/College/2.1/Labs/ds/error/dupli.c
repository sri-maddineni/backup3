#include<stdio.h>
void main()
{
 int a[10],i,j,temp,n,k;
 printf("\nenter n value");
 scanf("%d",&n);
 printf("\nEnter elements are");
 for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
 printf("\nBefore sorting");
 for(i=0;i<n;i++)
 {
 printf("\t%d",a[i]);
 }
 for(i=n/2;i>0;i--)
 {
 for(j=1;j<n;j++)
 {
 for(k=j-1;k>=0;k=k-i)
 {
 if(a[k+1]>=a[k])
 break;
 else
 {
 temp=a[k];
 a[k]=a[k+i];
 a[k+i]=temp;
 }
 }
 }
  }
 printf("\nAfter sorting");
 for(i=0;i<n;i++)
 {
 printf("\t%d",a[i]);
 }
 }
