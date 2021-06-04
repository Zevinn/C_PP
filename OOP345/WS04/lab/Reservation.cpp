// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.03
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define CRT_NO_SECURE_WARNINGS


#include <iostream>
#include <string>
#include <iomanip>
//#include <algorithm>
#include "Reservation.h"

namespace sdds {


Reservation::Reservation() 
	: Reserv_Id{nullptr}, Reserv_name{nullptr}, Reserv_email{nullptr}, partysize{0}, day{0}, time{0}
{
}

Reservation::Reservation(const std::string & m_res)
{
	/* In algorithm library, a function that checks if it incudes any space to remove. 
	std::remove_if(temp.begin(), temp.end(), isspace); 
	 begin() and end() are iterator, and this function means it puts the values between begin() and end() to check if there's a space. if there is, isspace would return true, remove_if function would remove it if ture.
	***** Linux doesn't accept this function :( ***** */
	std::string temp = m_res;
	int leng = m_res.length();
	int i = 0;
	int index;

	while (leng > i) {
		index = temp.find(' '); // if find() can't find space, it will return std::string::npos, which is -1
		if (index != -1) temp.erase(index, 1);
		i++;
	}


	

	/*
	1) find() to look for the delimeter (: or ,)
	2) copy the part up to right before the index of ',' by substr()
	3) erase the copied part and the delimeter by erase() and loop.
	4) if it's a turn to take num, stoi(), which is from 4th */
	
	index = temp.find(':'); // 7 index = 7
	Reserv_Id = temp.substr(0, index); // need to copy for the numbers of return of the index, cause substr(starting index, how many letters to copy)
	temp.erase(0, index + 1); // 8


	index = temp.find(',');
	Reserv_name = temp.substr(0, index);
	temp.erase(0, index + 1);
	
	index = temp.find(',');
	
	Reserv_email = "<" + temp.substr(0, index) + ">";
	temp.erase(0, index + 1);

	index = temp.find(',');
	string temp2 = temp.substr(0, index);
	partysize = std::stoi(temp2);
	temp.erase(0, index + 1);
	
	index = temp.find(',');
	temp2 = temp.substr(0, index);
	day = std::stoi(temp2);
	temp.erase(0, index + 1);

	time = std::stoi(temp);
}

std::ostream & operator<<(std::ostream& out, const Reservation& src)
{
	if (src.time >= 6 && src.time <= 9) {
		out << "Reservation " << src.Reserv_Id << ": " << setw(10) << right << src.Reserv_name << "  " << left << setw(20) << src.Reserv_email // + overloaded operator for strings
			<< "    Breakfast on day " << src.day << " @ " << src.time << ":00 " << "for " << src.partysize << " people.";
	}
	else if (src.time >= 11 && src.time <= 15) {
		out << "Reservation " << src.Reserv_Id << ": " << setw(10) << right << src.Reserv_name << "  " << left << setw(20) << src.Reserv_email
			<< "    Lunch on day " << src.day << " @ " << src.time << ":00 " << "for " << src.partysize << " people.";
	}
	else if (src.time >= 17 && src.time <= 21) {
		out << "Reservation " << src.Reserv_Id << ": " << setw(10) << right << src.Reserv_name << "  " << left << setw(20) << src.Reserv_email
			<< "    Dinner on day " << src.day << " @ " << src.time << ":00 " << "for " << src.partysize << " people.";
	}
	else {
		out << "Reservation " << src.Reserv_Id << ": " << setw(10) << right << src.Reserv_name << "  " << left << setw(20) << src.Reserv_email
			<< "    Drinks on day " << src.day << " @ " << src.time << ":00 " << "for " << src.partysize << " people.";
	}
	out << endl;
	return out;
}
} // end of the scope 'sdds'
