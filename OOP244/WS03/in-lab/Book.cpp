#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

namespace sict {
	void Book::set(char* gn_, char* fn_, char* title_, long long isbn) {
		bool valid = true;
		if (isbn <= 999999999999) {
			isbn = 1;
			valid = false;
		}
		else {
			strncpy(gn, gn_, max_name_size);
			strncpy(fn, fn_, max_name_size);
			strncpy(title, title_, max_title_size);
		}
	}
	bool Book::isEmpty() const {
		if (isbn == 1)
			return false;
		else
			return true;
	}
	void Book::display() const {
		if (isbn != 1) {
			cout << "Author: " << fn << ", " << gn << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << isbn << endl;
		}
		else
			cout << "The book object is empty!" << endl;
	}
}