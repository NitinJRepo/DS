//Program for Sequential Search (linear search)
#include<stdio.h>

#define	  SIZE	5

int main(){
	int data[SIZE],key;
	int i,flag=0;

	printf("\n enter the elements of the list ");
	for(i=0;i<SIZE;i++)
		scanf("%d",&data[i]);

	printf("\n enter the element to be searched ");
	scanf("%d",&key);

	for(i=0;i<SIZE;i++)
	{
		if(key==data[i])
		{
			flag=1;
			break;
		}
	}

	if(flag==1)
		printf("\n element found in the list at %d position ",i);
	else
		printf("\n element not found in the list\n");

}
