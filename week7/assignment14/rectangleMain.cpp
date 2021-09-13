#include "Rectangle.h"
#include <iostream>
#include <fstream>

using namespace std;

double findTotalArea(Rectangle *, int);
Rectangle* findSmall(Rectangle *, int, double, int &);
void printRectangle(Rectangle *, int);

int main()
{
	ifstream RectangleFile;
	string location; //it's important to note that this requires a full address (i.e. /home/pi/Downloads/...)
	cout << "Please enter the full address of the rectangle file:" << endl;
	cin >> location;
	RectangleFile.open(location);
	
	bool eof = false; //tells me when the file is empty
	int rectNum = 0; //holds the number of rectangles
	double total = 0; //total area
	double max = 0; //used with findSmall
	int newCount = 0; //size of the smaller array
	Rectangle* smaller; //holds the rectangles that have a dimension smaller than the user's input
	
	while(!eof)
	{
		if(RectangleFile.eof()) //if the file has ended break the while loop
		{
			eof = true;
		} else {
		string burner; //this burner is just for the sake of iterating through the entire file to increment rectNum
		RectangleFile >> burner;
		rectNum++;
		}
	}

	RectangleFile.close(); //i have to reset the file because I've already iterated all the way through it
	RectangleFile.open(location);

	rectNum /= 2; //the number I have is the amount of inputs, but each rectangle takes two inputs, so the number of rectangles is inputs / 2

	Rectangle* rectangles = new Rectangle[rectNum];

	for(int i = 0; i < rectNum; i++)
	{
		Rectangle temp;
		double tempWidth;
		double tempLength;

		RectangleFile >> tempLength;
		RectangleFile >> tempWidth;
		if(tempWidth >= 0 && tempLength >= 0) //this is just a precaution, i don't want the program to break with an invalid input
		{
		temp.setWidth(tempWidth);
		temp.setLength(tempLength);
		rectangles[i] = temp;
		}
	}

	total = findTotalArea(rectangles, rectNum);

	cout << "\nRight on. The total area of the rectangles in that file is: " << total << endl << endl;

	cout <<"Input a size, and this program will find every rectangle with a dimension smaller than that number: ";
	cin >> max;

	smaller = findSmall(rectangles, rectNum, max, newCount);

	cout << "These are the rectangles that are smaller than " << max << " in one or more dimensions:" << endl;
	
	printRectangle(smaller, newCount);


	RectangleFile.close();

	return 0;
	delete [] rectangles;
	rectangles = 0;
}

double findTotalArea(Rectangle* masterList, int count)
{
	double total = 0;
	for(int k = 0; k < count; k++)
	{
		Rectangle temp;
		double tempWidth, tempLength, tempArea; //i'm using all of these temp variables to temporarily pull values from the rectangle array
		temp = masterList[k];
		tempWidth = temp.getWidth();
		tempLength = temp.getLength();
		tempArea = tempWidth * tempLength;
		
		total += tempArea;
	}
	return total;
}

Rectangle* findSmall(Rectangle* masterList, int count, double size, int& newCount)
{
	int counter = 0;

	for(int m = 0; m < count; m++) //iterates through the array to give me a size for my small array
	{
		if(masterList[m].getWidth() <= size || masterList[m].getLength() <= size)
		{
			counter++;
		} 
	}

	newCount = counter;

	counter = 0; //after the value is transfered to newCount, I recycle the variable. gotta prevent it from ending up in a landfill

	Rectangle* smalls = new Rectangle[newCount];
	for(int l = 0; l < count; l++)
	{
		if(masterList[l].getWidth() <= size || masterList[l].getLength() <= size) //if either measurement is smaller than the target size, add that bad boy to the array
                { 
                        smalls[counter] = masterList[l];
			counter++;
                } 
	}
	return smalls;
	delete [] smalls;
	smalls = 0;
}

void printRectangle(Rectangle* masterList, int count)
{
	for(int j = 0; j < count; j++) //the rectangle number designation is not what number in the file it corresponds to; instead, it is simply a visual indicator of how many there are
	{
		cout << "Rectangle " << (j + 1) << " has a length of " << masterList[j].getLength() << " and a width of " << masterList[j].getWidth() << "." << endl;
	}
}
