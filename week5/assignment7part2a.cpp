//Michael Stoll, COSC 1030 07/05/2021
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	double  min, //the minimum value
		total, //sum of all numbers
		input, //middle man between the file and the vector
		average; //average of all numbers
	string location; //location of file to be read
	ifstream numberFile; //file to be read from
	vector<double> numbers; //vector that eventually is filled with the file's contents
	
	cout << "Input the name of a file of numbers." << endl;
	cin >> location;
	numberFile.open(location);
	 	while(!numberFile.eof())
		{
			numberFile >> input; //I put the middle man here so that i could put the result into the push_back() function
			numbers.push_back(input);
		}
	numberFile.close();
	
	min = numbers[0]; //assume that the first item is the smallest so far
	total = 0; //you have to initialize these guys or they won't accept +=
	for(double number : numbers) // for each number in the vector
	{
		if(number < min)
		{
			min = number; //if this number is smaller than the minimum, make this the new minimum
		}
		total += number; //regardless, add the value to the total
	}
	average = total / numbers.size(); //and then divide the total by the size of the vector
	cout << "The smallest number is " << min << endl;
	cout << "The sum of all the numbers is " << total << endl;
	cout << "The average of these numbers is " << average << endl;
}

