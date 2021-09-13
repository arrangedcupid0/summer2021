#include <iostream>
#include "SavingsAccount.h"
#include <string>


using namespace std;

SavingsAccount::SavingsAccount(double input)
{
        balance = input; 
        deposits = new double[2]; //every deposits array starts with room for two values, because it needs to have room for the initial deposit and the new value it may be given
	withdrawals = new double[1]; //every withdrawals array starts with room for one, because it needs to have room just for the new value it may be given
	numDeposits = 2; //and we start the counter in the third spot for the array, which is actually the second once it is passed through deposit()
	numWithdrawals = 1; //and withdrawals starts one behind that, for the reason stated above
	deposits[1] = balance; //I'm initializing balance to be the second spot in the array because the code doesn't like when I put it in the first.
};

SavingsAccount::SavingsAccount(int acc, string nombre, double bal) //i needed new names so i picked some that made sense to me
{
        accountNumber = acc; //read the above constructor notes, they all apply
        name = nombre;
        balance = bal;
        deposits = new double[2];
        withdrawals = new double[1];
	numDeposits = 2;
	numWithdrawals = 1;
	deposits[1] = balance;
};

SavingsAccount::~SavingsAccount()
{
	delete [] deposits; //the next few are self explanitory
	deposits = 0;
	delete [] withdrawals;
        withdrawals = 0;
}

void SavingsAccount::setName(string nombre)
{
        name = nombre;
}

void SavingsAccount::setAccountNumber(int acc)
{
        accountNumber = acc;
}

string SavingsAccount::getName() const
{
        return name;
}

int SavingsAccount::getAccountNumber() const
{
        return accountNumber;
}

double SavingsAccount::getBalance() const
{
        return balance;
}

void SavingsAccount::deposit(double input)
{
        if(input > 0) //as long as the input is a positive number
        {
		double* newDep = new double[numDeposits + 1]; //make a new array one integer bigger than the old deposits array
		for(int i = 1; i <= numDeposits; i++)
		{
			newDep[i] = deposits[i]; //copy the old array over
		}
		if(numDeposits == 2) //if it's the beginning of the array, put balance in as the second member
		{
			newDep[1] = balance;
		}
		newDep[numDeposits] = input; //put the new deposit in as the last member, a member that is outside the scope of the previous array
		deposits = newDep; //change the pointer over so that this new array becomes the deposits array
		numDeposits++; //increment relevent variables
		balance += input;
		delete [] newDep; //and deallocate memory
		newDep = 0;
	}
}

void SavingsAccount::withdraw(double input)
{
        if(input > 0 && balance >= input) //as long as the input is positive and less than the total balance
        {
                balance -= input;
		double* newWit = new double[numWithdrawals + 1]; //make a new array one integer bigger than the old withdrawals array
		for(int j = 1; j <= numWithdrawals; j++)
		{
			newWit[j] = withdrawals[j]; //copy the old array over 
		}
		newWit[numWithdrawals] = input; //put the new withdrawal in as the last member
		withdrawals = newWit; //change the pointer over, increment relevent variables
		numWithdrawals++;
		delete [] newWit; //and deallocate memory
		newWit = 0;
	}
}

void SavingsAccount::printAccountInfo()
{
        cout << "\nAccount holder: " << getName();
        cout << "\nAccount number: " << getAccountNumber();
        cout << "\nBalance: " << getBalance() << endl;
}

void SavingsAccount::printDeposits()
{
	cout << "\nDeposits for account " << getAccountNumber() << endl;
	if(numDeposits > 1) //keep in mind, for the purposes of this program 1 = 0
	{
	double* temp = getDeposits(); //make a temp array (so we aren't accidentally messing with deposits itself
	for(int a = 1; a < numDeposits; a++)
	{
		cout << "$" << temp[a] << "\t"; //print it out (with formatting)
	}
	cout << endl << endl;
	}else { //or, if there haven't been deposits
	cout << "There have been no deposits into this account." << endl;
	}
}

void SavingsAccount::printWithdrawals()
{
	cout << "\nWithdrawals for account " << getAccountNumber() << endl;
	if(numWithdrawals > 1) //again, 1 = 0
	{
	double* temp = getWithdrawals(); //make a temp array, yada yada yada. it's all the same as before
	for(int b = 1; b < numWithdrawals; b++)
        {
                cout << "$" << temp[b] << "\t";
        }
        cout << endl << endl;
	} else {
	cout << "There have been no withdrawals from this account." << endl;
	}

}

double* SavingsAccount::getDeposits() 
{
	double* temp = new double[numDeposits]; //make a new temp array so that you don't mess with deposits
	for(int c = 0; c < numDeposits; c++)
	{
		temp[c] = deposits[c]; //copy over deposits
	}
	return temp;
	delete [] temp; //deallocate memory
	temp = 0;
}

double* SavingsAccount::getWithdrawals() 
{
	double* temp = new double[numWithdrawals]; //manage your data properly
	for(int d = 0; d < numWithdrawals; d++)
	{
		temp[d] = withdrawals[d]; //copy over withdrawals
	}
	return temp;
	delete [] temp; //deallocate memory
	temp = 0;
}
