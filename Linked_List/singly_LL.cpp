#include<iostream>
#include "stdlib.h"

using namespace std;

typedef struct linkList
{
	int data;
	struct linkList *next;
}LL;

enum{QUIT,INSERT,DELETE,REVERSE,R_REVERSE,DISPLAY,SORTED_INSERT,NTHNODE};

int menu()
{       int ch;
	cout<<"\n\t 0 : QUIT "<<endl;
	cout<<"\t 1 : INSERT"<<endl;
	cout<<"\t 2 : DELETE"<<endl;
	cout<<"\t 3 : REVERSE"<<endl;
        cout<<"\t 4 : RECURSIVE REVERSE"<<endl;
	cout<<"\t 5 : DISPLAY"<<endl;
        cout<<"\t 6 : SORTED INSERTED"<<endl;
        cout<<"\t 7 : Nth NODE"<<endl;
	cout<<"\n\t ENTER YOUR CHOICE :-> ";
	cin>>ch;
	return ch;
}

LL* readdata()
{
	LL *temp;
	temp=(LL*) malloc (sizeof(LL));
	if(temp==NULL)	return NULL;
	else
	{
		cout<<" ENTER DATA : ";
		cin>>temp->data;
		temp->next=NULL;

		return temp;
	}
}
int imenu()
{
	int ch;
	cout<<"1: INSERT AT FIRST"<<endl;
	cout<<"2: INSERT AT LAST"<<endl;
	cout<<"3: INSERT AFTER SPECIFIC VALUE"<<endl;
        cout<<"\n Enter CHOICE: ";
	cin>>ch;
	return ch;

}
LL* addfirst(LL *pstart)
{
	LL *temp=readdata();
	if(temp == NULL )
        {	
            cout<<"MEMORY IS NOT AVAUILABLE"<<endl;
            return pstart;
	}

        temp->next=pstart;
	return temp;
}
LL *addlast(LL *pstart)
{
	LL *temp=readdata();
	LL *trav=pstart;
	if(temp==NULL)
        {
            cout<<"\n MEMORY IS NOT AVAILABLE"<<endl;
            return pstart;
	}
        
        if(pstart==NULL) 	
            return(addfirst(pstart));

	while(trav->next!=NULL)
            trav=trav->next;

       trav->next=temp;
       return pstart;
}
LL *addafter(LL *pstart)
{
	int ch;
	LL *temp=readdata();
	LL *trav=pstart;
	if(temp==NULL)
	cout<<"MEMORY IS NOT AVAILABLE"<<endl;
	cout<<"ENTER THE ELEMENT TO BE SEARCHED"<<endl;
	cin>>ch;
	while(trav!=NULL)
	{
		if(trav->data==ch)
	       {	temp->next=trav->next;
			trav->next=temp;
			return pstart;
	       }
	       trav=trav->next;
	}
	cout<<"ELEMENT NOT FOUND"<<endl;
        return pstart;
}

