//********************
//Author: Nitin
//********************

#include<iostream>
using namespace std;

int fibonacci(int n)
{
	if(n == 0) 
		return 0;
	if (n == 1) 
		return 1;

	return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
	int i,n;

	cout<<"Enter number: ";
	cin>>n;

	cout << "Using recursive approach:" << endl;	
	cout << "The Nth Fibonacci Number is: "<< fibonacci(n) << endl;

}

//Time complexity: T(n) = T(n-1) + T(n-2) which is exponential.
//Space complexity: O(n) because recursive program will internally maintain stack of size n for recursive function call 
