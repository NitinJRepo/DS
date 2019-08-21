#include"stdio.h"

void read( int data[] , int n )
{
	int i;
	puts(" Enter value for elements (in sorted order) :-> ");
	for( i=0;  i<n;  i++)
		scanf("%d",&data[i]);
}

void display(int data[] , int n )
{
	int i;
	for(  i=0;  i<n;  i++)
		printf("\ndata[%d] = %d ",i,data[i]);
}

void binary(int data[] , int n)
{
	int search,i,min=0,mid,max=n-1;
	puts(" ENTER THE ELEMENT TO BE SERCH :->");
	scanf("%d",&search);

	do
	{
		mid=(max+min)/2;

		if(data[mid] == search)
		{	printf("ELEMENT FOUND AT %d \n",mid);
			return;
		}
		else if(data[mid] > search)	max=mid-1;
		else				min=mid+1;
	} while(max>=min);

	printf("ELEMENT NOT FOUND IN LIST \n");
}

int main()
{
	int n,data[10],i;

	puts(" Enter no of elements :-> ");
	scanf("%d",&n);
	read(data,n);
	display( data,n );

	binary( data,n);
}
