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
#include <iomanip>
#include "Car.h"

namespace sdds {


sdds::Car::Car() : t_maker{""}, t_condition{""}, t_speed{0}
{
}

/*sdds::Car::Car(const Car &src)
{
	*this = src;
}

sdds::Car::Car(Car &&src)
{
	*this = std::move(src);
}

Car & sdds::Car::operator=(const Car &src)
{
	if (this != &src) {
		t_maker = src.t_maker;
		t_condition = src.t_condition;
		t_speed = src.t_speed;
	}
	return *this;
}

Car & sdds::Car::operator=(Car &&src)
{
	if (this != &src) {
		t_maker = src.t_maker;
		t_condition = src.t_condition;
		t_speed = src.t_speed;
		
		src.t_maker = "";
		src.t_condition = "";
		src.t_speed = 0;
	}
	return *this;
}*/

sdds::Car::Car(std::istream &in) // in-lab part, invalid situation is not considered
{
	std::string temp;
	int index;
	getline(in, temp, '\n'); // extracts one line
	
	if (temp[0] == 'c' || temp[0] == 'C') {
		//tag
		index = temp.find(',');
		temp.erase(0, index + 1);

		//maker
		index = temp.find(',');
		t_maker = temp.substr(0, index);
		removeSpace(t_maker);
		temp.erase(0, index + 1);

		//condition
		index = temp.find(',');
		t_condition = temp.substr(0, index);
		removeSpace(t_condition);
		if (t_condition.at(0) == 'n') t_condition += "ew";
		else if (t_condition.at(0) == 'b') t_condition += "roken";
		else if (t_condition.at(0) == 'u') t_condition += "sed";
		temp.erase(0, index + 1);

		//top speed
		t_speed = stod(temp);

	}
	
}

std::string sdds::Car::condition() const
{
	return t_condition;
}

double sdds::Car::topSpeed() const
{
	return t_speed;
}

void sdds::Car::display(std::ostream & out) const
{
	out << "| " << std::setw(10) << std::right << t_maker << " | " << std::setw(6) << std::left << t_condition
		<< " | " << std::fixed << std::setw(6) << std::setprecision(2) << t_speed << " |" << std::endl;
}

void sdds::Car::removeSpace(std::string &src)
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
