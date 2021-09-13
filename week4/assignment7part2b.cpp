//Michael Stoll COSC 1030 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MONTHS = 4; //declared so the other functions can use it in their headers
const int YEARS = 3; //declared because there isn't a reason not to, all three functions need it

void averageMonthly(const double[][MONTHS]);

void findRange(const double[][MONTHS], double, double);

int main()
{
	string monthsUsed[] = {"January", "February", "March", "April"};
	int choice; //which choice from the menu below
	double rainfall[YEARS][MONTHS];
	char input; //determines where the data comes from

	cout << "Do you want to input the data manually, or open a file? (M or F)" << endl;
		cin >> input;
	switch(input)
	{
		case 'M':
			{ for(int k = 0; k < YEARS; k++) //I feel like this format is more user friendly than having an input of every january, then every february, etc.
			 {
				cout << "This data is for year " << k + 2019 << endl;
				for(int j = 0; j < MONTHS; j++)
				{
					cout << "Month " << j + 1 << "?" << endl;
					cin >> rainfall[k][j];
				}
			 }
			}
			break;
		case 'F':
			{ string location;
			  ifstream rainfallFile;
			  cout << "Input your file location." << endl;
			  cin >> location;
			  rainfallFile.open(location); 
	        	 for(int i = 0; i < YEARS; i++) //this is a set of for loops that populate the 2d array with the numbers from a file,
                        {
                                for(int j = 0; j < MONTHS; j++) // granted that said file has the correct formatting
                                {
                                        rainfallFile >> rainfall[i][j];
                                }
                        }
			}
			break;
		default: cout << "Please enter a valid input." << endl;
			exit(0);
	}
	cout << "The input has been accepted. You can now do the following:" << endl;
	cout << "1. Find the average rainfall for each month" << endl;
	cout << "2. Define a range of values and find which months of which years fall under that range" << endl;
	cout << "3. Exit the program." << endl;
	cout << "\nType the number of your choice." << endl;
	cin >> choice;
	switch(choice)
	{
		case 1: 
			{
				averageMonthly(rainfall);
			}	break;
		case 2:
			{
				double min, //minimum value
				       max; //maximum value

				cout << "What is the minimum value?" << endl;
				cin >> min;
				cout << "\nWhat is the maximum value?" << endl;
				cin >> max;
				findRange(rainfall, min, max);
			}	break;
		case 3:
			{
				cout << "Goodbye." << endl;
			} exit(0);
		default: cout << "Please enter a valid input." << endl;
			exit(0);
	}
}

void averageMonthly(const double rainfall[][MONTHS])
{
	double monthlyRainfall[MONTHS];

	for(int i = 0; i < MONTHS; i++)
	{
		double temp = 0;
		for(int j = 0; j < YEARS; j++)
		{
			temp += rainfall[j][i]; //temp variable used to add up values before division 
		}
		monthlyRainfall[i] = temp / YEARS;
	}
	
	for(int i = 0; i < MONTHS; i++)
	{
		cout << "The average rainfall for month " << i + 1 << " is " << monthlyRainfall[i] << endl;
	}
}

void findRange(const double rainfall[][MONTHS], double min, double max)
{
	for(int i = 0; i < YEARS; i++)
	{
		for(int j = 0; j < MONTHS; j++)
		{
			if(rainfall[i][j] >= min && rainfall[i][j] <= max) //if a month is within the range,
			{
				   cout << "Month " << j + 1 << " of year " << i + 2019 << " falls within the given range." << endl; //mention that that is the case.
			}
		}
	} 
}
