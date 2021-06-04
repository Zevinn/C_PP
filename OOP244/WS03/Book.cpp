/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/

#include "Book.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sict {
	void Book::set(const char* gn_, const char* fn_, const char* title_, long long isbn_) {
		bool valid = true;
		valid = isbn_ >= min_isbn_value && isbn_ <= max_isbn_value ? 1 : 0;
		if (valid==0)
			isbn_ = 0;
		else {
			strncpy_s(gn, gn_, max_name_size);
			strncpy_s(fn, fn_, max_name_size);
			strncpy_s(title, title_, max_title_size);
			isbn = isbn_;
		}
	}
	bool Book::isEmpty() const {
		
		if (isbn == 0)
			return 1;
		else return 0;
	}
	void Book::display() const {
		if (isbn > 0) {
			cout << "Author: " << fn << ", " << gn << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << isbn << endl;
		}
		else
			cout << "The book object is empty!" << endl;
	}
	
}