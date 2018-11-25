#include"stdio.h"
#include"malloc.h"
typedef struct st_tag
{
	int data;
	struct st_tag *next;
}stktype;
enum{QUIT,INSERT,DELETE,DISPLAY};
int menu()
{
	int ch;
	puts("\n 0: QUIT");
	puts("\n 1: INSERT");
	puts("\n 2: DELETE");
	puts("\n 3: DISPLAY");
	puts("\n ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	return ch;
}
stktype *readdata()
{
	stktype *temp;
	temp=(stktype*)malloc(sizeof(stktype));

	if(temp==NULL)
	return NULL;

	else
	{
		printf("\n ENTER DATA: ");
		scanf("%d",&temp->data);
		temp->next=NULL;
		return temp;
	}
}

stktype *push(stktype *ptop)
{
	stktype *temp=readdata();
	if(temp==NULL)
	puts("\n MEMORY SPACE IS NOT AVAILABLE");
	else
	temp->next=ptop;
	return temp;
}

stktype *pop(stktype *ptop)
{
	stktype *temp=ptop;
	if(temp==NULL)
	printf("\n STACK IS EMPTY");
	else
	{
		printf("\n THE DELETED ELEMENT IS %d",ptop->data);
		ptop=ptop->next;
		free(temp);
	}
	return ptop;
}

void display(stktype *ptop)
{
	stktype *temp;
	temp=ptop;
	if(ptop==NULL)
	printf("\n THE STACK IS EMPTY");
	else
		 while(temp!=NULL)
		 {
			printf("\t %d ",temp->data);
			temp=temp->next;
		 }
}


int main()
{
	int ch;
	stktype *top;

	top = NULL;
	
	while(ch = menu())
	{
		switch(ch)
		{
			case INSERT:	
					top = push(top);
					break;
			case DELETE:	
					top = pop(top);
					break;
			case DISPLAY:   
					display(top);
					break;
			case QUIT:	
					return 0;

			default:        
				printf("\n INVALID CHOICE");
					break;
		}
	}
}

