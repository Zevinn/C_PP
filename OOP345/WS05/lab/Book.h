// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef BOOK_H__
#define BOOK_H__

using namespace std;
namespace sdds {

	class Book {
		string t_author;
		string t_title;
		string t_country; //country of publication
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
		friend ostream& operator<<(ostream&, const Book&);
	};


}


#endif // !BOOK_H__

