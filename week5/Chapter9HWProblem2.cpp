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
 
}

// Write your functions here