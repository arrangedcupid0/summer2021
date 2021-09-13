#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <string>
#include <iostream>

using namespace std;

class SavingsAccount
{
        private:
                string name;
                int accountNumber;
                double balance;
		double* deposits;
		double* withdrawals;
		int numDeposits;
		int numWithdrawals;
        public:
                SavingsAccount(double);

                SavingsAccount(int acc, string, double bal);

		~SavingsAccount();

                void setName(string nombre);

                void setAccountNumber(int acc);

                string getName() const;

                int getAccountNumber() const;

                double getBalance() const;

                void deposit(double input);

                void withdraw(double input);

		double* getDeposits();

		double* getWithdrawals();

                void printAccountInfo();

                void printDeposits();

		void printWithdrawals();

};
#endif
