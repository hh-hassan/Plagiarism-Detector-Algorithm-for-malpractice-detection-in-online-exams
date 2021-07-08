/*Name:Subir Gupta
  Roll number:19EE10059
  Dept:Electrical Engg.
  Machine no.:91
  IIT KHARAGPUR*/

#include<stdio.h>
#include<stdlib.h>

#define NULL 0

void;

int main()
{

	int i,n,*ptr;

	printf("Enter the number of elements:");
	scanf("%d",&n);
	
	if(n<1)
	{
		printf("\nInvalid input.");
		
		return 0;
	}

	if((ptr=(int*)malloc(n*sizeof(int)))==NULL)
	{
		printf("Memory cannot be allocated.");
		exit(1);
	}

	printf("\nEnter the elements one by one:");

	for(i=0;i<n;i++)
		scanf("%d",ptr+i);
		
	printf("\nSize of a[] = %d",n*sizeof(int));
	
	printf("\n\na[] = ");
	for(i=0;i<n;i++)
		printf("%d ",*(ptr+i));
		
	
	shift_one(ptr,n);
	
	printf("\n\nAfter function call:");
	printf("\na[] = ");
	for(i=0;i<n;i++)
		printf("%d ",*(ptr+i));
		
	shift_one(ptr,n);
	
	printf("\n\nAfter function call:");
	printf("\na[] = ");
	for(i=0;i<n;i++)
		printf("%d ",*(ptr+i));
		
	return 0;
}

void shift_one(int *ptr,int n)
{
	int i,temp;
	
	temp=*(ptr+n-1);
	
	for(i=n-1;i>0;i--)
		*(ptr+i)=*(ptr+i-1);
		
	*ptr=temp;
}