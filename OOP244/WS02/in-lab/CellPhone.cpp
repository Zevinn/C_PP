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
}