/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/

// TODO: header safeguards
#ifndef CELLPHONE_H_
#define CELLPHONE_H_

// TODO: sict namespace
namespace sict {
	// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone {
		char m_model[33];
		double m_price;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
		void display(const CellPhone &cp);
		void display(const CellPhone *cp, int n);

}
#endif