//Michael Stoll, COSC 1030 6/23/21
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{	const double MONTHLY_INTEREST = .014/12; //yearly interest rate divided by 12 for months

	char tra; //short for transaction, input should be either 'd' or 'w'

	int      numDep = 0, //number of deposits
		 numWit = 0, //number of withdrawls
		 prevMonth = 0, //what month was the last transaction held in 
		 month; //which month of the year it is, 1-12

	double   interest, //a temporary variable to add that month's interest to the balance
		 totalInterest, //total interest earned on balance
		 bal = 0, //account balance, initialized at 0
		 amt, //amount being transacted
		 totalDep = 0, //total amount deposited, initialized at 0
		 totalWit = 0; //total amount withdrawn, initialized at 0

	bool eof = false; //to stop the while loop from continuing past its scope

	ifstream bankRecord; //the next two lines just open up bankRecord.txt
	bankRecord.open("/home/pi/Downloads/bankRecord.txt");
	while(!eof) //while we have not reached the end of the file
	{
		bankRecord >> tra; //these three lines read the character, month, and amounts from the .txt file
		bankRecord >> month;
		bankRecord >> amt;
		if(bankRecord.eof())
		{
			eof = true;
		}
                if(month != prevMonth) //if the month of this transaction is not the same as the month of the previous transaction
                {
                       	interest = (bal * MONTHLY_INTEREST); //the interest for the month is stored in the temp interest variable
			bal += interest; //that temporary variable is added to balance,
			totalInterest += interest; //as well as the totalInterest total.
                }
		switch(tra) //this is where we find out if a transaction is a deposit or a withdrawl
		{
			case'd': totalDep += amt; //if it's a deposit, add that amount to the total deposit variable,
				bal += amt; 	 //the balance variable,
				numDep++;       //and count up on the amount of deposits
				break;	       //then break.
			case'w': totalWit += amt; //if it's a withdrawl, add that amount to the total wthdrawl variable,
				bal -= amt;	 //subtract it from the balance variable,
				numWit++;	//and count up on the amount of deposits
				break;	       //then break.
			default: cout << "Invalid transaction ID." << endl; //if the transaction isn't labeled deposit or withdrawl, the program throws an
		}							   //error and ignores the transaction
		prevMonth = month; //set the previous month variable to this month's value, for use in  the next iteration of the while loop
	} 
	cout << fixed << setprecision(2) << "The account balance is $" << bal << endl; //setprecision(2) because I want it in a familiar $xx.xx format
									              //fixed because, though this file doesn't have any big amounts,
										     //the program will continue to show fixed point notation
										    //even if the user transfers a lot of money in a year
	cout << "The total number of deposits is " << numDep << " for a total of $" << totalDep << endl; //and these three lines just output the variables that 
	cout << "The total number of withdrawls is " << numWit << " for a total of $" << totalWit << endl; //were created in the previous lines
	cout << "Total interest earned is $" << totalInterest << endl; 
}
