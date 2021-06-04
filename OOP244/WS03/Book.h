/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/

#ifndef SICT_BOOK_H_
#define SICT_BOOK_H_
namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999; // ISBN number has to be 13 digits

	class Book {
		char fn[max_name_size + 1];//family name
		char gn[max_name_size + 1];//given name
		char title[max_title_size + 1];
		long long isbn = 0;
	public:
		void set(const char*, const char*, const char*, long long);
		bool isEmpty() const;
		void display() const;

	};
}
#endif
