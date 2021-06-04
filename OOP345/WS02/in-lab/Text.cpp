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
#include <fstream>
#include "Text.h"


namespace sdds {
	
	int Text::counter = 0;
	
	
Text::Text() : text{nullptr}
{
}

Text::Text(const char * file)
{
	ifstream f;
	string temp;
	f.open(file);
	if (f.is_open())
	{
		while (!f.eof()) {
			
			if (f.get() == ' ') {
				
				counter++;
			}
		}
		
	}
	text = new string[counter];
	
	int i = 0;
	std::getline(f, text[i]);
	/*while (!f.eof()) {
		for (int i = 0; i < counter; i++) {
			if (getline(f, temp, ' '))
				text[i] = temp;
		}
	}*/
	
}

Text::Text(const Text & src)
{
	*this = src;
}

Text & Text::operator=(const Text & src)
{
	if (this != &src) {
		counter = src.counter;

		
			text = new string[counter];
			for (int i = 0; i < counter; i++) {
				text[i] = src.text[i];
			}
		
	}
	return *this;
}

Text::~Text()
{
	delete[] text;
	text = nullptr;
}

size_t Text::size() const
{
	return counter;
}

} //
