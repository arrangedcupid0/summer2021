#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <string>
#include <iostream>

using namespace std;

class SavingsAccount
{
        private:
                static const int MAX = 3;
                string name;
                int accountNumber;
                double balance;
                double maxDeposit[MAX];
		double maxDepositCopy[MAX];
        public:
                SavingsAccount();

                SavingsAccount(double);

                SavingsAccount(int acc, string, double bal);

                void setName(string nombre);

                void setAccountNumber(int acc);

                void setBalance(double bal);

                string getName() const;

                int getAccountNumber() const;

                double getBalance() const;

                void deposit(double input);

                void withdraw(double input);

                void printAccountInfo();

                double* getMax();


};
#endif
