//Michael Stoll, COSC 1030
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  const double price = 15.75;
  int shirts; //number of shirts
  double newPrice, //price after discount
	 discount, //discount based on quantity of shirts
	 cost; //total cost the user would have to pay


  cout << "Welcome to Bert's Custom Shirts.\nHow many t-shirts would you like?" << endl;
  cin >> shirts;
  if(shirts < 1 || shirts > 300) 
  {
  cout << "Sorry, that is an invalid amount." << endl;
  }
  if(shirts >= 1 && shirts <= 10)
  {
  cost = shirts * price;
  cout << fixed << showpoint << setprecision(2) << "Your total for that will be $" << cost << endl; //i threw in fixed, showpoint, and setprecision so that the number that appears will be a dollar amount that a user would be familiar with
  }
  if(shirts >= 11 && shirts <= 30)
  {
    newPrice = .95 * price; //discount is 5%, 100% - 5% = 95%
    cost = shirts * newPrice;
    cout << fixed << showpoint << setprecision(2) << "Since you're ordering in bulk, your new price per shirt is $" << newPrice << " and\nYour total for that will be $" << cost << endl;
  }
  if(shirts >= 31 && shirts <= 55)
  {
    newPrice = .9 * price;
    cost = shirts * newPrice;
    cout << fixed << showpoint << setprecision(2) << "Since you're ordering in bulk, your new price per shirt is $" << newPrice << " and\nYour total for that will be $" << cost << endl;
  }
  if(shirts > 55 && shirts <= 300)
  {
    newPrice = .75 * price;
    cost = shirts * newPrice;
    cout << fixed << showpoint << setprecision(2) << "Since you're ordering in bulk, your new price per shirt is $" << newPrice << " and\nYour total for that will be $" << cost << endl;
  }


  }
