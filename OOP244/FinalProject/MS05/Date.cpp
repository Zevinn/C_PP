/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;


namespace ama {
	
	void Date::status(int newStatus) {
		errcode = newStatus;
	}

	int Date::mdays(int year, int mon) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13; month--;
		return days[month] + int((month == 1)*((year % 4 == 0) &&
			(year % 100 != 0)) || (year % 400 == 0));
	}
	
	Date::Date() {
		yr = 0;
		mth = 0;
		day = 0;
		errcode = no_error;
	}

	Date::Date(int y, int m, int d) {
		if (y >= min_year && y <= max_year) {
			yr = y;
			if (m > 0 && m < 13) {
				mth = m;
				if (d > 0 && d <= mdays(y, m)) {
					day = d;
					errcode = no_error;
				}
				else {
					*this = Date();
					status(error_day);
				}
			}
			else {
				*this = Date();
				status(error_mon);
			}
		}
		else {
			*this = Date();
			status(error_year);
		}
	}

	int Date::status() {
		return errcode;
	}
	void Date::clearError() {
		errcode = no_error;
	}

	bool Date::isGood() {
		bool valid = (yr >= min_year && yr <= max_year && mth > 0 && mth < 13 && day > 0 && day <= (mdays(yr, mth)) && errcode == no_error);
		return valid;
	}

	bool Date::check(int v) { // if safe
		if (isGood()) {
			if (day + v > mdays(yr, mth) || day + v < 1) {
				return false;
			}
			else return true;
		}
		else return false;
	}

	Date& Date::operator+=(int days) {
		if (check(days)) {
			day += days;
			return *this;
		}
		else {
			errcode = error_invalid_operation;
			return *this;
		}
	}


	Date& Date::operator++() { // prefix
		if (check(1)) {
			day += 1;
			return *this;
		}
		else {
			errcode = error_invalid_operation;
			return *this;
		}
	}

	Date Date::operator++(int) { // postfix
			Date temp = *this;
			++(*this);
			return temp;
	}
	Date Date::operator+(int days) {
		Date temp = Date(yr, mth, day);
		if (check(days)) {
			temp.day += days;
			return temp;
		}
		else {
			temp.errcode = error_invalid_operation;
			return temp;
		}
	}
	bool Date::operator==(const Date& rhs) {
		if (yr == rhs.yr && mth == rhs.mth && day == rhs.day) {
			return true;
		}
		else return false;
	}
	bool Date::operator!=(const Date& rhs) {
		bool same = *this == rhs;
		if (same) return false;
		else return true;
	}

	bool Date::operator<(const Date& rhs) {
		bool isit = false;
		if (yr == rhs.yr && mth == rhs.mth && day < rhs.day) isit = true;
		else if (yr == rhs.yr && mth < rhs.mth) isit = true;
		else if (yr < rhs.yr) isit = true;
		
		return isit;
	}

	bool Date::operator>(const Date& rhs) {
		bool isit = false;
		if (yr == rhs.yr && mth == rhs.mth && day > rhs.day) isit = true;
		else if (yr == rhs.yr && mth > rhs.mth) isit = true;
		else if (yr < rhs.yr) isit = true;
		return isit;
	}

	bool Date::operator<=(const Date& rhs) {
		if (*this == rhs) return true;
		else if (*this < rhs) return true;
		else return false;
	}
	
	bool Date::operator>=(const Date& rhs) {
		if (*this == rhs) return true;
		else if (*this > rhs) return true;
		else return false;
	}


	std::istream& Date::read(istream& is) {
		char hold; // to hold a character in between the date values
		//is >> hold;
		is >> yr >> hold >> mth >> hold >> day;
		if (!is.fail()) {
			if (yr >= min_year && yr <= max_year) {
				status(no_error);
				if (mth >= 1 && mth <= 12) {
					status(no_error);
					if (day >= 1 && day <= mdays(yr, mth)) {
						status(no_error);
					}
					else {
						*this = Date();
						status(error_day);
					}
				}
				else {
					*this = Date();
					status(error_mon);
				}
			}
			else {
				*this = Date();
				status(error_year);
			}
		}
		else {
			*this = Date();
			status(error_input);
		}
		return is;
	}	
	
	std::ostream& Date::write(std::ostream& os) const {
		if (yr < 10) {
			os << "000";
		}
		os << yr << "/";
		if (mth < 10) {
			os << "0";
		}
		os << mth << "/";
		if (day < 10) {
			os << "0";
		}
		os << day;
		
		return os;
	} 




	std::istream& operator>>(std::istream& is, Date& d) {
		return d.read(is);
		
	}
	std::ostream& operator<<(std::ostream& is, const Date& d) {
		return d.write(is);
		
	}
} //end bracket 
