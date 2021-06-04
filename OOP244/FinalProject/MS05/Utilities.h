/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef UTILITIES_H__
#define UTILITIES_H__
#include "iProduct.h"
#include "Product.h"
#include "Perishable.h"
namespace ama {

	double& operator+=(double& total_s, const iProduct& src);
	std::ostream& operator<<(std::ostream& out, const iProduct& src);
	std::istream& operator>>(std::istream& in, iProduct& src);
	iProduct* createInstance(char tag);
}








#endif
