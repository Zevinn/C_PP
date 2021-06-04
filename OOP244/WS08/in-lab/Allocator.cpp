/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#include <iostream>
#include "iAccount.h"
#include "SavingsAccount.h"


namespace sict {
	const double interest = 0.05;
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *p = nullptr;
		if (type[0] == 'S') {
			p = new SavingsAccount(balance, interest);
			return p;
		}
		else return nullptr;
	}
}

