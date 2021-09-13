#include <iostream>
#include "SavingsAccount.h"
#include <string>

using namespace std;

SavingsAccount::SavingsAccount()
{
	accountNumber = 0;
	name = "";
	balance = 0.00;
	for(int l = 0; l < MAX; l++)
	{
		maxDeposit[l] = 0;
	}
};

SavingsAccount::SavingsAccount(double input)
{
	balance = input;
        for(int l = 0; l < MAX; l++)
        {
                maxDeposit[l] = 0;
        }

};

SavingsAccount::SavingsAccount(int acc, string nombre, double bal) //i needed new names so i picked some that made sense to me
{
	accountNumber = acc;
	name = nombre;
	balance = bal;
        for(int l = 0; l < MAX; l++)
        {
                maxDeposit[l] = 0;
        }

};

void SavingsAccount::setName(string nombre)
{
	name = nombre;
}
		
void SavingsAccount::setAccountNumber(int acc)
{
	accountNumber = acc;
}

void SavingsAccount::setBalance(double bal)
{
	balance = bal;
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
		balance += input;
	}
	bool changedList = false;	//if an input changes the list once I don't want it to do so twice, this boolean serves to stop the same value from populating the board
	for(int i = 0; i < MAX; i++)
	{
		if(input > maxDeposit[i] && !changedList)
		{
			maxDeposit[i] = input;
			changedList = true; 
		}
	}
}

void SavingsAccount::withdraw(double input)
{
	if(input > 0 && balance >= input)
	{
		balance -= input;
	}
}

void SavingsAccount::printAccountInfo()
{
	cout << "\nAccount holder: " << getName();
	cout << "\nAccount number: " << getAccountNumber();
	cout << "\nBalance: " << getBalance();
	cout << "\nThe three biggest deposits were: " << endl;
	for(int k = 0; k < MAX; k++)
	{
		cout << maxDeposit[k] << "\t";
	}
	cout << endl << endl;
}

double* SavingsAccount::getMax() 
{
	for(int j = 0; j < MAX; j++)
	{
		maxDepositCopy[j] = maxDeposit[j];
	}
	return maxDepositCopy;
}

