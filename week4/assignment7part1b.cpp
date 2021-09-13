//Michael Stoll COSC 1030 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string monthsUsed[] = {"January", "February", "March", "April"};
	int months = 4;
	int years = 3;
	double rainfall[years][months];
	char input;

	cout << "There are " << months << " months." << endl;

	cout << "Do you want to input the data manually, or open a file? (M or F)" << endl;
		cin >> input;
	switch(input)
	{
		case 'M':
			{ for(int k = 0; k < years; k++)
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
			  cout << "Input your file location." << endl;
			  cin >> location;
			  rainfallFile.open(location);
			for(int a = 0; a < years; a++)
			{
				for(int b = 0; b < months; b++)
				{
					rainfallFile >> rainfall[a][b];
				}
			}
			}
			break;
		default: cout << "Please enter a valid input." << endl;
			exit(0);
	}


			for(int i = 0; i < years; i++)
                        {
                                for(int j = 0; j < months; j++) 
                                {
                                       cout << rainfall[i][j];
                                }
                        }



	double monthlyRainfall[months];

	for(int i = 0; i < months; i++)
	{
		int temp = 0;
		for(int j = 0; j < years; j++)
		{
			temp += rainfall[j][i]; 
		}
		monthlyRainfall[i] = temp / years;
	}
	
	for(int i = 0; i < months; i++)
	{
		cout << "The average rainfall for month " << i + 1 << " is " << monthlyRainfall[i] << endl;
	}
}
  
