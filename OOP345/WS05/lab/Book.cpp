// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {

	Book::Book() : t_author{ "" }, t_title{ "" }, t_country{ "" }, t_year{0}, t_price{ 0 }, t_desc{ "" }
	{
	}

	Book::Book(const Book &src)
	{
		*this = src;
	}

	Book::Book(Book &&src)
	{
		*this = std::move(src);
	}

	Book & Book::operator=(const Book &src)
	{
		if (this != &src) {
			t_author = src.t_author;
			t_title = src.t_title;
			t_country = src.t_country;
			t_year = src.t_year;
			t_price = src.t_price;
			t_desc = src.t_desc;
		}
		return *this;
	}

	Book & Book::operator=(Book &&src)
	{
		if (this != &src) {
			t_author = src.t_author;
			t_title = src.t_title;
			t_country = src.t_country;
			t_year = src.t_year;
			t_price = src.t_price;
			t_desc = src.t_desc;

			src.t_author = "";
			src.t_title = "";
			src.t_country = "";
			src.t_year = 0;
			src.t_price = 0;
			src.t_desc = "";
		}
		return *this;
	}

	void Book::removeSpace(string &src)
	{
		// beginning
		while (src[0] == ' ') {
			src.erase(0, 1);
		}
		// end
		while (src[src.size()-1] == ' ') {
			src.erase(src.size() - 1, 1);
		}
	}

	const string & Book::title() const
	{
		return t_title;
	}

	const string & Book::country() const
	{
		return t_country;
	}

	const size_t & Book::year() const
	{
		return t_year;
	}

	double & Book::price()
	{
		return t_price;
	}

	Book::Book(const string & strBook)
	{
		std::string temp = strBook;
		int index;
		
		if (temp[0] != '#') {
			//author
			index = temp.find(',');
			t_author = temp.substr(0, index);
			removeSpace(t_author);
			temp.erase(0, index + 1);
			
			//title
			index = temp.find(',');
			t_title = temp.substr(0, index);
			removeSpace(t_title);
			temp.erase(0, index + 1);
			
			//country of publication
			index = temp.find(',');
			t_country = temp.substr(0, index);
			removeSpace(t_country);
			temp.erase(0, index + 1);
			
			//price
			index = temp.find(',');
			string temp2 = temp.substr(0, index);
			t_price = stod(temp2);
			temp.erase(0, index + 1);
			
			//year of publication
			index = temp.find(',');
			temp2 = temp.substr(0, index);
			t_year = stoi(temp2);
			temp.erase(0, index + 1);
			
			//description
			removeSpace(temp);
			t_desc = temp;
		}


	}

	ostream & operator<<(ostream &out, const Book &src)
	{
		out << setw(20)<<right << src.t_author << " | " 
			<< setw(22) << right << src.t_title << " | "
			<< setw(5) << right << src.t_country << " | "
			<< setw(4) << src.t_year << " | " 
			<< setw(6) << right << fixed << setprecision(2) <<src.t_price << " | "
			<< src.t_desc << endl;
		return out;
	}

}