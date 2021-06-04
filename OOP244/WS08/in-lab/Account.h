/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef ACCOUNT_H__
#define ACCOUNT_H__

#include <iostream>
#include "iAccount.h"

namespace sict {
	class Account : public iAccount {
		double bal;
	public:
		Account(double bal_src);
		bool credit(double amount);
		bool debit(double amount);
	protected:
		double balance() const;
	};
}




#endif 

