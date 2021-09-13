//Michael Stoll COSC 1030 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string monthsUsed[] = {"January", "February", "March", "April"};
	int months = 4, //total amount of months
	    years = 3; //total amount of years
	double rainfall[years][months];
	char input; //determines where the data comes from

	cout << "Do you want to input the data manually, or open a file? (M or F)" << endl;
		cin >> input;
	switch(input)
	{
		case 'M':
			{ for(int k = 0; k < years; k++) //I feel like this format is more user friendly than having an input of every january, then every february, etc.
			 {
				cout << "This data is for year " << k + 2019 << endl;
				for(int j = 0; j < months; j++)
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
			  cout << "Input your full file location. (i.e. /home/pi/Downloads/...)" << endl; //it's important to note that the full address has to be input
			  cin >> location;
			  rainfallFile.open(location); 
	        	 for(int a = 0; a < years; a++) //this is a set of for loops that populate the 2d array with the numbers from a file,
                        {
                                for(int b = 0; b < months; b++) // granted that said file has the correct formatting
                                {
                                        rainfallFile >> rainfall[a][b];
                                }
                        }
			}
			break;
		default: cout << "Please enter a valid input." << endl;
			exit(0);
	}

	double monthlyRainfall[months];

	for(int i = 0; i < months; i++)
	{
		double temp = 0;
		for(int j = 0; j < years; j++)
		{
			temp += rainfall[j][i]; //temp variable used to add up values before division 
		}
		monthlyRainfall[i] = temp / years;
	}
	
	for(int i = 0; i < months; i++)
	{
		cout << "The average rainfall for month " << i + 1 << " is " << monthlyRainfall[i] << endl;
	}
}
