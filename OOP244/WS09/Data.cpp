// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: 2.0.1
// Date: 2017/12/17
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the answers and readRow functions
// Chris     2017.12.17 removed answers to Q1
///////////////////////////////////////////////////
/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#include <iostream>
#include "Data.h"

using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		
		double dif = population[n - 1] - population[0];
		double growth = dif / 1000000;
		cout << "Population change from " << year[0] <<
			" to " << year[n - 1] << " is ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << growth << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		bool up = violentCrime[0] < violentCrime[n - 1] ? true : false;
		if (up) {
			cout << "Violent Crime trend is up" << endl;
		}
		else cout << "Violent Crime trend is down" << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		double aver = average(grandTheftAuto, n);
		cout << "There are " << aver / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		
		double minimum = 0;
		double maximum = 0;
		minimum = min(violentCrimeRate, n);
		maximum = max(violentCrimeRate, n);
		cout << "The Minimum Violent Crime rate was " << (int)minimum << endl;
		cout << "The Maximum Violent Crime rate was " << (int)maximum << endl;

	}
}