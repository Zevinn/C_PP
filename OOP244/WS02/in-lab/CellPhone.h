// TODO: header safeguards
#ifndef CELLPHONE_H_
#define CELLPHONE_H_

// TODO: sict namespace
namespace sict {
	struct CellPhone {
		char m_model[33];
		double m_price;
	};
	
		void display(const CellPhone &cp);
	// TODO: define the structure CellPhone in the sict namespace

	// TODO: declare the function display(...),
	//         also in the sict namespace
}
#endif