/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#include <iostream>
#include "SavingsAccount.h"

sict::SavingsAccount::SavingsAccount(double bal_src, double intRate_src) : Account(bal_src)
{
	if (intRate_src > 0) {
		interestRate = intRate_src;
	}
	else interestRate = 0.0;
}

void sict::SavingsAccount::monthEnd()
{
	double rate = balance() * interestRate;
	credit(rate);
}

void sict::SavingsAccount::display(std::ostream & out) const
{
	out << "Account type: Savings" << std::endl;
	out.setf(std::ios::fixed);
	out.precision(2);
	out.width(7);
	out << "Balance: $";
	out << balance() << std::endl;
	out << "Interest Rate (%): " << this->interestRate*100;
	out << std::endl;
	out.precision(6);
}
