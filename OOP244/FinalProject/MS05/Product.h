/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef PRODUCT_H__
#define PRODUCT_H__
#include "iProduct.h"
#include "ErrorState.h"

namespace ama {
	class Product : public iProduct {
		const char type;
		char sku[max_length_sku + 1]; // stock keeping unit
		char unit[max_length_unit + 1];
		char *np; // name pointer
		int amount; // available quantity of the product;
		int neededA; // needed amount;
		double price; // price of a unit before tax;
		bool taxable;
		ErrorState error;
	protected:
		void message(const char* pText);
		bool isClear() const;
	public:
		Product(char t = 'N');
		Product(const char* sku_src, const char* name_src, const char* unit_src, double price_src = 0.00, int neededA_src = 0, int amount_src = 0, bool taxable_src = true);
		Product(const Product& src); // copy constructor 
		~Product();
		Product& operator=(const Product& src); // copy assignment
		void copy(const Product& src); // my own function for copying
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const iProduct& src) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		const char* name() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;

	};



} // end of namespace scope;
















#endif
