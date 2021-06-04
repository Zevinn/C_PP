/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/

#include "ChequingAccount.h"

sict::ChequingAccount::ChequingAccount(double bal_s, double transFee_s, double monthlyFee_s) : Account(bal_s)
{
	if (transFee_s > 0) transFee = transFee_s;
	else transFee = 0.0;

	if (monthlyFee_s > 0) monthlyFee = monthlyFee_s;
	else transFee = 0.0;
}

bool sict::ChequingAccount::credit(double amount)
{
	if (Account::credit(amount)) {
		if (Account::debit(transFee)) return true;
		else return false;
	}
	else return false;
}

bool sict::ChequingAccount::debit(double amount)
{
	if (Account::debit(amount)) {
		if (Account::debit(transFee)) return true;
		else return false;
	}
	else return false;
}

void sict::ChequingAccount::monthEnd()
{
	Account::debit(monthlyFee);
}

void sict::ChequingAccount::display(std::ostream & out) const
{
	out << "Account type: Chequing" << std::endl;
	out.setf(std::ios::fixed);
	out.precision(2);
	out.width(7);
	out << "Balance: $";
	out << balance() << std::endl;
	out << "Per Transaction Fee: " << transFee << std::endl;
	out << "Monthly Fee: " << monthlyFee << std::endl;
	out.precision(6);
	out.unsetf(std::ios::fixed);

}
