//COSC 1030 Michael Stoll, 7/28/21
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void bubbleSort(double*[], int);
void selectionSort(double*[], int);

const int ARRAYSIZE = 6;

int main()
{

	const int ARRAYSIZE = 6;

	double unsorted[ARRAYSIZE];
	double* sorted[ARRAYSIZE];

	string file; 
	ifstream Data;
	cout << "Please input the file location:" << endl; //it took me all the way until the last assignment, but I realized that you don't have to specify a full filepath if you have the file in the same folder as the program
	cin >> file; //better late than never, right?
	Data.open(file);

	for(int i = 0; i < ARRAYSIZE; i++)
	{
		Data >> unsorted[i];
	}

	for(int j = 0; j < ARRAYSIZE; j++) //of course, sorted isn't really sorted yet, but this for loop initializes each sorted value so it isn't empty and so it has things to trade
	{
		sorted[j] = &unsorted[j];
	}

	cout << "\nCalling bubbleSort:\n"; 
	bubbleSort(sorted, ARRAYSIZE);

	for(int j = 0; j < ARRAYSIZE; j++) //this second iteration of the loop is to reset the sorted array, so it can be resorted
        {
                sorted[j] = &unsorted[j];
        }


	cout << "\nCalling selectionSort\n";
	selectionSort(sorted, ARRAYSIZE);

	Data.close();
	return 0;
}

void bubbleSort(double** sorter, int size)
{
	bool moved;
	double* temp;
	int counter = 0;

	do
	{
		moved = false; //start off without anything having been moved
		for(int j = 0; j < (size - 1); j++)
		{
			if(*sorter[j] > *sorter[j + 1]) //if there is something that needs to be moved,
			{
				*temp = *sorter[j]; //move it, without deleting any information, by using a temp variable
				*sorter[j] = *sorter[j + 1];
				*sorter[j + 1] = *temp;
				moved = true;
			}
		}
	} while (moved); //and keep doing this while there are things moving

	for(int k = 0; k < ARRAYSIZE; k++)
	{
		cout << *sorter[k] << "\t";
	}
}

void selectionSort(double** sorter, int size)
{
	int start, minIndex; //start is the place in the array where you start, minIndex is esentially the same thing unless you find a value in the rest of the array that is smaller than start,
				//in which case it becomes a variable that holds that value for the sorting process
	double* minValue; //min value is the smallest value of the iteration, even though we're dealing with pointers

	for(start = 0; start < (size - 1); start++)
	{
		minIndex = start; //tie the two together
		minValue = sorter[start]; //and assume the first value is smallest
		for(int l = (start + 1); l < size; l++)
		{
			if(*(sorter[l]) < *minValue) //if you find a smaller value, go ahead and make that minValue variable earn it's paycheck
			{
				minValue = sorter[l];
				minIndex = l; //and tell the program where to find that value
			}
		}
		sorter[minIndex] = sorter[start]; //then take a couple lines and swap the two values
		sorter[start] = minValue;
	}	
	
	for(int k = 0; k < ARRAYSIZE; k++)
        {
                cout << *sorter[k] << "\t";
        }

}
