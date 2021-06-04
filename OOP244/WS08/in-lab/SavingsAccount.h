/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef SAVINGSACCOUNT_H__
#define SAVINGSACCOUNT_H__

#include <iostream>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double interestRate;
	public:
		SavingsAccount(double bal_src, double intRate_src);
		void monthEnd();
		void display(std::ostream& out) const;
	};

}



#endif
