/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
// TODO: header file guard
#ifndef FRACTION_H__
#define FRACTION_H__

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numer;
		int denom;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction&) const;
		Fraction operator*(const Fraction&) const;
		bool operator==(const Fraction&) const;
		bool operator!=(const Fraction&) const;
		Fraction operator+=(const Fraction&);
	};
}

#endif