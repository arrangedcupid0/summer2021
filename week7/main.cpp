#include <iostream>
#include "SavingsAccount.h"
using namespace std;


int main()
{
  cout << "Testing the default constructor\n";
  SavingsAccount account1;
  cout << "Depositing 123.45" << endl; 
  account1.deposit(123.45);
  account1.setName("Paul Marquard");
  account1.setAccountNumber(33445566);
  cout << "Printing out the account information\n";
  account1.printAccountInfo(); 

  cout << "\n\n";
  cout << "Testing constructor    SavingsAccount account2(645.90);\n";
  SavingsAccount account2(645.90);
  account2.setName("Jared Bowden");
  account2.setAccountNumber(981240);
  cout << "Printing account information for account2\n";
  account2.printAccountInfo(); 
  cout << "Changing the balance to 1045.89" << endl;
  account2.setBalance(1045.89); 
  cout << "Printing account info" << endl;
  account2.printAccountInfo();
  cout << "Making 4 deposits 1678.89,  234.56, 50.78, 60.45\n";
  account2.deposit(1678.89);
  account2.deposit(234.56);
  account2.deposit(50.78); 
  account2.deposit(60.45); 
  cout << "Printing account2 information\n";
  account2.printAccountInfo(); 

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

  cout << "\n\n Testing management of maxDeposit array";
  cout << "Printing account2\n";
  account2.printAccountInfo();
  double *ptr = account2.getMax();
  ptr[0] = 60.34;
  cout << "Printing account2, maxDeposits should not have changed\n"; 
  account2.printAccountInfo();



  return 0; 
}
