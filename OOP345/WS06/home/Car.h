// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		std::string t_maker;
		std::string t_condition;
		double t_speed;
	public:
		Car();
		Car(const Car&);
		Car(Car&&);
		Car& operator=(const Car&);
		Car& operator=(Car&&);
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void removeSpace(std::string &); // to eliminate spaces in a string
		// add other required functions
	};


}
