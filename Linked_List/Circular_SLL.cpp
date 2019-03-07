#include "stdio.h"
#include "stdlib.h"

typedef struct l
{
	int data;
	struct l *next;
}CLL;

enum{QUIT,INSERT,DELETE, DISPLAY};

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

CLL* readdata()
{
	CLL *temp;
	temp=(CLL*) malloc (sizeof(CLL));
	if(temp==NULL)	return NULL;
	else
	{
		puts(" ENTER DATA :->");
		scanf("%d",&temp->data);
		temp->next=NULL;

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

CLL* addfirst(CLL *start)
{
	CLL *temp=readdata();
	CLL *trav=start;
	if(temp == NULL ){
		puts("MEMORY IS NOT AVAUILABLE");
		return NULL;
	}

	if(start==NULL)
	    temp->next=temp;

	else{
		while(trav->next!=start)
		trav=trav->next;

		temp->next=start;
		trav->next=temp;
	}
	start=temp;
	return start;
}

CLL *addlast(CLL *start)
{
	CLL *temp=readdata();
	CLL *trav=start;

	if(temp==NULL){
		puts("\n MEMORY IS NOT AVAILABLE");
		return NULL;
	}

	if(start==NULL)
	return(addfirst(start));

       while(trav->next!=start)
       trav=trav->next;

       temp->next=start;
       trav->next=temp;
       return start;
}

CLL *addafter(CLL *start)
{
	int ch;
	CLL *temp=readdata();
	CLL *trav=start;
	if(temp==NULL){
		puts("\n MEMORY IS NOT AVAILABLE");
		return NULL;
	}
	puts("\n ENTER THE ELEMENT TO SEARCHED");
	scanf("%d",&ch);
	do
	{
		if(trav->data==ch)
	       {	temp->next=trav->next;
			trav->next=temp;
			return start;
	       }
	       trav=trav->next;
	}while(trav!=start);
	puts("\n ELEMENT NOT FOUND");
	return start;
}

CLL *insert(CLL *start)
{
	int ch=imenu();
	switch(ch)
	{
		case 1:		return addfirst(start);
		case 2:		return addlast(start);
		case 3:		addafter(start);
				return start;
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

CLL *delfirst(CLL *start)
{
	CLL *temp;
	CLL *trav=start;

	if(start==NULL){
		puts("\n LIST IS EMPTY \n");
		return NULL;
	}
	if(start->next==start) {
		temp=start;
		start=NULL;
	}
	else{
		while(trav->next!=start)
		trav=trav->next;

		temp=start;
		start=start->next;
		trav->next=start;
	    }
	    free(temp);
	    return start;

}

CLL *dellast(CLL *start)
{
	CLL *temp;
	CLL *trav=start;

	if(start==NULL){
		puts("\n LIST IS EMPTY \n");
		return NULL;
	}
	if(start->next==start)
	   return delfirst(start);

	while(trav->next->next!=start)
	   trav=trav->next;

	temp=trav->next;
	trav->next=start;
	free(temp);

	return start;
}

CLL *delspecific(CLL *start)
{
	int ch;
	CLL *temp;
	CLL *trav=start;

	if(start==NULL){
		puts("\n LIST IS EMPTY \n");
		return NULL;
	}

	puts(" ENTER ELEMENT TO BE DELETED :-> ");
	scanf("%d",&ch);

	if(trav->data==ch)
	return (delfirst(start));

	do
	{
		if(trav->next->data==ch)
		{
			temp=trav->next;
			trav->next=temp->next;
			free(temp);
			return start;
		}
		trav=trav->next;
	}while(trav->next!=start);

	puts(" ELEMENT NOT FOUND IN LIST");
	return start;
}

CLL* delet(CLL* start)
{
	int ch=dmenu();
	if(start == NULL)	puts("LIST IS EMPTY ");
	else
	switch(ch)
	{
		case 1:     return delfirst(start);

		case 2:		return dellast(start);

		case 3:		return delspecific(start);

		default :	puts(" INVALID OPTION ");
	}
}

void display( CLL *start)
{
	CLL *trav=start;
	if(start==NULL)
		printf(" LIST IS EMPTY ");
	else
		do
		{	printf("\t %d",trav->data);
			trav=trav->next;
		}while(trav!=start);
}

int main()
{
	int ch;
	CLL *start;

	start = NULL;
	while(ch = menu())
	{
		switch(ch)
		{
			case INSERT :	start=insert(start);
					break;
			case DELETE :	start=delet(start);
					break;
			
			case DISPLAY:	display(start);
					break;
			case QUIT   :	
					return 0;
			default	    :
					printf("\n INVALID OPTION");
					break;
		}
	}
}
