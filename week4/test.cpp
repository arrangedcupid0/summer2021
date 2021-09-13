//Michael Stoll, COSC 1030 6/23/21
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{       const double MONTHLY_INTEREST = .014/12; //yearly interest rate divided by 12 for months


        char tra; //short for transaction, input should be either 'd' or 'w'

        int      next,
		 numDep, //number of deposits
                 numWit, //number of withdrawls
                 prevMonth, //what month was the last transaction held in 
                 month;  //which month of the year it is, 1-12

        double   interest, //total interest earned on balance
		 bal = 0, //account balance, initialized at 0
                 amt; //amount being transacted

        ifstream bankRecord; //the next two lines just open up bankRecord.txt
        bankRecord.open("/home/pi/Downloads/bankRecord.txt");
        do  //I want the code to itere through all of the available entries, so as long as there is a value to iterate through it will.
        {
                bankRecord >> tra;
                bankRecord >> month;
                bankRecord >> amt;
	if( bankRecord.eof() )  break;

	cout << tra << " " << month << " " << amt << endl;
	} while(!bankRecord.eof());  //I want the code to iterate through all of the available entries, so as long as there is a value to iterate through it will.
 

}
