#include"stdio.h"
#define MAX 5

typedef struct
{
	int top;
	int data[MAX];
}STACK;

typedef enum{ QUIT , PUSH ,  POP , DISPLAY } choice;

int menu ()
{
	int ch;
	puts(" \n\t\t\tMAIN MENU \n");
	puts(" 0 : QUIT");
	puts(" 1 : PUSH");
	puts(" 2 : POP ");
	puts(" 3 : DISPLAY");
	puts("Enter your choice :-> ");
	scanf("%d",&ch);
	return ch;
}

int isfull(int top)
{
	return ( top >= MAX-1 ? 1 : 0 );
}
int isempty(int top)
{
		return (top < 0 ? 1 : 0);
}
void push(STACK *stack, int newele)
{
	stack->data[++stack->top]=newele;
}
void pop(STACK *stack)
{
	stack->top--;
}
void display(STACK stack)
{
	int i;
	for(  i=0;  i<=stack.top;  i++)
		printf("\ndata[%d] = %d\n ", i, stack.data[i]);
}

int main()
{
	int ch,newele;
	STACK  stack;
	stack.top=-1;

	while(ch=menu())
	{
		switch(ch)
		{
			case PUSH:      
				if(isfull(stack.top))
				    puts("STACK IS FULL");
				else
				{
				    puts("Enter new element :->");
			            scanf("%d",&newele);
				    push( &stack, newele);
				}
				break;

			case POP:       
				if(isempty(stack.top))
				    puts("STACK IS EMPTY");
				else
				{
				    printf("DELETED ELEMENT DATA[%d] = %d",stack.top, stack.data[stack.top]);
				    pop(&stack);
				}
				break;

			case DISPLAY:   
				if(isempty(stack.top))
				    puts("STACK IS EMPTY");
				else
				    display(stack);
				break;

			default:   	
                                puts("WRONG choice");
				break;
		}
	}
}

