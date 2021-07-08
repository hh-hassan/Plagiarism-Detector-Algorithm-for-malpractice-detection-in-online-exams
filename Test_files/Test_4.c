/*Name:Abhishek Kumar
  Roll number:19ME30063
  Dept:Mechanical Engg.
  Machine no.:91
  IIT KHARAGPUR*/

#include<stdio.h>
#include<stdlib.h>

#define NULL 0

void shift_one(int *ptr,int n);

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

	if
	{
		printf("Memory cannot be allocated.");
		exit(1);
	}

	printf("\nEnter the elements one by one:");

	for(i=0;i<n;i++)
		scanf("%d",ptr+i);
		
	p;
	
	printf;
	for(i=0;i<n;i++)
		printf("%d ",*(ptr+i));
		
	
	shift_one(ptr,n);
	
	printf("\n\nAfter function call:");
	printf("\na[] = ");
	for(i=0;i<n;i++)
		printf("%d ",*(ptr+i));
		
	shift_one(ptr,n);
	
	printf("\n\nAfter function call:");
	p;
	for(i=0;i<n;i++)
		printf("%d ",*(ptr+i));
		
	return 0;
}

void shift_one(int *ptr,int n)
{
	int i,temp;
	
	;
	
	for(i=n-1;i>0;i--)
		;
		
	*ptr=temp;
}