/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#include <iostream>
#include "Account.h"

using namespace std;
namespace sict {

Account::Account(double bal_src) : iAccount()
{
	if (bal_src > 0) {
		bal = bal_src;
	}
	else
		bal = 0.00;
}

bool Account::credit(double amount)
{
	if (amount > 0) {
		bal += amount;
		return true;
	}
	else return false;
	
}

bool Account::debit(double amount)
{
	if (amount > 0 && this->bal > amount) {
		bal -= amount;
		return true;
	}
	else return false;
}

double Account::balance() const
{
	return this->bal;
}

}
