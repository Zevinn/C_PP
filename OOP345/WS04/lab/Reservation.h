#pragma once
// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.03
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
using namespace std;
namespace sdds {
	class Reservation {
		string Reserv_Id; // Reservation Id
		string Reserv_name; // Reservation Name
		string Reserv_email; // Reservation Email
		size_t partysize; // Numer of ppl in the party
		size_t day; // the day --- 1 < day > 31
		size_t time; // the hour --- 0 < time > 24
	public:
		Reservation();
		Reservation(const std::string&);
		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}

