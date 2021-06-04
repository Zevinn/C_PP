// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;

	//size_t Utilities::m_widthField = 1;
	char Utilities::m_delimiter = '\0';

	Utilities::Utilities(){}

	void Utilities::setFieldWidth(size_t w)
	{
		m_widthField = w;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more)
	{
		string temp;
		size_t leng;
		auto index = str.find(m_delimiter, next_pos + 1); //find next index of the delimiter
		
		// more delimiter?
		if (index != std::string::npos) more = true; // if succeed to extract, set more to true, when do I want to set 'more' to true when I succeed the extraction? or when I find next delimiter to keep extracting ?
		else more = false;
		
		// define length
		if (!more) leng = str.length() - next_pos;
		else leng = (index - next_pos) - 1; // the length of the token to extract this time.
		
		// extract the token
		temp = str.substr(next_pos + 1, leng);
		
		// the next position of the delimiter.
		if(more) next_pos = index; 
		removeSpace(temp);
		
		if (temp == "") // if there's no token between the 2 delimters, which means it's an empty string,
				throw std::invalid_argument("no token between 2 delimiters"); // then throw an exception
		

		if (Utilities::m_widthField < temp.length()) setFieldWidth(temp.length()); // set the width to proper width

		return temp;
	}
	void Utilities::setDelimiter(const char d)
	{
		m_delimiter = d;
	}
	const char Utilities::getDelimiter() const
	{
		return m_delimiter;
	}
	void Utilities::removeSpace(std::string & src)
	{
		if (!src.empty()) {

			// beginning
			while (!src.empty() && src[0] == ' ') {
				src.erase(0, 1);
			}
			// end
			while (!src.empty() && src[src.size() - 1] == ' ') {
				src.erase(src.size() - 1, 1);
			}
		}
	}
