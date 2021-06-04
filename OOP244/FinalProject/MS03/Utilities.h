/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef UTILITIES_H__
#define UTILITIES_H__
#include "Product.h"
namespace ama {

	double& operator+=(double& total_s, const Product& src);
	std::ostream& operator<<(std::ostream& out, const Product& src);
	std::istream& operator>>(std::istream& in, Product& src);
}








#endif
