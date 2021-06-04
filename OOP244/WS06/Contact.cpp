/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Contact.h"

using namespace std;
namespace sict {
	Contact::Contact() {
		names[0] = 0;
		phnum = nullptr;
		num = 0;
		//Contact::Contact() :names{ 0 }, phnum(nullptr > , num(0){};
	}
	Contact::~Contact() { delete[] phnum; phnum = nullptr; }
	Contact::Contact(const char* nm, long long *phnum_, int num_) : Contact() {
		
		
		int count = 0;
		if (phnum_ != nullptr && phnum_[0] != '\0' && num_ > 0) {
			phnum = new long long[num_];
		}
		
		if (nm != nullptr && nm != '\0') {
			strncpy(names, nm, max_name_size);
			names[strlen(names)] = '\0';
		}

		for (int i = 0; i < num_; i++) {
			if (phnum_[i] > 10000000000 && phnum_[i] < 999999999999) {
				int number = phnum_[i] % 10000000;
				int acode = (phnum_[i] / 10000000) % 1000;
				int ccode = phnum_[i] / 10000000000;
				
				if (number >= 1000000 && number <= 9999999 &&
					acode >= 100 && acode <= 999 &&
					ccode >= 1 && ccode <= 99) {
					phnum[count] = phnum_[i];
					count++;
				}
			}
		}
		num = count;
		
	}
	Contact::Contact(const Contact& src) {
		copy(src);
	
	}
	
	Contact& Contact::operator=(const Contact& src) {
		if (this != &src) {
			delete[] phnum;
			phnum = nullptr;
			copy(src);
		}
			return *this;
	}

	Contact& Contact::operator+=(const long long newnum) {
		if (names[0] == 0 || names == nullptr) {

			return *this = Contact();
		}
		
		if (newnum > 10000000000 && newnum < 999999999999) {
			int number = newnum % 10000000;
			int acode = (newnum / 10000000) % 1000;
			int ccode = newnum / 10000000000;

			if (number >= 1000000 && number <= 9999999 &&
				acode >= 100 && acode <= 999 &&
				ccode >= 1 && ccode <= 99) {
				num++;
				long long* temp = new long long[num];
				if (phnum != nullptr && phnum[0] != 0) {
					for (int i = 0; i < num-1; i++) {
						temp[i] = phnum[i];
					}
					delete[] phnum;
					phnum = nullptr;
				}
				phnum = new long long[num];
				temp[num - 1] = newnum;
				for (int j = 0; j < num; j++) {
					phnum[j] = temp[j];
				}
				
				delete[] temp;
				temp = nullptr;
			}
		}
		return *this;
	}

	bool Contact::isEmpty() const {
		bool valid = (names[0] == '\0' && phnum == nullptr && num == 0);
		return valid;
	}

	void Contact::display() const {
		long long first3, back4;
		if (isEmpty() == true)
			cout << "Empty contact!" << endl;
		else {
			cout << names << endl;
			for (int i = 0; i < num; i++) {
				int number = phnum[i] % 10000000;
				int acode = (phnum[i] / 10000000) % 1000;
				int ccode = phnum[i] / 10000000000;
				first3 = number / 10000;
				back4 = number % 10000;
				cout << "(+" << ccode << ") " << acode << " " << first3 << "-";
				cout.fill('0');
				cout.width(4);
				cout << back4 << endl;
			}
		}
	}
	void Contact::copy(const Contact& src) { // To reduce copying duplication
		strncpy(names, src.names, max_name_size);
		names[strlen(names)] = '\0';
		num = src.num;
		if (src.phnum != 0 && src.phnum != nullptr) {
			phnum = new long long[src.num]; // ********************* IMPORTANT ***********************
			for (int i = 0; i < src.num; i++) {
				phnum[i] = src.phnum[i];
			}
		}
	}
}