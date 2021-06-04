#pragma once
#ifndef BOOK_H_
#define BOOK_H_
namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;

	class Book {
		char fn[max_name_size + 1]; // family name
		char gn[max_name_size + 1]; // given name
		char title[max_title_size + 1];
		long long isbn;
	public:
		void set(char*, char*, char*, long long);
		bool isEmpty() const;
		void display() const;
	};
}

#endif