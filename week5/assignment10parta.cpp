//Michael Stoll, COSC 1030 7/11/21
#include <iostream>
using namespace std; 

void printArray(int *, const int); 
int * revArray(int *, const int);

int main() {
  int numArray; 
  cout << "how many integers will be in the array? : " << endl;
  cin >> numArray;

  int *intArray; 
  // use new to allocate space for an array, intArray  with numArray elements
  intArray = new int[numArray];
  // populate the array with even numbers 
  for(int i = 0; i < numArray; i++)
  {
	intArray[i] = i * 2;
  }
  //test the printArray function as well as the intArray initialization
  cout << "\nPrinting the forward array intArray with printArray\n";
  printArray(intArray, numArray); 

  // set aside a chunk of memory for the reverse array I'll be making
  int *rev;  
	
  //test everything else
  cout << "\nCalling rev = revArray(intArray, numArray);\n";
  rev = revArray(intArray, numArray); 
  cout << "\nPrinting the reversed array\n";
  printArray(rev, numArray); 
  cout << "\nPrinting the original array\n";
  printArray(intArray, numArray);  

  // deallocate the memory allocated in this program with appropriate use of delete 
  delete [] intArray;
  intArray = 0;
}

void printArray(int* inpArr, const int size)
{
	//literally just prints each value of an array
	for(int i = 0; i < size; i++)
	{
		cout << inpArr[i] << " ";
	}

}

int* revArray(int * fwdArr, const int size)
{
	//use two counter variables, one counting up and one counting down, so I can have the highest value in the imported array initialized to the smallest value in my created array
	int count = 0;
	int* tempArray = new int[size];
	for(int j = size - 1; j >= 0; j--)
	{
		tempArray[count] = fwdArr[j];
		count++; 
	}
	return tempArray;
	delete [] tempArray;
	tempArray = 0;
}
