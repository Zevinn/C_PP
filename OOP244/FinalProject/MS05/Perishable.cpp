/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/

#include <iostream>
#include "Perishable.h"
using namespace std;

namespace ama{
Perishable::Perishable() : Product('P')
{
	ExpiryDate = Date();
}

std::ostream & Perishable::write(std::ostream & out, int writeMode) const
{
	Product::write(out, writeMode);
	
	if (!isClear() || isEmpty()){  // this = &Product object
		return out; // true from isClear() means no error
	}
	else if(writeMode == write_human){
		out.width(max_length_label);
		out.setf(ios::right);
		out << "Expiry Date: ";
		ExpiryDate.write(out);
		out << endl;
	}
	else if (writeMode == write_table) {
		out << " ";
		ExpiryDate.write(out);
		out << " |";
	}
	else if (writeMode == write_condensed) {
		out << ",";
		ExpiryDate.write(out);
	}
	return out;
}

std::istream & Perishable::read(std::istream & in, bool interactive)
{
	Product::read(in, interactive);
	if (interactive) {
		std::cout.setf(std::ios::right);
		std::cout.width(max_length_label); // -2 for the characters ":" & a space
		std::cout << "Expiry date (YYYY/MM/DD): ";
		ExpiryDate.read(in);
		if (ExpiryDate.status() != no_error) {
			in.setstate(ios::failbit);
			if (ExpiryDate.status() == error_year) {
				this->message("Invalid Year in Date Entry");
			}
			else if (ExpiryDate.status() == error_mon) {
				this->message("Invalid Month in Date Entry");
			}
			else if (ExpiryDate.status() == error_day) {
				this->message("Invalid Day in Date Entry");
			}
			else if (ExpiryDate.status() == error_input) {
				this->message("Invalid Date Entry");
			}
			*this = Perishable();
		}
	}
	else { // non-interactive mode
		in.ignore(); // for ','
		ExpiryDate.read(in);
		in.ignore(); // like how many skipping \n though?
	}
	return in;
}
}