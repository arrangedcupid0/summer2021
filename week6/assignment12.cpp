//Michael Stoll, COSC 1030 7/18/2021
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

enum class Color {BLUE, RED, ORANGE, SILVER, BLACK, GREEN};

struct Car
{
        string brand; //this is the structure outlined in the assignment instructions
        string model;
        int numMiles;
        Color color; 
	int year;
};

Car* readCarList(string, int);
void printCarList(Car*, int);
Car* findNewCars(Car*, int, int, int&);
int colorToInt(string);
string colorToString(Color);

int main()
{
	//this chunk of code asks the user for a complete file location (i.e. /home/pi/Downloads/cars.txt) and imports that file
	string location; 
	cout << "Please enter the full location of the file, starting at the /home directory:" << endl;
	cin >> location;
	ifstream carTable;
	carTable.open(location);

	int numCars = 0;
	while(!carTable.eof())
	{
		string burner; //this is just to iterate through the entire file, to increase a counter variable which stores the total size
		carTable >> burner;
		numCars++; //which I get over here, though this size holds 5 x the amount of cars, so I have to divide it by 5
	}
	numCars /= 5; //like I do here.
	
	Car* masterList = new Car[numCars];
	masterList = readCarList(location, numCars);
	
	cout << "\nThese are the cars we have on the lot:" << endl; //all this through here is pretty standard input / output code, which runs various functions as it needs them
	printCarList(masterList, numCars);

	int oldestYear;
	int newerCars = numCars;
	Car* newCars;
	cout << "\nWhat is the oldest year of car that you're looking for?" << endl;
	cin >> oldestYear;
	newCars = findNewCars(masterList, numCars, oldestYear, newerCars);
	
	cout << "\nThese are the cars that fit that criteria:" << endl;
	printCarList(newCars, newerCars);
	
	delete [] masterList;
	masterList = nullptr;
	delete [] newCars;
	newCars = nullptr;
}

Car* readCarList(string fileName, int numCars)
{
	Car* cars = new Car[numCars];
	int colorInt;	//the int that corresponds to the color in the enumerated variable Color

	ifstream carTable;	
        carTable.open(fileName);

        for(int i = 0; i < numCars; i++) //use the inputfile that the user added to initialize a Car structure (object? It seems a lot like the objects I learned about in Java)
        {
		string temp;
                carTable >> cars[i].brand;
                carTable >> cars[i].model;
                carTable >> cars[i].numMiles;
                carTable >> temp;
		colorInt = colorToInt(temp); //for an explanation, see the colorToInt function below
		cars[i].color = static_cast<Color>(colorInt); //this took a lot of trial and error. it's sort of like a crude teepee; don't look at it too hard, and it shouldn't fall down
                carTable >> cars[i].year;
        }
	return cars;
}

void printCarList(Car* carList, int count)
{
	for(int j = 0; j < count; j++) //uses the left and setw() functions for formatting, the rest is self explanatory
        {
		if(carList[j].year != 0) //if the year of a car is stored as 0, I know it's an empty member of the array, and I don't want to print it
		{
                 string input = colorToString(carList[j].color);
		 cout << left << setw(13) << carList[j].brand << setw(13) << carList[j].model << setw(13) << carList[j].year << setw(13) << carList[j].numMiles << setw(13) << input << endl;
      		} 
	 }

}

Car* findNewCars(Car* carList, int count, int year, int& countNew)
{
	int newCount = 0; //this function takes values from the total car list and checks if they are newer than a given year. if they are, it adds the value to an array to export
	int counter = 0;
	for(int k = 0; k < count; k++) //this for loop figures out how much space needs to be allocated for the array
	{
		if(carList[k].year >= year)
		{
			newCount++;
		}
	}
	Car* newCars = new Car[newCount];
        for(int k = 0; k < count; k++) //this for loop fills up that array
        {
                if(carList[k].year >= year)
                {
                        newCars[counter] = carList[k];
                        counter++;
                }
        }

	return newCars;
}

int colorToInt(string color) //i couldn't import directly to an integer or a Color enum, so I made my own crude type converter.
{
	int output;
	if(color == "blue")
	{
		output = 0;
	} else if(color == "red")
	{
		output = 1;

	} else if(color == "orange")
	{
		output = 2;

	} else if(color == "silver")
	{
		output = 3;

	} else if(color == "black")
	{
		output = 4;

	} else if(color == "green")
	{
		output = 5;
	}

	return output;
}
string colorToString(Color c) //this is how I convert the int that is stored for the color back into a string value that I can output.
{
	int temp = static_cast<int>(c);
	string output;
	switch(temp)
	{
		case 0:
			{
				output = "blue";
			} break;
		case 1:
			{
				output = "red";
			} break;
		case 2:
			{
				output = "orange";
			} break;
		case 3:
			{
				output = "silver";
			} break;
		case 4:
			{
				output = "black";
			} break;
		case 5:
			{
				output = "green";
			} break;
		default : output = "<Unidentified Color>";
	}
	return output;
}
