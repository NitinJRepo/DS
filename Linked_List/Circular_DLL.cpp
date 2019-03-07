#include "stdio.h"
#include "stdlib.h"

typedef struct D
{
	int data;
	struct D *next;
	struct D *prev;
}CDLL;

enum{QUIT,INSERT,DELETE,DISPLAY};

int menu()
{       int ch;
	puts("\n\t0 : QUIT ");
	puts("\n\t1 : INSERT");
	puts("\n\t2 : DELET");
	puts("\n\t3 : DISPLAY");
	puts("\n\tENTER YOUR CHOICE :-> ");
	scanf("%d", &ch);
	return ch;
}

CDLL* readdata()
{
	CDLL *temp;
	temp=(CDLL*) malloc (sizeof(CDLL));
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

CDLL* addfirst(CDLL *pstart)
{
	CDLL *temp=readdata();
	if(temp == NULL )	puts("MEMORY IS NOT AVAUILABLE");
	if(pstart==NULL)
	{
	   temp->next=temp->prev=temp;
	   return temp;
	}
	else{
	temp->next=pstart;
	temp->prev=pstart->prev;
	pstart->prev->next=temp;
	pstart->prev=temp;
	return temp;
	}
}

CDLL *addlast(CDLL *pstart)
{
	CDLL *temp=readdata();
	CDLL *trav=pstart;
	if(temp==NULL)
	puts("\n MEMORY IS NOT AVAILABLE");
	if(pstart==NULL) 	return(addfirst(pstart));
	else{

		 trav=pstart->prev;

		 temp->next=pstart;
		 pstart->prev=temp;
		 temp->prev=trav;
		 trav->next=temp;

		 return pstart;
	    }
}

CDLL *addafter(CDLL *pstart)
{
	int ch;
	CDLL *temp=readdata();
	CDLL *trav=pstart;
	if(temp==NULL)
	puts("\n MEMORY IS NOT AVAILABLE");
	puts("\n ENTER THE ELEMENT TO BE SEARCHED");
	scanf("%d",&ch);
	do{
		if(trav->data==ch)
		{
			temp->next=trav->next;
			trav->next->prev=temp;
			temp->prev=trav;
			trav->next=temp;
			return pstart;
		}
		trav=trav->next;
	}while(trav!=pstart);

	puts("\n ELEMENT NOT FOUND");
	return pstart;
}

CDLL *insert(CDLL *pstart)
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

CDLL *delfirst(CDLL *pstart)
{
	CDLL *temp=pstart;
	pstart=pstart->next;
	pstart->prev=temp->prev;
	temp->prev->next=pstart;
	free(temp);
	return pstart;
}

CDLL *dellast(CDLL *pstart)
{
	CDLL *temp=pstart;

	if(temp->next==pstart)		return(delfirst(pstart));
	temp=pstart->prev;
	pstart->prev=temp->prev;
	temp->prev->next=pstart;
	free(temp);
	return pstart;
}

CDLL *delspecific(CDLL *pstart)
{
	int ch;
	CDLL *trav=pstart;

	puts(" ENTER ELEMENT TO BE DELETED :-> ");
	scanf("%d",&ch);
	if(trav->data==ch)		return (delfirst(pstart));

	trav=trav->next;
	while(trav!=pstart)
	{
		if(trav->data==ch)
		{
			trav->next->prev=trav->prev;
			trav->prev->next=trav->next;
			free(trav);
			return pstart;
		}
		trav=trav->next;
	}
	puts(" ELEMENT NOT FOUND IN LIST");
	return pstart;
}

CDLL* delet(CDLL* pstart)
{
	int ch=dmenu();
	if(pstart == NULL)	puts("LIST IS EMPTY ");
	else
	switch(ch)
	{
		case 1:     return delfirst(pstart);

		case 2:	    return dellast(pstart);

		case 3:	    return delspecific(pstart);

		default :   puts(" INVALID OPTION ");
	}
}

void display(CDLL *pstart)
{
	CDLL *trav=pstart;
	if(pstart==NULL)
		printf(" LIST IS EMPTY ");
	else{
		do
		{	printf("\t %d",trav->data);
			trav=trav->next;
		}while(trav!=pstart);
	}
}

int main()
{

	int ch;
	CDLL *start;

	start=NULL;
	
	while(ch = menu())
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

			case QUIT:	
					return 0;
			default:
					printf("\n INVALID OPTION");
					break;
		}
	}
}
