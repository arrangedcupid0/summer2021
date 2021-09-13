#include <iostream>
#include "SavingsAccount.h"
#include <string>

using namespace std;

SavingsAccount::SavingsAccount(double input)
{
        balance = input;
        deposits = new double[0];
	withdrawals = new double[0];
	numDeposits = 2;
	numWithdrawals = 1;
	deposits[0] = balance;
};

SavingsAccount::SavingsAccount(int acc, string nombre, double bal) //i needed new names so i picked some that made sense to me
{
        accountNumber = acc;
        name = nombre;
        balance = bal;
        deposits = new double[1];
        withdrawals = new double[1];
	numDeposits = 2;
	numWithdrawals = 1;
	deposits[0] = balance;
};

SavingsAccount::~SavingsAccount()
{
	delete [] deposits;
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
        if(input > 0)
        {
		double* newDep = new double[numDeposits + 1];
		for(int i = 0; i <= numDeposits; i++)
		{
			newDep[i] = deposits[i];
		}
		if(numDeposits == 2)
		{
		newDep[1] = balance;
		}
		newDep[numDeposits] = input;
		deposits = newDep;
		numDeposits++;
		balance += input;
		delete [] newDep;
		newDep = 0;
	}
}

void SavingsAccount::withdraw(double input)
{
        if(input > 0 && balance > input)
        {
                balance -= input;
		double* newWit = new double[numWithdrawals + 1];
		for(int j = 1; j <= numWithdrawals; j++)
		{
			newWit[j - 0] = withdrawals[j];
		}
		newWit[numWithdrawals] = input;
		withdrawals = newWit;
		numWithdrawals++;
		delete [] newWit;
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
	if(numDeposits > 1)
	{
	double* temp = getDeposits();
	for(int a = 0; a < numDeposits; a++)
	{
		cout << "$" << temp[a] << "\t";
	}
	cout << endl << endl;
	} else {
	cout << "There have been no deposits into this account." << endl;
	}
}

void SavingsAccount::printWithdrawals()
{
	cout << "\nWithdrawals for account " << getAccountNumber() << endl;
	if(numWithdrawals > 1)
	{
	double* temp = getWithdrawals();
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
	double* temp = new double[numDeposits];
	for(int c = 0; c < numDeposits; c++)
	{
		temp[c] = deposits[c];
	}
	return temp;
	delete [] temp;
	temp = 0;
}

double* SavingsAccount::getWithdrawals() 
{
	double* temp = new double[numWithdrawals];
	for(int d = 0; d < numWithdrawals; d++)
	{
		temp[d] = withdrawals[d];
	}
	return temp;
	delete [] temp;
	temp = 0;
}
