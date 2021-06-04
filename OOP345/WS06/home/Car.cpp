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
#include <iomanip>
#include <exception>
#include "Car.h"

namespace sdds {


sdds::Car::Car() : t_maker{""}, t_condition{""}, t_speed{0}
{
}

sdds::Car::Car(const Car &src)
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
}

sdds::Car::Car(std::istream &in) 
{
	std::string temp;
	
	//tag
	getline(in, temp, ','); // extracts one line
	
	//maker
	getline(in, temp, ',');
	t_maker = temp;
	removeSpace(t_maker);

	//condition
	getline(in, temp, ',');
	t_condition = temp;
	removeSpace(t_condition);
	if (t_condition == "" || t_condition.at(0) == 'n') t_condition = "new";
	else if (t_condition.at(0) == 'b') t_condition += "roken";
	else if (t_condition.at(0) == 'u') t_condition += "sed";
	else throw std::invalid_argument("Invalid record!");

	//top speed
	getline(in, temp, ',');
	removeSpace(temp);
	if(temp.find_first_not_of("1234567890") == std::string::npos) t_speed = stod(temp);
	// above is to check whether it holds numbers only or not. 
	//Looking for any chars by the method find_first_not_of("1234567890"), if it returns -1, which is npos, it does hold alphabetical characters
	else throw std::invalid_argument("Invalid record!"); // assigning type of exception within 'throw' is important
	

	
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
	out << "| " << std::setw(10) << std::right << t_maker << " | " << std::setw(6) << std::left << condition()
		<< " | " << std::fixed << std::setw(6) << std::setprecision(2) << topSpeed() << " |";
}

void sdds::Car::removeSpace(std::string &src)
{
	if (!src.empty()) {

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
}
