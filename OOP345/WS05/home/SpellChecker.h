// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>
using namespace std;
namespace sdds {

	class SpellChecker {
		string * m_badWords;
		string * m_goodWords;
		int m_size = 5;
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;

	};
}
#endif // !SPELLCHECKER_H__#pragma once
