/*	QUEUE USING ARRAY REPRESANTATION . 	*/

#include"stdio.h"

#define SIZE 5

typedef struct qtag
	{
	    int data[SIZE];
	    int front;
	    int rear;
	}qtype;

typedef enum ch{ QUIT , INSERT , DELET , DISPLAY , RETRIVE}choice;

// TO INITIALIZE THE Q AT START .
void initialize(qtype *pq)
{
    pq->front=0;
	pq->rear=-1;
}
// TO KNOW USER'S CHOICE .
int menu()
{       int ch;
	puts("\n\t0 : QUIT ");
	puts("\n\t1 : INSERT");
	puts("\n\t2 : DELET");
	puts("\n\t3 : DISPLAY");
	puts("\n\t4 : RETRIVE");
	puts("\n\tENTER YOUR CHOICE :-> ");
	scanf("%d", &ch);
	return ch;
}
// TO CHECK WEATHER THE Q IS FULL OR NOT .
int isfull(qtype dq)
{
	if ( dq.rear == SIZE-1)
		return 1;
	else
		return 0;
}

// TO CHEC WEATHER THE Q IS EMPTY OR NOT .
int isempty(qtype dq)
{
	if ( dq.front > dq.rear )          //OR dq.front==dq.rear+1
		return 1;
	else
		return 0;
}

// TO READ DATA
int readdata()
{
	int data;
	puts("ENTER DATA :->" );
	scanf("%d",&data);
	return data;
}

// TO INSERT A NEW ELEMENT IN Q .
void insert( qtype *pq , int ele )
{
	pq->rear++;
	pq->data[pq->rear]=ele;
}

// TO DELET AN ELEMENT .
int delet( qtype *pq)
{
	return pq->data[pq->front++];
}

//  TO DISPLAY CONTAINS OF QUEUE .
void display( qtype *pq)
{
	int i;
	for ( i = pq->front ;i <= pq->rear ; i++)
		printf("\n data[%d] = %d ",i,pq->data[i]);
}

//  TO RETRIVE TOP MOST ELEMENT .
void retrive(qtype *pq)
{
	printf("\n data[%d] = %d ",pq->rear,pq->data[pq->rear]);
}


int main()
{
	qtype q;
	int ele,ch;

	initialize(&q);
	while(ch = menu())
	{
		switch (ch)
		{
			case INSERT:	
				if(isfull(q))
					puts("QUEUE IS FULL ");
				else{	
					ele = readdata();
					insert( &q , ele );
				}
				break;

			case DELET:	
				if(isempty(q))
					puts("QUEUE IS EMPTY ");
				else{	
					ele = delet(&q);
					printf(" deleted element = %d ",ele);
				}
				break;

			case DISPLAY:  	
				if(isempty(q))
				    puts("QUEUE IS EMPTY ");
				else
					display( &q );
				break;

			case RETRIVE:	
				if(isempty(q))
					puts("QUEUE IS EMPTY ");
				else
					retrive( &q );
				break;

			default :	
				puts (" INVALID OPTION ");
		}
	}
}
