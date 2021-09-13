//Michael Stoll COSC 1030
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int standardSlices = 8;
const double pizzaCost = 6.5;

	double   people, //how many people are being fed
		 slices,//how many slices that will require
		 pizzas, //how many pizzas that will require
		 cost, //how much that will cost
		 discount, //how much of a discount the user gets
		 percentOff, //how much money that discount saves the user
		 finalCost; //how much the user will have to pay

	int totalPizzas, //how many total pizzas will need to be bought
	 remainingSlices; //how many slices will be left over after everyone is fed

int main() {
  cout << "Hi, welcome to Pizza Hut.\n";

  cout << "\nHow many people are you feeding?\n";
	  cin >> people;
  cout << "\nAnd how many slices will they be having each?\n";
 	 cin >> slices;
 
  pizzas = (people * slices) / static_cast<double>(standardSlices);
  
  totalPizzas = ceil(pizzas);
 
  cost = totalPizzas * pizzaCost;
 
  remainingSlices = static_cast<int>(slices) % standardSlices;
 
  discount = rand() % 40 + 11;
 
  percentOff = (discount / 100) * cost;
 
  finalCost = cost - percentOff;

  cout << setprecision(2) << "\nSo for " << people << " people and " << slices << " per person, \nyou will need " << pizzas << " pizzas, so you need to buy " << totalPizzas << " total pizzas.\nThis will cost you " << cost << " dollars and you will have " << remainingSlices << " slices left over.\n";
  cout << "However, we are having a discount today. Yours is " << discount << "%. \nSo, with the discount of $" << percentOff << ", your final total today is $" << finalCost << ".\n";
}
