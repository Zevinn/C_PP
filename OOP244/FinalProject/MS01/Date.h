/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef DATE_H__
#define DATE_H__
#include <iostream>

namespace ama {
	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;
	
	class Date {
		int yr;
		int mth;
		int day;
		int errcode; // status of any error
		void status(int newStatus); //
		int mdays(int year, int month) const; //
		bool check(int); // check before using operator on the day value if safe
	public:
		Date(); //
		Date(int y, int m, int d); //
		int status(); //
		void clearError(); //
		bool isGood(); //
		Date& operator+=(int days);
		Date& operator++();
		Date operator++(int);
		Date operator+(int days);
		bool operator==(const Date& rhs);
		bool operator!=(const Date& rhs);
		bool operator<(const Date& rhs);
		bool operator>(const Date& rhs);
		bool operator<=(const Date& rhs);
		bool operator>=(const Date& rhs);
		std::istream& read(std::istream& is); //
		std::ostream& write(std::ostream& os) const; //
		
	};
	std::istream& operator>>(std::istream& is, Date& d);
	std::ostream& operator<<(std::ostream& os, const Date& d);
}

#endif
