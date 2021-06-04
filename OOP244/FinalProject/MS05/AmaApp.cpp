/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "AmaApp.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
namespace ama {

	void clearKeyboard() { // for pause function
		while (getchar() != '\n');
	}
	void AmaApp::pause() const
	{
		
		cout << "Press Enter to continue...";
		clearKeyboard();
		cout << endl;
		//system("pause");
	}

	int AmaApp::menu() const
	{
		int a; // answer from an user
		
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> a;
		cin.clear(); // Clear the input buffer before exiting
		cin.ignore(1000, '\n');
		if (a < 0 || a > 7) return -1;
		else return a;
	}

	void AmaApp::loadProductRecords()
	{
		for (int i = 0; i < 100; i++) { // Delete all products from the array(if any)
			if (m_products[i] != nullptr) {
				delete[] m_products[i];
				m_products[i] = nullptr;
			}
		}
		int r = 0; //set reading index to zero
		char c;
		iProduct* p;
		ifstream fin(m_filename, ios::in); // open the file for reading
		if (!fin.is_open()) { // if file doesn't exist, close the file and exit
			fin.close();
		}
		else { // if scceed to open,
			while (!fin.eof()) { // until reading fails loop
				fin.get(c);
				p = createInstance(c);
				if (p != nullptr) { // call the createInstance Func and if not null,
					m_products[r] = p;// store the product in the array at the read index
					fin.ignore(); // ignore the comma from the file
					p->read(fin, false); // read the product within non-interactive mode
					r++; // increment the read index
				}
			}
			m_noOfProducts = r; // set number of products to readIndex
			fin.close(); // close the datafile;
			fin.ignore();
		}
	}

	void AmaApp::saveProductRecords() const
	{
		fstream fout(m_filename, ios::out);
		if (fout.is_open()) {
			for (int i = 0; i < m_noOfProducts; i++) {
				m_products[i]->write(fout, write_condensed);
				fout << endl;
			}
		}
		fout.close();
		cout << endl;
	}

	void AmaApp::listProducts() const
	{
		double total = 0;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;
		for (int i = 0; i < m_noOfProducts; i++) {
			cout << "|";
			cout.width(4);
			cout.setf(ios::right);
			cout << i + 1 << " |";
			m_products[i]->write(std::cout, write_table);
			cout << endl;
			total += m_products[i]->total_cost();
		}
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                      Total cost of support ($): | ";
		cout.width(10);
		cout.setf(ios::right);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << total;
		cout << " |" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl << endl;

		pause();
	}

	iProduct* AmaApp::find(const char * sku_s) const
	{
		iProduct* p = nullptr;
		
		for (int i = 0; i < m_noOfProducts; i++) {
			p = m_products[i];
			if (*p == sku_s) return p;
		}
		return nullptr;
	}

	void AmaApp::addQty(iProduct * product)
	{
		int i = 0;
		int needed = product->qtyNeeded();
		int avail = product->qtyAvailable();
		int Aneeded = needed - avail; // actual needed quantity
		product->write(cout, write_human);
		cout << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> i;
		
		if (cin.fail()) { // does it fail because of type difference ? 
			cout << "Invalid quantity value!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			if (i <= Aneeded) {
				*product += i;
			}
			else {
				int extra = i + avail - needed;
				cout << "Too many items; only " << Aneeded << " is needed. Please return the extra " << extra << " items." << endl;
				*product += Aneeded;
				
			}
			saveProductRecords();
			cout << "Updated!" << endl; // make sure to flush the keyboard ... ?
		}
	}

	void AmaApp::addProduct(char tag)
	{
		iProduct* p = nullptr;
		
		p = createInstance(tag);
		if (p != nullptr) {
			p->read(cin, 1);
			if (cin.fail()) {
				cout << endl;
				p->write(cout, write_human);
				cout << endl << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else { 
				m_products[m_noOfProducts] = p;
				m_noOfProducts++;
				saveProductRecords();
				
				cout << "Success!" << endl << endl;

			}
		}
	}



	AmaApp::AmaApp(const char* filename_s)
	{
		if (filename_s != nullptr || filename_s[0] != '\0') {
			strcpy(m_filename, filename_s);
		}
		for (int i = 0; i < 100; i++) {
			m_products[i] = nullptr;
		}
		m_noOfProducts = 0;
		loadProductRecords();
	}

	AmaApp::~AmaApp() {
		for (int i = 0; i < 100; i++) {
			if (m_products[i] != nullptr) {
				delete[] m_products[i];
				m_products[i] = nullptr;
			}
		}
	}

	int AmaApp::run()
	{
		int input = 1;
		while (input != 0) {
			input = menu();
			
			if (input == -1){
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
			}
			else if (input == 1) {
				listProducts();
				
			}
			else if (input == 2) {
				char sku_s[max_length_sku];
				cout << "Please enter the product SKU: ";
				cin >> sku_s;
				cout << endl; // might be wrong place?
				iProduct* p = find(sku_s);
				if (p != nullptr) { 
					p->write(cout, write_human); 
					cout << endl;
					cin.ignore(1000, '\n');
				}
				else {
					cin.ignore(1000, '\n');
					
					cout << "No such product!" << endl;
				}
				pause();
				
			}
			else if (input == 3) {
				addProduct('n');
				
			}
			else if (input == 4) {
				addProduct('p');
				
			}
			else if (input == 5) {
				char sku_s[max_length_sku];
				cout << "Please enter the product SKU: ";
				cin >> sku_s;
				cout << endl;
				iProduct* p = find(sku_s);
				if (p != nullptr) {
					addQty(p);
					
				}
				else cout << "No such product!" << endl;
				
				cout << endl;
			}
			else if (input == 6) {} // none
			else if (input == 7) {} // none
			else if (input == 0) {
				
				cout << "Goodbye!";
				cout.clear();
				cout << endl;
			}
		}
			return 0;
	}
}


