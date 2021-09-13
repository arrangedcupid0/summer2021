#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	double numbers[200]; //the array has a maximum size of 200
	double smallest, //the smallest value in the file
	       sum, //the sum of the values stored in numbers[]
	       average; // the average of those same numbers
	string file; //file name, inputed by user
	int    count = -1; //counter variable for the for loop
	ifstream doubleFile; //the file full of doubles that will populate numbers[]
	bool eof = false;

	cout << "Enter the name of the file with doubles." << endl;
	cin >> file;
	doubleFile.open(file); 
	
	while(count < 200 && !eof) //while there are less than 200 values stored in numbers[]
	{
		if(doubleFile.eof()) //if it reaches the end of the file it needs to break, for some reason if I don't tell it to break the program just won't run correctly 
		{
			eof = true;
		} else {
		count++;
		doubleFile >> numbers[count]; //import the next number from the file and store it in the array
		}
	} 

	if(count == 199 && !doubleFile.eof()) //the insructions say to announce if there are more than 200 numbers in the 
	{
		cout << "The file has more than 200 numbers, but only 200 will be processed." << endl;
	}

	cout << "There are " << (count + 1) << " numbers in the array." << endl;	

	doubleFile.close(); 
		
	smallest = numbers[0]; //initialize that the first value is the current smalles value,
	for(int i = 0; i < count; i++) //then look for a smaller one.
	{
		if(numbers[i] < smallest && numbers[i] > 0) //i don't want it to partially initialize and leave a 0 to confuse the program
		{
			smallest = numbers[i];
		}
	}
	cout << "The smallest number is " << smallest << endl;
	sum = 0;
	for(int j = 0; j < count; j++) //i don't like using the same variable twice, even a self contained counter variable
	{
		sum += numbers[j];
	}
	 cout << "The sum of all the numbers in the array is " << fixed << sum << endl;


	average = (sum / count); //basic double division, total of all numbers divided by the amount of numbers
	cout << "The average of those numbers is " << average << endl;
}
