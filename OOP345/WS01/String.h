// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.09.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef STRING_H__
#define STRING_H__


namespace sdds {
	extern unsigned int g_maxSize; // because at other module, this is used and 'extern' allows them to initialize it multiple times
	class String
	{
	private:
		char *str;
	public:
		static unsigned int count;
		String(const char*);
		//~String();
		void display(std::ostream&);
	};
	std::ostream& operator<<(std::ostream&, String&);
}
#endif