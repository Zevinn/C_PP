/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
// TODO: add file header comments here

// TODO: add your headers here
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <cstring>
#include "Traveler.h"
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Traveler::Traveler() { 
		Fname[0] = '\0'; 
		Lname[0] = '\0'; 
		Dest[0] = '\0';
		year = 0; 
		month = 0; 
		day = 0;
	};
	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char *fn, const char *ln, const char *dn) {
		if (fn == '\0' || ln == '\0' || dn == '\0') {
			Traveler();
		}
		else {
			strncpy(Fname, fn, max_name_size);
			strncpy(Lname, ln, max_name_size);
			strncpy(Dest, dn, max_destination_size);
			year = 2019;
			month = 7;
			day = 1;
		}
	}
	Traveler::Traveler(const char *fn, const char *ln, const char *dn, int yr, int mt, int d) {
		if (fn == '\0' || ln == '\0' || dn == '\0' || (yr < 2018 && yr > 2023) || (mt < 0 && mt > 13) || (d < 0 && d > 32)) Traveler();
		else {
			strncpy(Fname, fn, max_name_size);
			strncpy(Lname, ln, max_name_size);
			strncpy(Dest, dn, max_destination_size);
			year = yr;
			month = mt;
			day = d;
		}
	}
    // TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {
		bool valid = Fname[0] != '\0' && Lname[0] != '\0' && Dest[0] != '\0' &&
			year > 2018 && year < 2023 && month > 0 && month < 13 && day > 0 && day < 32;

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
			cout << Lname << ", " << Fname << " goes to " << Dest <<
				" on " <<year << "/";
			cout.fill('0');
			cout.width(2);
			cout << month; 
			cout << "/";
			cout.fill('0');
			cout.width(2);
			cout << day << endl;
			
		}
	}
	const char* Traveler::name() const {
		bool empty = isEmpty();
		if (empty == false) return Fname;
		else return nullptr;
	}
	bool Traveler::canTravelWith(const Traveler& traveler) const {
		bool sure = 0; // Can they travel together? sure
		if (year == traveler.year && month == traveler.month && day == traveler.day &&
			strcmp(Dest, traveler.Dest) == 0) {
			sure = true;
		}
		else sure = false;
		return sure;
	}

}