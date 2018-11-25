#include<iostream>
#include<string.h>

using namespace std;

#define MAX 25

typedef struct {
		  int top;
		  int data[MAX];
		}STACK;

void push(STACK *stack,char newele)
{
	stack->data[++stack->top]=newele;
}

char pop(STACK *stack)
{
       return  stack->data[stack->top--];
}

int priority(char temp)
{
    switch(temp)
    {
        case '*':
	case '/':
	case '%':    return 2;
	case '+':
	case '-':    return 1;
	default :    return 0;
    }
}

int main()
{
	STACK stack;
	char infix[20], postfix[20], temp;
	int i=0,j=0,l,newopr,op1;
	
        stack.top=-1;
	
        cout<<"operator & operand must be of one charecter "<<endl;
	cout<<"ENTER INFIX EXPRESSION:->"<<endl;
	cin>>infix;
	
        l = strlen(infix);
	
	while(infix[i] != '\0')
	{
	    temp = infix[i++];

            if((temp>64  &&  temp <91) || (temp>96  &&  temp <123))
	        postfix[j++] = temp;
	    else
		if(stack.top == -1)	
                    push(&stack, temp);
		else
		{     
                    newopr = priority(temp);

	            while(1) {
		        op1 = priority(stack.data[stack.top]);
			
                        if(newopr > op1)
			{       
                            push(&stack, temp);
			    break;
			}
		        else
			    postfix[j++]=pop(&stack);
	            }

		}
	}

	while(stack.top >= 0)
	    postfix[j++] = pop(&stack);

	for(i = 0;i<l;i++)
	    cout<< postfix[i];

	cout<<endl;
}
