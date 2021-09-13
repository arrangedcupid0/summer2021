//Michael Stoll, COSC 1030 7/8/2021
#include <iostream>
using namespace std; 

void printArray(int *, const int);
void printArray2(int [], const int); 
void revArray(int *, int *, const int);

int main() {
  const int size = 5;
  int intArray[] = {1, 2, 3, 4, 5};
  int arr2[size];  // space for size integers
  int *arrPtr = intArray;  // points to first element of intArray
  int *ptr2 = &intArray[0]; 
  int arr3[size];  // space for size integers
 
  cout << "\nPrinting the forward array intArray with printArray\n";
  printArray(intArray, size); 

  cout << "\nPrinting the forward array  arrPtr with printArray2\n"; 
  printArray2(arrPtr, size);  

  cout << "\nCalling revArray(intArray, arr2, size); \n"; 
  revArray(intArray, arr2, size); 
  cout << "\nPrinting the reversed array, arr2: \n";
  printArray(arr2, size); 

  cout << "\nCalling revArray(ptr2, arr3, size);\n";
  revArray(ptr2, arr3, size); 
  cout << "\nPrinting the reversed array, arr3\n";
  printArray(arr3, size); 

  // critique the following code:
  /*
  int *bptr;
  revArray(intArray, bptr, size); 
  printArray(bptr, size); 
  */

//that code would be fine, except that you didn't initialize bptr as nullptr,
//and with what I gather from the reading it doesn't like that very much
 
}

// Write your functions here

void printArray(int* arrPtr, const int size)
{

	for(int i = 0; i < size; i++)
	{
		cout << *(arrPtr + i) << " "; //references each member of the array in terms of memory address
	}

}

void printArray2(int  arr[], const int size)
{

	for(int j = 0; j < size; j++)
	{
		cout << arr[j] << " "; //references each member of the array in terms of actual array methods
	}

}

void revArray(int* ptrArr, int* newArr, const int size) //this one is a little more complicated.
{
	int count = 0; //i need two counter variables here, because I need one to count up and one to count down. count counts up,
	for(int k = size; k > 0; k--) //and k counts down from size. this is because i want to work backwards through the memory address of
	{				//the intArray while working forwards through arr3.
		*(newArr + count) = *(ptrArr + (k-1));
		count++;
	}

}
