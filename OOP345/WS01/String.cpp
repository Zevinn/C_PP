// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.09.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"


namespace sdds {
	unsigned g_maxSize = 3;
	unsigned String::count = 0;
	String::String(const char* s_str)
	{
		
		if (s_str == nullptr)
			str = nullptr;
		else {
			str = new char[g_maxSize];
			strncpy(str, s_str, g_maxSize);
			str[g_maxSize] = '\0';
		}
	}

	/*String::~String()
	{
		delete[] str;
		str = nullptr;
	}*/

	void String::display(std::ostream& out)
	{
		out << str;
	}
	std::ostream& operator<<(std::ostream& out, String& st) {
		++String::count;
		std::cout << String::count << ": ";
		st.display(out);
		return out;
	}
	
	
}