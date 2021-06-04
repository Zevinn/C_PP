// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#pragma once
#include <iostream>



	class Utilities {
		size_t m_widthField = 0;
		static char m_delimiter; // static variable?, ALL OBJECTS of this share the same delimiter
	public:
		Utilities();
		void setFieldWidth(size_t);
		size_t getFieldWidth() const;
		const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(const char);
		const char getDelimiter() const;
		void removeSpace(std::string &src); // extra custom function 
	};

