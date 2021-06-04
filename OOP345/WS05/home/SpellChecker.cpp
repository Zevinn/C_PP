// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds {
	
	SpellChecker::SpellChecker(const char * filename)
	{
		std::ifstream file(filename);
		try {
			if (file.is_open() == false) throw std::runtime_error("Bad file name!");
		
			else{
			std::string temp;
			int i = 0;
			m_badWords = new string[m_size];
			m_goodWords = new string[m_size];
			while (i < m_size) {
				std::getline(file, temp);

				while (temp[0] == ' ') temp.erase(0, 1);
				while (temp.size() - 1 == ' ')temp.erase(temp.size() - 1, 1);
				while (temp.find('\n') != string::npos) temp.erase(temp.find('\n'), 1);
				while (temp.find('\r') != string::npos) temp.erase(temp.find('\r'), 1); // matrix problem;


				int index = temp.find(' ');
				m_badWords[i] = temp.substr(0, index);
				temp.erase(0, index + 1);
				while (temp[0] == ' ') temp.erase(0, 1);
				m_goodWords[i] = temp;
				i++;
			}
		}
	file.close();
		}
		catch (const char* msg) { cout << msg << endl; file.close(); }
	}
	void SpellChecker::operator()(std::string & text) const
	{
		for (auto i = 0; i < 5; i++) {
			if (m_badWords != nullptr) {
				while (text.find(m_badWords[i]) != string::npos) text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
			}
		}
	}
}