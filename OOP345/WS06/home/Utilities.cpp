// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "Utilities.h"
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	Vehicle * createInstance(std::istream & in)
	{	
		
		Vehicle* p = nullptr;
		std::string temp;
		std::string tag;
		if (getline(in, temp, '\n')) {
			removeSpace(temp);
			tag = temp[0];
			std::stringstream ss(temp);
			if(tag == "c" || tag == "C") {
				p = new Car(ss); 
			}
			else if (tag == "r" || tag == "R") {
				p = new Racecar(ss);
			}
			else throw std::invalid_argument("Unrecognized record type: [" + tag + "]");
		}
		return p;
	}
	void removeSpace(std::string &src)
	{
		
		// beginning
		while (!src.empty() && src[0] == ' ') {
			src.erase(0, 1);
		}
		// end
		while (!src.empty() && src[src.size() - 1] == ' ') {
			src.erase(src.size() - 1, 1);
		}
	}
}
