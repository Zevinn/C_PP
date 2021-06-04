/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef AMA_PERISHABLE_H__
#define AMA_PESISHABLE_H__
#include "Date.h"
#include "Product.h"

namespace ama {
	class Perishable : public Product 
	{
		Date ExpiryDate;
	public:
		Perishable();
		std::ostream& write(std::ostream& out, int writeMode) const;
		std::istream& read(std::istream& in, bool interractive);
	};
}





#endif // !PERISHABLE_H__
