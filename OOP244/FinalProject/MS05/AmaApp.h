/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef AMAAPP_H__
#define AMAAPP_H__
#include "iProduct.h"
#include "Utilities.h"
namespace ama {
	class AmaApp {
		char m_filename[256];
		iProduct* m_products[100];
		int m_noOfProducts;
		AmaApp(const AmaApp& src) = delete; // copy constructor prohibited
		AmaApp& operator=(const AmaApp& src) = delete; // copy assignment prohibited
		void pause() const;
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const;
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);
	public:
		AmaApp(const char* filename_s);
		~AmaApp();
		int run();
	};
}



#endif // !AMAAPP_H__