LL *insert(LL *pstart)
{
	int ch=imenu();
	switch(ch)
	{
		case 1:		return addfirst(pstart);
		case 2:		return addlast(pstart);
		case 3:		addafter(pstart);
				return pstart;
		default:
			cout<<"\n INVALID OPTION"<<endl;
	}
}
int dmenu()
{
	int ch;
	cout<<" 1 : DELETE FROM START"<<endl;
	cout<<" 2 : DELETE FROM END"<<endl;
	cout<<" 3 : DELETE ANY SPECIFICE VALUE"<<endl;
	cin>>ch;
	return ch;
}
LL *delfirst(LL *pstart)
{
    if(pstart == NULL)
    {
        cout<<"LIST IS EMPTY"<<endl;
        return pstart;
    }     

	LL *temp=pstart;
	pstart=pstart->next;
	free(temp);
	return pstart;
}
LL *dellast(LL *pstart)
{
    if(pstart == NULL)
    {
        cout<<"LIST IS EMPTY"<<endl;
        return pstart;
    }

	LL *trav=pstart;
	LL *temp;
	if(trav->next==NULL)		
            return(delfirst(pstart));
	
        while(trav->next->next!=NULL)
	    trav=trav->next;
	
        temp=trav->next;
	trav->next=NULL;
	free(temp);
	return pstart;
}
LL *delspecific(LL *pstart)
{
    if(pstart == NULL)
    {
        cout<<"LIST IS EMPTY"<<endl;
        return pstart;
    }

	int ch;
	LL *trav=pstart;
	LL *temp;
	cout<<" ENTER ELEMENT TO BE DELETED: ";
	cin>>ch;
	if(trav->data==ch)		return (delfirst(pstart));

	while(trav->next!=NULL)
	{
		if(trav->next->data==ch)
		{
			temp=trav->next;
			trav->next=trav->next->next;
			free(temp);
			return pstart;
		}
		trav=trav->next;
	}
	cout<<" ELEMENT NOT FOUND IN LIST"<<endl;
	return pstart;
}
LL* delet(LL* pstart)
{
	int ch=dmenu();
	if(pstart == NULL)	cout<<"LIST IS EMPTY "<<endl;
	else
	switch(ch)
	{
		case 1:         return delfirst(pstart);

		case 2:		return dellast(pstart);

		case 3:		return delspecific(pstart);

		default :	 cout<<" INVALID OPTION "<<endl;
	}
}
LL* reverse(LL* start1)
{
	LL* temp;
	LL* start2=NULL;
	if(start1==NULL)
	{	cout<<"\n LIST IS EMPTY"<<endl;
		return NULL;
	}
	while(start1!=NULL)
	{
		temp=start1;
		start1=start1->next;
		temp->next=start2;
		start2=temp;
	}
	cout<<"\n LIST SUCCESSFULLY REVERSED"<<endl;
	
	return start2;
}

LL* r_Reverse(LL* start1)
{
    LL* first;
    LL* rest;

    if (start1 == NULL)
    {
       cout<<"list is empty"<<endl;
       return NULL;
    }

    if(start1->next==NULL)
        return start1;
 
    first = start1;
    rest = first->next;

    first->next = NULL;
    start1 = r_Reverse(rest);
    rest->next = first;

    return start1;
}

LL* sortedInsert(LL* start)
{
	LL* temp=readdata();
	LL* trav = start;
	LL* prev = start;

	if(start==NULL || start->data > temp->data)
	{
		temp->next=start;
		return temp;
	}
	while (trav!= NULL && trav->data < temp->data)
	{
		prev=trav;
		trav=trav->next;
	}
	temp->next=trav;
	prev->next=temp;
	return start;
}

LL* nthNode(LL *start)
{
    LL *ptr1,*ptr2;
    int n;
    int count=0;

    if(start==NULL)
    {
	cout<<"LIST IS EMPTY"<<endl;
	return NULL;
    }
  
    cout<<"ENTER THE Nth NODE FROM LAST : "<<endl;
    cin>>n;

    ptr1  = start;
    ptr2  = start;

    while(count < n)
    {
       count++;
       
       if((ptr1=ptr1->next)==NULL)
       {	  
         cout<<"Length of the linked list less than n."<<endl;
         return NULL;
       }
    }

    while((ptr1=ptr1->next)!=NULL)
         ptr2=ptr2->next;

    return(ptr2);
} 

void display( LL *pstart)
{
	LL *trav=pstart;
	if(pstart==NULL)
		cout<<" LIST IS EMPTY "<<endl;
	else
		while( trav != NULL )
		{	cout<<"\t"<<trav->data;
			trav=trav->next;
		}
}

int main()
{

	int ch;
	LL *start;
	LL *nthnode;
        start=NULL;
        
	while(ch=menu())
	{
		switch(ch)
		{
			case INSERT :	start=insert(start);
					break;
			case DELETE :	start=delet(start);
					break;
			case REVERSE:   start=reverse(start);
					break;
                        case R_REVERSE: start=r_Reverse(start);
                                        break;
			case DISPLAY:	display(start);
					break;
                        case SORTED_INSERT: start=sortedInsert(start);
                                        break;
                        case NTHNODE:   nthnode=nthNode(start);
                                        cout<<"Nth node from last is : "<<nthnode->data<<endl;
                                        break;
			case QUIT   :	return 0;
			default	    :
					cout<<"INVALID OPTION"<<endl;
					
					return 0;
		}
	}
}
