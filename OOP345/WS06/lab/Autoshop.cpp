// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.02
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include "Autoshop.h"

namespace sdds {
	Autoshop & Autoshop::operator+=(Vehicle * theVehicle)
	{
		this->m_vehicles.push_back(theVehicle);
		
		return *this;
	}
	void Autoshop::display(std::ostream & out) const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		
		for (auto i = (m_vehicles).begin(); i != m_vehicles.end(); i++) {
			(*i)->display(out);
		}
		out << "--------------------------------" << std::endl;
	}
}