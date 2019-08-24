#include<stdio.h>
#define   SIZE	5

void swap(int &a, int &b)
{
	int temp= 0;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	int data[SIZE],i,j,temp;

	printf("\n ENTER THE ELEMENTS IN THE LIST : \n");
	for(i=0;i<SIZE;i++)
		scanf("%d",&data[i]);  //EX:10,4,6,2,3

	printf("\n THE SORTED LIST IS :\n");

	for(i=0;i<SIZE-1;i++)
		for(j=0;j<SIZE-i-1;j++)
			if(data[j]>data[j+1])
			{
			    swap(data[j],data[j+1]);
			}

	for(i=0;i<SIZE;i++)
	  printf("\t%d",data[i]);

}

//Time complexity: 
//	O(n^2) <-- worst case, when the array is reverse sorted
//	O(n) <-- best case, when the array is already sorted and the algorithm is modified
//	to stop running when the inner loop doesn't perform any swap.
//
//Space complexity:
//	O(1) <-- For iterative version
// 	O(n) <-- For resursive version

