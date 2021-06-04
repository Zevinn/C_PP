/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
 // TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() { 
		numer = 0; 
		denom = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int nu, int de) {
		if (nu <= 0 || de <= 0) {
			*this = Fraction();
		}
		else { 
			numer = nu; denom = de;
			reduce();
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		if (numer > denom) return numer;
		else return denom;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		if (numer < denom) return numer;
		else return denom;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int divisor = gcd();
		numer = numer / divisor;
		denom = denom / divisor;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		
		if (numer > 0) {
			if (denom > 0 && denom != 1) {
				cout << numer << "/" << denom;
			}
			if (denom == 1) {
				cout << numer;
			}
		}
		else {
			cout << "no fraction stored";
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (numer == 0 && denom == 0) return true;
		else return false;
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction temp(0, 0);
		if (isEmpty() == 0 && rhs.isEmpty() == 0) {
			temp.numer = numer * rhs.denom + denom * rhs.numer;
			temp.denom = denom * rhs.denom;
		}
		/*if (isEmpty() == 0 && rhs.isEmpty() == 0) {
			Fraction temp((numer * rhs.denom + denom * rhs.numer), (denom * rhs.denom));
			temp.reduce();
			return temp;
		}*/
		return temp;	
	}
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction temp(0, 0);
		if (/*temp.*/isEmpty() == 0 && rhs.isEmpty() == 0) {
			temp.numer = numer * rhs.numer;
			temp.denom = denom * rhs.denom;
			temp.reduce();
		}
		return temp;
	}

	bool Fraction::operator==(const Fraction& rhs) const {
		if (isEmpty() == 0 && rhs.isEmpty() == 0) {
			if (numer/denom == rhs.numer/rhs.denom) {
				return true;
			}
			else return false;
		}
		else return false;
	}

	bool Fraction::operator!=(const Fraction& rhs) const {
		if (isEmpty() == 0 && rhs.isEmpty() == 0) {
			return *this == rhs ? false : true;
		}
		else return false;
	}

	Fraction Fraction::operator+=(const Fraction& rhs){
		if (isEmpty() == 0 && rhs.isEmpty() == 0) {
			Fraction temp = (*this + rhs);
			temp.reduce();
			*this = temp;
			return *this;
		}
		else {
			Fraction();
			return *this;
		}
	
	}
}