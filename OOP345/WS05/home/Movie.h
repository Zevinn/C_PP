
// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>

using namespace std;

namespace sdds {

	class Movie {
		string m_title;
		size_t m_year;
		string m_desc;
		// m_ means Movie
	public:
		Movie();
		const std::string& title() const;
		void removeSpace(string&); // remove spaces in the constructor
		Movie(const std::string& strMovie);
		Movie(const Movie&);
		Movie(Movie&&);
		Movie& operator=(const Movie&);
		Movie& operator=(Movie&&);
		friend std::ostream& operator<<(ostream&, const Movie&);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}

	};

}

#endif
