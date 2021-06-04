// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include "Utilities.h"
using namespace std;


	class Item {
		string m_name;
		string m_description;
		size_t m_serialNumber;
		size_t m_quantity;
		static size_t m_widthField;
		
	public:
		Item();
		Item(const string&);
		const std::string& getName() const;
		const unsigned int getSerialNumber();
		const unsigned int getQuantity();
		void updateQuantity();
		void display(ostream& os, bool full) const;
	};

