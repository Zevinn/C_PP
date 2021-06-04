/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef CONTACT_H__
#define CONTACT_H__


namespace sict {
	const int max_name_size = 16;
	class Contact {
		char names[max_name_size];
		long long *phnum; // phone number
		int num; // number of phone number
	public:
		Contact();
		Contact(const char*, long long*, int);
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+=(const long long);
		~Contact();
		void copy(const Contact&);
		bool isEmpty() const;
		void display() const;
	};
}
#endif