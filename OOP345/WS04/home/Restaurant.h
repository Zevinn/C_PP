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
    
    // composition
    class Restaurant {
        Reservation* reservs; // Reservation pointers
		size_t count;
	public:
		Restaurant();
        Restaurant(Reservation* r[], size_t cnt);
		Restaurant(const Restaurant&);
		Restaurant(Restaurant&&);
		Restaurant& operator=(const Restaurant&);
		Restaurant& operator=(Restaurant&&);
		~Restaurant();
		size_t size() const;


        friend std::ostream& operator<<(std::ostream&, const Restaurant&);
    
    
    
    };
}