#include "stdio.h"
#include "stdlib.h"

typedef struct D
{
	int data;
	struct D *next;
	struct D *prev;
}DLL;

enum{QUIT,INSERT,DELETE,DISPLAY,REVERSE};

int menu()
{       int ch;
	puts("\n\t0 : QUIT ");
	puts("\n\t1 : INSERT");
	puts("\n\t2 : DELET");
	puts("\n\t3 : DISPLAY");
	puts("\n\t4 : REVERSE DISPLAY");
	puts("\n\tENTER YOUR CHOICE :-> ");
	scanf("%d", &ch);
	return ch;
}

DLL* readdata()
{
	DLL *temp;
	temp=(DLL*) malloc (sizeof(DLL));
	if(temp==NULL)	return NULL;
	else
	{
		puts(" ENTER DATA :->");
		scanf("%d",&temp->data);
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
}

int imenu()
{
	int ch;
	puts("\n1: INSERT AT FIRST");
	puts("\n2: INSERT AT LAST");
	puts("\n3: INSERT AFTER SPECIFIC VALUE");
	scanf("%d",&ch);
	return ch;

}

DLL* addfirst(DLL *pstart)
{
	DLL *temp=readdata();
	if(temp == NULL )	puts("MEMORY IS NOT AVAUILABLE");
	temp->next=pstart;
	pstart->prev=temp;
	pstart=temp;

	return pstart;
}

DLL *addlast(DLL *pstart)
{
	DLL *temp=readdata();
	DLL *trav=pstart;
	if(temp==NULL)
	puts("\n MEMORY IS NOT AVAILABLE");
	if(pstart==NULL) 	return(addfirst(pstart));

	while(trav->next!=NULL)
       trav=trav->next;

       trav->next=temp;
       temp->prev=trav;
       return pstart;
}

DLL *addafter(DLL *pstart)
{
	int ch;
	DLL *temp=readdata();
	DLL *trav=pstart;
	if(temp==NULL)
	puts("\n MEMORY IS NOT AVAILABLE");
	puts("\n ENTER THE ELEMENT TO BE SEARCHED");
	scanf("%d",&ch);
	while(trav!=NULL)
	{
		if(trav->data==ch)
	       {	temp->next=trav->next;
				trav->next->prev=temp;
				trav->next=temp;
				temp->prev=trav;
				return pstart;
	       }
	       trav=trav->next;
	}
	puts("\n ELEMENT NOT FOUND");
	return pstart;
}

DLL *insert(DLL *pstart)
{
	int ch=imenu();
	switch(ch)
	{
		case 1:		return addfirst(pstart);
		case 2:		return addlast(pstart);
		case 3:		return addafter(pstart);
				
		default:
			puts("\n INVALID OPTION");
	}
}

int dmenu()
{
	int ch;
	puts(" 1 : DELETE FROM START\n");
	puts(" 2 : DELETE FROM END\n");
	puts(" 3 : DELETE ANY SPECIFICE VALUE\n");
	scanf("%d",&ch);
	return ch;
}

DLL *delfirst(DLL *pstart)
{
	DLL *temp=pstart;
	pstart=pstart->next;
	pstart->prev=NULL;
	free(temp);
	return pstart;
}

DLL *dellast(DLL *pstart)
{
	DLL *temp=pstart;
	DLL *trav;
	if(temp->next==NULL)		return(delfirst(pstart));
	while(trav->next!=NULL)
		trav=trav->next;
		temp=trav;
		trav->prev->next=NULL;
		free(temp);
		return pstart;
}

DLL *delspecific(DLL *pstart)
{
	int ch;
	DLL *temp=pstart;
	DLL *trav;
	puts(" ENTER ELEMENT TO BE DELETED :-> ");
	scanf("%d",&ch);
	if(temp->data==ch)		return (delfirst(pstart));

	while(trav!=NULL)
	{
		if(trav->data==ch)
		{
			trav->prev->next=trav->next;
			trav->next->prev=trav->prev;

			free(trav);
			return pstart;
		}
		trav=trav->next;
	}
	puts(" ELEMENT NOT FOUND IN LIST");
	return pstart;
}

DLL* delet(DLL* pstart)
{
	int ch=dmenu();
	if(pstart == NULL)	puts("LIST IS EMPTY ");
	else
	switch(ch)
	{
		case 1:     return delfirst(pstart);

		case 2:		return dellast(pstart);

		case 3:		return delspecific(pstart);

		default :	 puts(" INVALID OPTION ");
	}
}

void display( DLL *pstart)
{
	DLL *trav=pstart;
	if(pstart==NULL)
		printf(" LIST IS EMPTY ");
	else
		while( trav != NULL )
		{	printf("\t %d",trav->data);
			trav=trav->next;
		}
}

void reverseDisplay(DLL *pstart)
{
	DLL *temp=pstart;

	if(pstart==NULL)
	printf("\n LIST IS EMPTY");

	while(temp->next!=NULL)
	temp=temp->next;

	while(temp!=NULL)
	{
		printf("\t %d",temp->data);
		temp=temp->prev;
	}
}

int main()
{

	int ch;
	DLL *start;

	start=NULL;

	while(ch=menu())
	{
		switch(ch)
		{
			case INSERT:	
					start = insert(start);
					break;
			case DELETE:	
					start = delet(start);
					break;
			case DISPLAY:	
					display(start);
					break;
			case REVERSE:   reverseDisplay(start);
					break;
			case QUIT:	
					return 0;
			default:
					printf("\n INVALID OPTION");
					break;
		}
	}
}
