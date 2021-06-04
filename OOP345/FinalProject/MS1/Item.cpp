
// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"


size_t Item::m_widthField = 1;
	Item::Item(const string & src)
	{
		Utilities m_u;
		bool more = false;
		string temp;
		size_t next_pos = src.find(m_u.getDelimiter());
		m_name = src.substr(0, next_pos);
		m_serialNumber = stoul(m_u.extractToken(src, next_pos, more));
		//if(more)
		m_quantity = stoul(m_u.extractToken(src, next_pos, more)); // std::stoul > convert string to unsigned integer
		m_description = m_u.extractToken(src, next_pos, more);
		if (m_widthField < m_name.length()) {
			m_widthField = m_name.length();
			m_u.setFieldWidth(m_widthField);
		}
	}
	const std::string & Item::getName() const
	{
		return m_name;
	}
	const unsigned int Item::getSerialNumber()
	{
		return m_serialNumber++;
	}
	const unsigned int Item::getQuantity()
	{
		return m_quantity;
	}
	void Item::updateQuantity()
	{
		if (m_quantity != 0) m_quantity--;
	}
	void Item::display(ostream & os, bool full) const
	{
		os << setw(m_widthField) << left << m_name << right << " [" << setw(6);
		if (m_serialNumber < 100000)
			os << setfill('0') << m_serialNumber << setfill(' ') << "]";
		else
			os << m_serialNumber << "]";
		if (!full) {
			os << endl;
		}
		else {
			os << " Quantity: " << left << setw(m_widthField) << m_quantity << " Description: " + m_description << endl;
		}
	}
