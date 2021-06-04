#pragma once
// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.06
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Reservation.h"

namespace sdds {
    
    class Reservation;

    class ConfirmationSender {
        const Reservation** ResP;
		int thesize; // need a size to manage the array of pointers
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		~ConfirmationSender();
	
		ConfirmationSender& operator+=(const Reservation&);
		ConfirmationSender& operator-=(const Reservation&);
		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
    };



}