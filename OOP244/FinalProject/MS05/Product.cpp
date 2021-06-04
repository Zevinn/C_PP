/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"
#include <sstream>
#include <string>
#include <string.h>


using namespace std;
namespace ama {
	void Product::message(const char * pText)
	{
		this->error.copy(pText);
	}
	bool Product::isClear() const
	{
		bool isit = error.operator bool();
		if (isit) return false;
		else return true;
	}

	Product::Product(char t) : type(t) { 
		sku[0] = 0;
		unit[0] = 0;
		np = nullptr;
		amount = 0;
		neededA = 0;
		price = 0;
	}
	Product::Product(const char* sku_src, const char* name_src, const char* unit_src, double price_src, int neededA_src, int amount_src, bool taxable_src) : Product()
	{
		if (name_src[0] == '\0' || name_src == nullptr) { *this = Product(); }
		else {
			
			strcpy(sku, sku_src);
			np = new char[strlen(name_src) + 1];
			strcpy(np, name_src);
			np[strlen(name_src)] = '\0';
			strcpy(unit, unit_src);
			price = price_src;
			neededA = neededA_src;
			amount = amount_src;
			taxable = taxable_src;
		}
	}
	Product::Product(const Product& src) : Product()
	{
		copy(src);
	}
	Product::~Product()
	{
		delete[] np; np = nullptr;
	}
	Product & Product::operator=(const Product & src)
	{
		if (this != &src && src.np != nullptr && src.np[0] != '\0') {
			delete[] np;
			copy(src);
		}
		else np = nullptr;
		return *this;
	}
	void Product::copy(const Product & src) // to reduce duplication
	{
		price = src.price;
		neededA = src.neededA;
		amount = src.amount;
		taxable = src.taxable;
		
		strcpy(sku, src.sku);
		np = new char[strlen(src.np) + 1];
		strcpy(np, src.np);
		np[strlen(src.np)] = '\0';
		strcpy(unit, src.unit);
	}
	int Product::operator+=(int cnt)
	{
		if (cnt > 0) {
			amount += cnt;
		}
		return amount;
	}
	bool Product::operator==(const char * sku_s) const
	{
		bool same;
		int leng = strlen(sku_s);
		for (int i = 0; i < leng; i++) {
			same = (sku[i] == sku_s[i]);
			if (same == false) break;
		}
		return same;
	}
	bool Product::operator>(const char * sku_s) const 
	{
		if (strcmp(sku, sku_s) > 0) return true;
		else return false;
	}
	bool Product::operator>(const iProduct & src) const
	{
		if (strcmp(np, src.name()) > 0) return true;
		else return false;

	}
	int Product::qtyAvailable() const
	{
		return amount;
	}
	int Product::qtyNeeded() const
	{
		return neededA;
	}
	const char * Product::name() const
	{
		return np;
	}
	double Product::total_cost() const
	{
		if (taxable) {
			double total = 0;
			total = price + (price * tax_rate);
			total = total * amount;
			return total;
		}
		else return amount * price;
	}
	bool Product::isEmpty() const {
		if (np == nullptr) return true;
		else return false;
	}
	std::istream& Product::read(std::istream & in, bool interactive)
	{
		stringstream ss;
		string temp;
		if (interactive == false) {
			
			getline(in, temp, ',');
			stringstream(temp) >> sku;
			getline(in, temp, ',');
			np = new char[max_length_name];
			stringstream(temp).get(np, max_length_name); // get the string into 'name' up to length of 'max_length_name'

			getline(in, temp, ',');
			stringstream(temp) >> unit;
			getline(in, temp, ',');
			stringstream(temp) >> price;
			getline(in, temp, ',');
			stringstream(temp) >> taxable;
			getline(in, temp, ',');
			stringstream(temp) >> amount;
			in >> neededA;
			
			
		}
		else {
			char tmp[max_length_name];
			cout.width(max_length_label);
			cout.setf(ios::right);
			cout << "Sku: ";
			in >> sku;
			

			cout.width(max_length_label);
			cout << "Name (no spaces): ";
			in >> tmp;
			np = new char[max_length_name];
			strcpy(np, tmp);
			

			cout.width(max_length_label);
			cout << "Unit: ";
			in >> unit;
			

			char t;
			cout.width(max_length_label);
			cout << "Taxed? (y/n): ";
			in >> t;
			
			if (t == 'y' || t == 'Y' || t == 'n' || t == 'N') {
				{if (t == 'y' || t == 'Y') taxable = 1;
				else taxable = 0; }
				cout.width(max_length_label);
				cout << "Price: ";
				in >> price;
			
				
				if (!in.fail()) {   //cin.fail() detects whether the value entered fits the value defined in the variable
					cout.width(max_length_label);
					cout << "Quantity on hand: ";
					in >> amount;
				
					
					if(!in.fail()){
						cout.width(max_length_label);
						cout << "Quantity needed: ";
						in >> neededA;
						
				
							if (!in.fail()) {
								return in;
							}
							else {
								message("Invalid Quantity Needed Entry!");
								in.setstate(ios::failbit);
							}
					}
					else {
						message("Invalid Quantity Available Entry!");
						in.setstate(ios::failbit);
					}
				}
				else {
					message("Invalid Price Entry!");
					in.setstate(ios::failbit);
				}
			}
			else {
				message("Only (Y)es or (N)o are acceptable!");
				in.setstate(ios::failbit);
				//*this = Product();
			}
		}
		return in;
	}
	std::ostream & Product::write(std::ostream & out, int writeMode) const
	{
		if (error.message() != nullptr) {
			out << error.message(); 
			return out;
		}
		else if (np == nullptr) {
			// do nothing
			
		}
		else if (writeMode == write_condensed) {
			out << type << "," << sku << "," << np << "," << unit << ",";
			out.setf(ios::fixed);
			out.precision(2);
			out << price << "," << taxable << "," << amount << "," << neededA;
			
		}
		else if (writeMode == write_table) {
			out << " ";
			out.setf(ios::right);
			out.width(max_length_sku);
			out << sku << " | ";
			out.unsetf(ios::right);
			
			out.setf(ios::left);
			if (strlen(np) > 16) {
				for (int i = 0; i < 13; i++) {
				out << np[i];
				}
				out << "..." << " | ";
			}
			else {
			out.width(16);
			out << np << " | ";
			}
			out.setf(ios::left);
			out.width(10);
			out << unit << " | ";
			
			out.width(7);
			out.setf(ios::right);
			out.setf(ios::fixed);
			out.precision(2);
			out << price << " | ";
			//out.precision(6);

			out.width(3);
			if (taxable) out << "yes";
			else out << "no";
			out << " | ";

			out.width(6);
			out << amount << " | ";

			out.width(6);
			out << neededA << " |";

		}
		else if (writeMode == write_human) {
			out.setf(ios::right);
			out.width(max_length_label);
			out << "Sku: " << sku << endl;
			out.width(max_length_label);
			out << "Name: " << np << endl;
			out.width(max_length_label);
			out.setf(ios::fixed);
			out.precision(2);
			out << "Price: " << price << endl;
			out.width(max_length_label);
			if (this->taxable) {
			out << "Price after Tax: " << price + (price*tax_rate) << endl;
			}
			else out << "Price after Tax: " << price << endl;
			out.width(max_length_label);
			out << "Quantity Available: " << amount << " " << unit << endl;
			out.width(max_length_label);
			out << "Quantity Needed: " << neededA << " " << unit << endl;
			
		}
	return out;
	}
}