//Michael Stoll, COSC 1030 7/7/2021
#include <iostream>

using namespace std;

int whyWouldYouNeedThisEquation(int*, int*);

int main()
{
	int x, y, z;
	
	
	cout << "Give a value for x: " << endl;
	cin >> x; //the user assigns the variables arbitrary integers
	cout << "Give a value for y: " << endl;
	cin >> y;

	z = whyWouldYouNeedThisEquation(&x, &y); //and then passes those integers as reference points to the function, where it converts those addresses to pointers

	cout << "The new value for x is " << x << endl; //and then main throws out the newly minted variables, complete with needless multiplication
	cout << "The new value for y is " << y << endl;
	cout << "The number returned by the function is " << z << endl; 
}

int whyWouldYouNeedThisEquation(int* a, int* b)
{
	int temp = *a; //you said not to restate the code,
	*a = *b * 10; //so the bare bones, sparknotes details are as follows:
	*b = temp * 10; //a and b both store memory addresses,
	return *a + *b; //by labeling them with * I should be able to manipulate the actual number being referenced.
}
