//********************
//Author: Nitin
//********************

#include<iostream>
using namespace std;

int fibonacci(int n)
{
	int i, previous=0, current=1, next;


	for(i=0; i < n-1; i++)
	{
		next = previous + current;
		previous = current;
		current = next;
	}
	return current;
}

int main()
{
	int n;

	cout << "Enter number of terms for Series: ";
        cin >> n;

	cout << "Using Dynamic programming (Bottom-Up approach -- Tabulation)" << endl;
	cout<<"Nth fibonacci number is  : " << fibonacci(n) << endl;
}

//Time complexity: O(n) since it contains loop that repeats n-1 times
//Space complexity: O(1) i.e. constant
