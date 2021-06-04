// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.06
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define CRT_NO_SECURE_WARNINGS


#include <iostream>
#include "ConfirmationSender.h"
#include "Reservation.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() : ResP {nullptr}, thesize {0}
	{
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender &src)
	{
		
		ResP = nullptr;
		*this = src;
	
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender &&src)
	{
		ResP = nullptr;
		*this = std::move(src);
	}
	ConfirmationSender & ConfirmationSender::operator=(const ConfirmationSender &src) 
		// ***** need to make sure what you delete after checking if the sources are the same, is not already nullptr. 
		//It occured segmentation fault, as well as in the copy constructors, which is why I put 'ResP = nullptr;' before '*this = src;'
	{
		if (this != &src) {
			if (ResP != nullptr) {
				delete [] ResP;
			}
			thesize = src.thesize;
			if (src.ResP != nullptr) {

				ResP = new const Reservation*[thesize];
				for (int i = 0; i < src.thesize; i++) {
					ResP[i] = src.ResP[i];
				}
			}
		}
		return *this;
	}
	ConfirmationSender & ConfirmationSender::operator=(ConfirmationSender &&src)
	{
		if (this != &src) {
			if (ResP != nullptr) {
				delete [] ResP;
			}
			thesize = src.thesize;
			ResP = src.ResP;

			src.thesize = 0;
			src.ResP = nullptr;
		}
		return *this;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		if (ResP != nullptr) {
			delete [] ResP;
			ResP = nullptr;
		}
	}
	ConfirmationSender & ConfirmationSender::operator+=(const Reservation & res)
	{
		bool found = false;
		for (int i = 0; i < thesize; i++) { // Looking for the same one.
			if (ResP[i] == &res) found = true;
		}
		if (!found) { //if not found
			const Reservation** temp = new const Reservation*[thesize + 1]; // Create a temporary container to hold the original values.
			for (int x = 0; x < thesize; x++) {
				temp[x] = ResP[x]; // copy the original into the temporary container
			}
			delete [] ResP; // delete the original
			temp[thesize] = &res; // accept the resource 
			ResP = new const Reservation*[thesize + 1]; // Create the original again resizing
			thesize++;
			for (int x = 0; x < thesize; x++) { // Copy the values of the temp into the Original
				ResP[x] = temp[x];
			}
			delete [] temp;
			temp = nullptr; // make sure to delete the temp values.
		}
		return *this;
	}
	ConfirmationSender & ConfirmationSender::operator-=(const Reservation & res)
	{
		bool found = false;
		int index; // Look for the same one as the resource to remove and hold the index of the same one 
		for (int i = 0; i < thesize; i++) {
			if (ResP[i] == &res) { 
				found = true; 
				index = i;
			}
		}
		if (found) {
			ResP[index] = nullptr; // remove the resource one.
			const Reservation** temp = new const Reservation*[thesize]; // create a temporary container to hold the original
			for (int i = 0; i < index; i++) { // copying the values up to before the index
				temp[i] = ResP[i];
			}
			for (int i = index + 1; i < thesize; i++) { // copying the values after the index
				temp[i] = ResP[i];
			}
			delete [] ResP; // delete the original
			ResP = new const Reservation*[thesize-1]; // Create the original resizing
			thesize--;
			for (int i = 0; i < thesize; i++) {
				ResP[i] = temp[i]; // copy the values into the remade original
			}
			delete [] temp;
			temp = nullptr; // make sure to delete the temp container
		}
		return *this;
	}
	
	std::ostream & operator<<(std::ostream & out, const ConfirmationSender & res)
	{
		out << "--------------------------" << std::endl;
		out << "Confirmations to Send" << std::endl;
		out << "--------------------------" << std::endl;
		if (res.ResP == nullptr) {
			out << "The object is empty!" << std::endl;
			out << "--------------------------" << std::endl;
		}
		else {
			for (int i = 0; i < res.thesize; i++) {
				out << *(res.ResP[i]); // the ARRAY of POINTERS, Need to dereference TWICE!
			}
			out << "--------------------------" << std::endl;
		}

		return out;
	}
}