#include<iostream>
#include"string.h"
#include<cstdlib>

using namespace std;

#define MAX 25

typedef struct {
		  int top;
		  int data[MAX];
		}STACK;

void push(STACK *stack,int newele)
{
    stack->data[++stack->top]=newele;
}

char pop(STACK *stack)
{
    return  stack->data[stack->top--];
}

int operation(int opr1,int opr2,char temp1)
{
    switch(temp1)
    {
	case '*':   return opr1 * opr2;

	case '/':   return opr1 / opr2;

	case '%':   return opr1 % opr2;

	case '+':   return opr1 + opr2;

	case '-':   return opr1 - opr2;
    }
}

int main()
{
	STACK stack;
	char postfix[MAX],temp[2] = {"0"};
	int i=0,opr1,opr2,result;
	
	stack.top=-1;
	
	cout<<"operator & operand must be of one charecter "<<endl;
	cout<<"ENTER POSTFIX EXPRESSION:->"<<endl;
	cin>>postfix;
	
        while(postfix[i] != '\0')
	{       
	    temp[0] = postfix[i++];
	    
            if ((temp[0] >='0')&&(temp[0] <= '9'))
	        push(&stack,atoi(temp));
	    else
            {
		opr2 = pop(&stack);
		opr1 = pop(&stack);
		result = operation(opr1,opr2,temp[0]);
		push(&stack,result);
	    }
	}
	cout<<stack.data[stack.top]<<endl;
}
