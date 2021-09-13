#include "Rectangle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Rectangle::setWidth(double w)
{
	if (w >= 0)
	{
		width = w;
	} else {
		cout << "Invalid width\n";
		exit(EXIT_FAILURE);
	}
}

void Rectangle::setLength(double l)
{
	if (l >= 0)
	{
		length = l;
	} else {
		cout << "Invalid length\n";
		exit(EXIT_FAILURE);
	}
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getLength() const
{
	return length;
}

double Rectangle::getArea() const
{
	return width * length;
}
