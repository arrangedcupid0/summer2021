//Michael Stoll COSC 1030 06/27/21
#include <iostream>
using namespace std; 

const double PI = 3.14159;
void printMenu();
int getChoice();
double getPositiveDouble(string);
double calculateSphereVolume();
double calculateCylinderVolume();
double calculateTriangularPrismVolume();
double calculateRectangularPrismVolume();
double calculateConeVolume();
void printResult(double, string);

int main()
{
	int choice = 0;
	double vol; 
	string shape;
	while (choice != 6)
	{
		printMenu(); // prints out the Menu of choices	
		choice = getChoice(); // gets the user's choice 
		switch (choice)
		{
			case 1: // sphere;
				vol = calculateSphereVolume();
				shape = "sphere";
				break;
			case 2: // cylinder
				vol = calculateCylinderVolume();
				shape = "cylinder";
				break;
			case 3: // triangularPrism
				vol = calculateTriangularPrismVolume();
				shape = "triangularPrism";
				break;
			case 4: //rectangular prism
				vol = calculateRectangularPrismVolume();
				shape = "rectangularPrism";
				break;
			case 5:	// cone
				vol = calculateConeVolume();
				shape = "cone";
				break;	
			case 6:
				cout << "Goodbye";
		}
		if (choice != 6)
			printResult(vol, shape);
		}
}
 
/* 
 * printMenu()
 *  prints the menu options for the program
 */
void printMenu()
{
 	cout << "This program calculates the following volumes: " << endl;
 	cout << "1. sphere" << endl;
 	cout << "2. cylinder" << endl;
 	cout << "3. triangular prism" << endl;
 	cout << "4. rectangular prism" << endl;
 	cout << "5. cone" << endl;
 	cout << "6. quit" << endl;
 	cout << "Type the number of your selection here: ";
}

/*
 * getChoice
 *   checks to see that user input is between 1 and 5 or asks for another input
 *   returns a number between 1 and 6
 */
int getChoice()
{
	int input;
	cin >> input;
	while(input > 6 || input < 1)
	{
		cout << "Please enter a valid input:";
		cin >> input;
	}
	return input;
}

/*
 * getPositiveDouble
 *  returns a double that is greater than 0, performs input validation
 *  uses the input string for the user prompt when needed
 */ 
double getPositiveDouble(string attribute)
{
	double number;
	do
	{
		cout << "\nPlease enter a positive number for the " << attribute << ": ";
		cin >> number;
	} while(number <= 0);
	return number;
}

/*
 * calculateSphereVolume
 *  prompts the user for the dimensions of the sphere.  Uses getPositiveDouble to do input validation
 *  computes and returns the sphere volume
 */
 
double calculateSphereVolume() 
{
	double rad, //radius of sphere
	       volume; //total volume of sphere
	
	cout << "Please enter the radius of the sphere: ";
	cin >> rad;
	if(rad <= 0)
	{
		rad = getPositiveDouble("radius");
	}
	volume = (4 * rad * rad * rad * PI) / 3;
	return volume;
}

/* 
 * calculateCylinderVolume
 *  prompts the user for the dimensions of the cylinder. Uses getPositiveDouble to do input validation
 *  computes and returns the cylinder volume
 */

double calculateCylinderVolume()
{
	double rad, //radius of circle base
	       height, //height of cylinder
               volume; //total volume

        cout << "Please enter the radius of the base: ";
        cin >> rad;
        if(rad <= 0)
        {
                rad = getPositiveDouble("radius");
        }
	cout << "Please enter the height: ";
	cin >> height;
	if(height <= 0)
	{
		height = getPositiveDouble("height");
	}
        volume = PI * rad * rad * height;
        return volume;

}

/*
 * calculateTriangularPrismVolume
 *  prompts the user for the dimensions of the triangular prism.  Uses getPositiveDouble to do input validation
 *  computes and reutnrs the triangular prism volume.
 */
double calculateTriangularPrismVolume()
{
	double  base, //length of base of triangle
                height, // length of height of triangle
                length, //length in the third dimension
                volume; // total volume

        cout << "Please enter the base length of the triangle face: ";
        cin >> base;
        if(base <= 0)
        {
                base = getPositiveDouble("base");
        }
        cout << "Please enter the height length of the triangle face: ";
        cin >> height;
        if(height <= 0)
        {
                height = getPositiveDouble("height");
        }
        cout << "Please enter the length: ";
        cin >> length;
        if(length <= 0)
        {
                length = getPositiveDouble("length");
        }

        volume = .5 * base * height * length;
        return volume;

}

/*
 * calculateRectangularPrismVolume
 *  prompts the user for the dimensions of a rectangular prism.  Uses getPositiveDouble to do input validation
 *  computes and returns the volume of the rectangular prism
 */
double calculateRectangularPrismVolume()
{
	double  base, //length of base of face
                height, //length of height of face
                length, //length in the unmentioned third dimension
                volume; //total volume

        cout << "Please enter the base length of the face: ";
        cin >> base;
        if(base <= 0)
        {
                base = getPositiveDouble("base");
        }
        cout << "Please enter the height length of the face: ";
        cin >> height;
        if(height <= 0)
        {
                height = getPositiveDouble("height");
        }
        cout << "Please enter the length: ";
        cin >> length;
        if(length <= 0)
        {
                length = getPositiveDouble("length");
        }

        volume = base * height * length;
        return volume;


}

/*
 *calculateConeVolume
 * prompts the user for the dimensions of a cone. Uses getPositiveDouble to do input validation
 * computes and returns the volume of the cone
 */
double calculateConeVolume()
{
	double rad, //radius of circle base
	       height, //height of cone
               volume; //total volume

        cout << "Please enter the radius of the base: ";
        cin >> rad;
        if(rad <= 0)
        {
                rad = getPositiveDouble("radius");
        }
	cout << "Please enter the height: ";
	cin >> height;
	if(height <= 0)
	{
		height = getPositiveDouble("height");
	}
        volume = (PI * rad * rad * height) / 3;
        return volume;

}
/*
 * printResult
 *  creates a print out using the input vol and the shape input which holds the string describing the shape
 */
void printResult(double vol, string shape)
{
 cout << "-----------------------------" << endl;
 cout << "The volume of the " << shape << " is: " << vol << endl;
 cout << "-----------------------------" << endl << endl;
}
