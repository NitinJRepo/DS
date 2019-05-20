//********************
//Author: Nitin
//********************

#include <iostream>
#include <cstring>
using namespace std;


int fibonacci(int n, int lookupArray[])
{
	if(n < 2)
		return n;

	// if sub-problem is seen for the first time
	if(lookupArray[n] == 0) 
		lookupArray[n] = fibonacci(n-1, lookupArray) + fibonacci(n-2, lookupArray);

	return lookupArray[n];
}

int main()
{
	int n;
	
	cout<<"Enter number : ";
	cin>>n;

	int lookupArray[n + 1];

	memset(lookupArray, 0, sizeof(lookupArray));

	cout << "Using Dynamic Programming (Top-Down approach -- Memoization)" << endl;
	cout << "The Nth Fibonacci Number is: " << fibonacci(n, lookupArray) << endl;

}

// Time complexity: O(n), instead of exponential time
// Space complexity: O(n) 
