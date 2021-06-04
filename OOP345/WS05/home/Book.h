// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
namespace sdds {
	template<typename T>
	class Collection;

	class Book {
	
		std::string t_author;
		std::string t_title;
		std::string t_country; //country of publication
		size_t t_year; // year of publication
		double t_price;
		string t_desc;
		// t_ : this
	public:
		Book();
		Book(const Book&);
		Book(Book&&);
		Book& operator=(const Book&);
		Book& operator=(Book&&);
		void removeSpace(string&); // to remove spaces in the beginning and end of any token
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const string& strBook);
		// add other functions

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(t_desc);
		}

		friend ostream& operator<<(ostream&, const Book&);

	};


}


#endif // !BOOK_H__

