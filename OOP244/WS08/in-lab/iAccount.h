/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef IACCOUNT_H__
#define IACCOUNT_H__

#include <iostream>

namespace sict {
	class iAccount {
	public:
		virtual bool credit(double amount) = 0;
		virtual bool debit(double amount) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& out) const = 0;
		virtual ~iAccount(){} // The VIRTUAL Destructor of the base class will make the derived classes able to call their own destructors individually.
		//if it doens't have the virtual destructor, the pointer created in Allocator.cpp won't work properly due to absence of it
	};
	iAccount* CreateAccount(const char* type, double balance);

}










#endif