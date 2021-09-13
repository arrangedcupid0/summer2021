#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

double * addSpace(double* dptr, int size, int space);

int main()
{	
	//this block of code sets up the sample array and populates it with values from .5 to 29.5
	srand(time(0));
	const int size = 7;
	double* sampleDPtr = new double[size];
	for(int i = 0; i < size; i++)
	{
		sampleDPtr[i] = (rand() % 30) + .5;
	}

	//read out the values in the sample array with proper formatting
	cout << setprecision(2) << fixed;
	cout << "Initialized a sample double array with the values: ";	
	for(int k = 0; k < size; k++)
	{
		cout << sampleDPtr[k] << " ";
	}	

	//user inputs how much space they would like at the end of the array
	cout << "\nNow calling addSpace. How much space would you like?" << endl;
	int space;
	cin >> space;
	cout << "Calling addSpace(sampleDPtr, size, space);..." << endl;
	double* newDArr = new double[size + space];
	newDArr = addSpace(sampleDPtr, size, space);

	//returns the array that addSpace provides 
	cout << "addSpace returned this array: ";
	for(int l = 0; l < (size + space); l++)
	{
		cout << *(newDArr + l) << " ";
	}

	//frees up the memory used in the program
	delete [] newDArr;
	delete [] sampleDPtr;
	newDArr = 0;
	sampleDPtr = 0;
}

double * addSpace(double* dptr, int size, int space)
{
	//i don't need to free up this memory because A. the scope is limited to this function and B. I actually can't because I can't reference newDoubArr outside the function and I can't delete inside the function
	//anyway, the code copies the sample array over, then adds as many zeros as the user desires
	double* newDoubArr = new double[size + space];
	for(int i = 0; i < size; i++)
	{
		newDoubArr[i] = dptr[i];
	}
	for(int j = 0; j < space; j++)
	{
		newDoubArr[size + j] = 0;
	}
	return newDoubArr;
	delete [] newDoubArr;
	newDoubArr = 0;
}
