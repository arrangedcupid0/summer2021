#include <iostream>
#include "SavingsAccount.h"
using namespace std;


int main()
{
  cout << "\n\n";
  cout << "Testing constructor    SavingsAccount account2(645.90);\n";
  SavingsAccount account2(645.90);
  account2.setName("Jared Bowden");
  account2.setAccountNumber(981240);
  cout << "Printing account information for account2\n";
  account2.printAccountInfo(); 
  cout << "Making 4 deposits 1678.89,  234.56, 50.78, 60.45\n";
  account2.deposit(1678.89);
  account2.deposit(234.56);
  account2.deposit(50.78); 
  account2.deposit(60.45); 
  cout << "Printing account2 deposits\n";
  account2.printDeposits();
  cout << "Making 3 withdrawals: 100.34, 45.60, 78.90\n";
  account2.withdraw(100.34);
  account2.withdraw(45.60);
  account2.withdraw(78.90);
  cout << "Printing account2 withdrawals \n";
  account2.printWithdrawals(); 


  cout << "\n\nTesting the constructor:  SavingsAccount account3(558928,"
        << "\"Teresa Strickland\", 3900.32); ";
  SavingsAccount account3(558928, "Teresa Strickland", 3900.32);
  cout << "Printing account3 info\n";
  account3.printAccountInfo(); 
  cout << "Attempting to deposit a negative amount\n";
  account3.deposit(-10.00);
  cout << "current balance " << account3.getBalance() << endl;
  cout << "Attempting to withdraw a negative amount\n";
  account3.withdraw(-10.00); 
  cout << "current balance " << account3.getBalance() << endl;
  cout << "Attempting to withdraw more than is in the account\n";
  account3.withdraw(5000.00);
  cout << "current balance "  << account3.getBalance() << endl;
  cout << "printing deposits\n";
  account3.printDeposits();
  cout << "printing withdrawals\n";
  account3.printWithdrawals(); 

  cout << "\nTesting management of deposits array, ";
  cout << "Printing account2 deposits\n";
  account2.printDeposits();
  double *ptr = account2.getDeposits();
  ptr[0] = 60.34;
  cout << "Printing account2, deposits should not have changed\n"; 
  account2.printDeposits(); 

  cout << "\nTesting management of withdrawals array, ";
  cout << "Printing account2 withdrawals:\n";
  account2.printWithdrawals();
  double *nptr = account2.getWithdrawals(); 
  nptr[0] = 23.65;
  cout << "Printing account2, withdrawals array, should not have changed\n";
  account2.printWithdrawals(); 
  return 0; 
}
