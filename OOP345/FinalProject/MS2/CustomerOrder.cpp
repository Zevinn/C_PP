// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() : m_name{""}, m_product{""}, m_cntItem{0}, m_lstItem{nullptr} {}

CustomerOrder::CustomerOrder(string& src)
{
	Utilities u;
	bool more = false;
	string temp;
	size_t next_pos = src.find(u.getDelimiter());
	m_name = src.substr(0, next_pos);
	m_product = u.extractToken(src, next_pos, more);
	size_t savingIndex = next_pos; // To save the position where the item list starts in the file.
	// will read the file to see how many items I need to store first, then create the number of spaces in m_lstItem.
	while (more) { // count the number of items
		string temp;
		temp = u.extractToken(src, next_pos, more);
		m_cntItem++;
	}
	next_pos = savingIndex; // call the position 
	more = true; // to re-read the file
	m_lstItem = new ItemInfo*[m_cntItem];
	size_t index = 0;
	while (more && index < m_cntItem) { // store the items in the list 
		m_lstItem[index] = new ItemInfo(u.extractToken(src, next_pos, more));
		index++;
	}
	if (CustomerOrder::m_widthField < u.getFieldWidth()) m_widthField = u.getFieldWidth();
}

CustomerOrder::CustomerOrder(const CustomerOrder & src)
{
	throw std::invalid_argument("");
}

CustomerOrder::CustomerOrder(CustomerOrder && src) noexcept
{
	*this = std::move(src);
}

CustomerOrder & CustomerOrder::operator=(CustomerOrder && src)
{
	if (this != &src) {
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;
		// src.m_widthField = m_widthField;

		src.m_name = "";
		src.m_product = "";
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder()
{
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string src) const
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == src) return m_lstItem[i]->m_fillState;
	}
	return true; // if the item isn't existed
}

bool CustomerOrder::getOrderFillState() const
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_fillState) return false;
	}
	return true;
}

void CustomerOrder::fillItem(Item & item, std::ostream & out)
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item.getName()) { // if true, it found the item.
			if (item.getQuantity() > 0) {
				item.updateQuantity(); // Substract 1 from the inventory
				item.getSerialNumber(); // update Serial Number
				m_lstItem[i]->m_fillState = true; // update fillState to ture
				out << "Filled " + m_name + ", " + m_product + "[" << item.getName() << "]" << endl;
			}
			else { // if it's not availabe in the inventory
				out << "Unable to fill " + m_name + ", " + m_product + "[" << item.getName() << "]" << endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream & out) const
{
	out << m_name + " - " + m_product << endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		out << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << setfill(' ') << "] "
			<< setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_fillState) out << "FILLED";
		else out << "MISSING";
		out << endl;
	}
}
