/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "ErrorState.h"
using namespace std;
namespace ama {
	
	ErrorState::ErrorState(const char* errorMessage) : msge(nullptr) {
		if (errorMessage == nullptr || errorMessage[0] == '\0' || errorMessage == 0) {
			msge = '\0';
		}
		else {
			
			msge = new char[strlen(errorMessage) +1];
			strncpy(msge, errorMessage, strlen(errorMessage));
			msge[strlen(errorMessage)] = '\0';
		}
		//copy(errorMessage);
	}

	//ErrorState::ErrorState(const ErrorState& other) {copy(other);}

	/*ErrorState& ErrorState::operator=(const ErrorState& other) {
		if (this != &other) {
			delete[] msge;
			msge = nullptr;
			copy(other);
		}
		return *this;
	}*/

	void ErrorState::copy(const char *src) { // copy duplication, define just in case it will be used in further Milestone;
		
		if (src != nullptr && src != 0 && src[0] != '\0') {
			msge = new char[strlen(src) +1];
			strncpy(msge, src, strlen(src));
			msge[strlen(src)] = '\0';
		}
		else msge = '\0';
	}

	ErrorState::~ErrorState() { delete[] msge; msge = nullptr; }

	ErrorState::operator bool() const {
		return (msge == nullptr || msge[0] == '\0') ? false : true;
	}

	ErrorState& ErrorState::operator=(const char *pText) {
		
		copy(pText);
		return *this;
	}

	void ErrorState::message(const char* pText) {
		delete[] msge;
		copy(pText);
	}

	const char* ErrorState::message() const {
		if (msge == '\0' || msge == 0) return nullptr;
		else return msge;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& msg) {
		if (msg.operator bool()) {
			os << msg.message();
		}
			return os;
		
	}
}