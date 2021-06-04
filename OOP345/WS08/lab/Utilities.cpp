// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.13
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		
						
		unsigned sCode; // standard code
		// assume the desciption container has bigger size than price container,
		size_t x = 0;
		while (desc.size() > x) {
			sCode = desc[x].code;
			for (size_t i = 0; i < price.size(); i++) {
				if (sCode == price[i].code) {
					Product* p = new Product(desc[x].desc, price[i].price);
					p->validate();
					priceList += p;
					delete p;
				}
			}
			x++;
		}
		return priceList;
	}
}