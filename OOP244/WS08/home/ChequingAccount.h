/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef CHEQUINGACCOUNT_H__
#define CHEQUINGACCOUNT_H__
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
		double transFee;
		double monthlyFee;
	public:
		ChequingAccount(double bal_s, double trFee_s, double mthFee_s);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& out) const;

	};

}









#endif

