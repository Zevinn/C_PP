/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"

// TODO: the sict namespace
using namespace std;
    // TODO: definition for display(...) 
namespace sict {
	void display(const CellPhone &cp) {
		cout << "Phone " << cp.m_model << " costs"
			<< " $" << cp.m_price << "!" << endl;
	}
	void display(const CellPhone *cp, int n) {
		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". Phone " << cp[i].m_model << " costs "
				<< "$" << cp[i].m_price << "!" << endl;
		}
		double cheapest = 100000;
		for (int i = 0; i < n; i++) {
			cheapest = cp[i].m_price < cheapest ? cp[i].m_price : cheapest;
		}
		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << cheapest << "." << endl;
		cout << "------------------------------" << endl;
	}
}