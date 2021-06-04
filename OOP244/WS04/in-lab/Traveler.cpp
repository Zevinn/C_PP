/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Traveler.h"
using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Traveler::Traveler() { Fname[0] = '\0'; Lname[0] = '\0'; Dest[0] = '\0';};
	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char *fn, const char *ln, const char *dn) {
		if (fn == 0 || ln == 0 || dn == 0) {
			Traveler();
		}
		else {
			strncpy(Fname, fn, max_name_size);
			strncpy(Lname, ln, max_name_size);
			strncpy(Dest, dn, max_destination_size);
					
		}
	}
    // TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {
		bool valid = strlen(Fname) != 0 && strlen(Lname) != 0 && strlen(Dest) != 0;
		if (!valid) {
			return true;
		}
		else return false;
	}
    // TODO: implement display query here
	void Traveler::display() const {
		if (isEmpty() == true) {
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else{
			cout << Fname << " " << Lname << " goes to " << Dest << endl;
			
		}
	}
}