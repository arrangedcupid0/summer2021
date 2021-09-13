//Michael Stoll, COSC 1030 7/14/2021
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Car
{
        string brand; //this is the structure outlined in the assignment instructions
        string model;
        int numMiles;
        string color;
	string year;
};


int main()
{
	const int size = 10; //this is the size for the later cars array and is meant to correspond with the amount of entries in the cars.txt file inputed
	
	//this chunk of code asks the user for a file location and imports that file
	string location; 
	ifstream carTable;
	cout << "Please enter the name of the file:" << endl;
	cin >> location;
	carTable.open(location);

	//this makes an array of Car called cars, with the size of size. isn't technical speak fun?
	Car cars[size];

	//declares and initializes the totalMiles variable for later 
	int totalMiles = 0;

	for(int i = 0; i < size; i++) //use the inputfile that the user added to initialize a Car structure (object? It seems a lot like the objects I learned about in Java)
	{
		carTable >> cars[i].brand;
		carTable >> cars[i].model;
                carTable >> cars[i].numMiles;
                carTable >> cars[i].color;
                carTable >> cars[i].year;
	}

	cout << "\nHere are the cars on the lot today: " << endl;

	for(int j = 0; j < size; j++) //uses the left and setw() functions for formatting, the rest is self explanatory
	{
		cout << left << setw(13) << cars[j].brand << setw(13) << cars[j].model << setw(13) << cars[j].year << setw(13) << cars[j].numMiles << setw(13) << cars[j].color << endl;
		totalMiles += cars[j].numMiles; //also this is used for the final cout statement
	}
	
	cout << "\nThese cars are silver: " << endl;
	for(Car each : cars) //this is supposed to step through each Car in the cars array and check if its color is silver, which would make it print to the terminal window with cout
	{
		if(each.color == "silver")
		{
			cout << each.brand << " " << each.model << endl;
		}
	}
	
	cout << "\nThese cars have been used for more than 75,000 miles: " << endl;
	for(Car each : cars) //this is supposed to step through each Car in the cars array and check if its mileage is above 75k, which would make it print to the terminal window with cout
	{
		if(each.numMiles > 75000) //side note: why isn't ctrl+c, ctrl+v a thing in nano? it would have been way easier to copy the first time I typed that line instead of retyping it
		{
			cout << each.brand << " " << each.model << endl;
		}
	}
	cout << "\nAll together, these cars have traveled a total of " << totalMiles << " miles." << endl;
}
