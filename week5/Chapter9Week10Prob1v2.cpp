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

  // populate the array with even numbers 


  cout << "\nPrinting the forward array intArray with printArray\n";
  printArray(intArray, numArray); 

  int *rev;  

  cout << "\nCalling rev = revArray(intArray, numArray);\n";
  rev = revArray(intArray, numArray); 
  cout << "\nPrinting the reversed array\n";
  printArray(rev, numArray); 
  cout << "\nPrinting the original array\n");
  printArray(intArray, numArray);  

  // deallocate the memory allocated in this program with appropriate use of delete 
 
}

// Write your functions here

