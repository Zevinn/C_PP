// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.06
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define CRT_NO_SECURE_WARNINGS


#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {
	Restaurant::Restaurant() : reservs{nullptr}, count{0}
	{
	}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		if (cnt > 0 && *reservations != nullptr) {
			reservs = new Reservation[cnt];
			count = 0;
			for (size_t i = 0; i < cnt; i++) {
				if (reservations[i] != nullptr) {
					reservs[i] = *reservations[i];
					count++;
				}
			}
		}
	}
	Restaurant::Restaurant(const Restaurant &src)
	{
		reservs = nullptr;
		*this = src;
	}
	Restaurant::Restaurant(Restaurant &&src)
	{
		reservs = nullptr;
		*this = std::move(src);
	}
	Restaurant & Restaurant::operator=(const Restaurant &src)
	{
		if (this != &src) {
			if (reservs != nullptr) {
				delete [] reservs;
			}
			count = src.count;
			if (src.reservs != nullptr) {

				reservs = new Reservation[src.count]; // current instance pointer points the same object of what src pointer points
				for (size_t i = 0; i < src.count; i++) {
					reservs[i] = src.reservs[i];
				}
			}
		}
		return *this;
	}
	Restaurant & Restaurant::operator=(Restaurant &&src)
	{
		if (this != &src) {
			if (reservs != nullptr) {
				delete [] reservs;
			}
			count = src.count;
			reservs = src.reservs;

			src.count = 0;
			src.reservs = nullptr;
		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		if(reservs != nullptr){
			delete[] reservs;
			reservs = nullptr;
		}
	}

	size_t Restaurant::size() const { return count; }

	std::ostream & operator<<(std::ostream & out, const Restaurant & src)
	{
		out << "--------------------------" << std::endl;
		out << "Fancy Restaurant" << std::endl;
		out << "--------------------------" << std::endl;
		if (src.count == 0) {
			out << "The object is empty!" << std::endl;
			out << "--------------------------" << std::endl;
		}
		else {
			for (unsigned i = 0; i < src.count; i++) {
				out << src.reservs[i];
				
			}
			out << "--------------------------" << std::endl;
		}
		return out;
	}
}