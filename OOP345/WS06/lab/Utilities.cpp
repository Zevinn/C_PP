// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

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
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Vehicle.h"

using namespace std;
namespace sdds {
	Vehicle * createInstance(std::istream & in)
	{	
		
		Vehicle* p = nullptr;
		std::string temp;
		if (getline(in, temp, '\n')) {
			removeSpace(temp);
			std::stringstream ss(temp);
			if (temp[0] == 'c' || temp[0] == 'C') {
				p = new Car(ss); 
			}
		}
		return p;
	}
	void removeSpace(std::string &src)
	{
		// beginning
		while (src[0] == ' ') {
			src.erase(0, 1);
		}
		// end
		while (src[src.size() - 1] == ' ') {
			src.erase(src.size() - 1, 1);
		}
	}
}
