/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef ERROR_STATE_H__
#define ERROR_STATE_H__
#include <iostream>
namespace ama {

class ErrorState {
	char* msge;
public:
	explicit ErrorState(const char* errorMessage = nullptr);
	ErrorState(const ErrorState& other) = delete;
	ErrorState& operator=(const ErrorState& other) = delete;
	~ErrorState();
	operator bool() const;
	ErrorState& operator=(const char* pText);
	void message(const char* pText);
	const char* message() const;
	void copy(const char*);
};

std::ostream& operator<<(std::ostream& os, const ErrorState& msg);

} // end bracket;
#endif
