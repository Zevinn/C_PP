
// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Movie.h"
#include "Collection.h"

using namespace std;

namespace sdds {
	Movie::Movie() : m_title{ "" }, m_year{ 0 }, m_desc{ "" }
	{
	}
	const std::string & Movie::title() const
	{
		return m_title;
	}
	void Movie::removeSpace(string &src)
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
	Movie::Movie(const std::string & strMovie)
	{
		std::string temp = strMovie;
		int index;
		if (temp[0] != '#') {
			index = temp.find(',');
			m_title = temp.substr(0, index);
			removeSpace(m_title);
			temp.erase(0, index + 1);

			index = temp.find(',');
			m_year = stoi(temp.substr(0, index));
			temp.erase(0, index + 1);

			//index = temp.find(',');
			//m_desc = temp.substr(0, index);
			m_desc = temp;
			removeSpace(m_desc);
		}
	}
	Movie::Movie(const Movie &src)
	{
		*this = src;
	}
	Movie::Movie(Movie &&src)
	{
		*this = std::move(src);
	}
	Movie & Movie::operator=(const Movie &src)
	{
		if (this != &src) {
			m_title = src.m_title;
			m_year = src.m_year;
			m_desc = src.m_desc;
		}
		return *this;
	}
	Movie & Movie::operator=(Movie && src)
	{
		if (this != &src) {
			m_title = src.m_title;
			m_year = src.m_year;
			m_desc = src.m_desc;

			src.m_title = "";
			src.m_year = 0;
			src.m_desc = "";
		}
		return *this;
	}
	std::ostream & operator<<(ostream &out, const Movie &src)
	{
		out << setw(40) << src.m_title << " | "
			<< setw(4) << src.m_year << " | "
			<< src.m_desc << std::endl;
		return out;
	}
}


