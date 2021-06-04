#pragma once
// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.06
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>

namespace sdds {
    
    class Reservation;
    
    // composition
    class Restaurant {
        Reservation* reservs; // Reservation pointers
        public: 
        Restaurant(Reservation*, size_t);
        // other member functions to be added here

        friend std::ostream& operator<<(std::ostream&, Restaurant&);
    
    
    
    };
}