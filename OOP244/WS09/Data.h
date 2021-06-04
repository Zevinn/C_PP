// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////
/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef DATA_H__
#define DATA_H__
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>

using namespace std;
namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH = 15;
	const int DES_WIDTH = 20;

	// max returns the largest item in data
	//
	template<typename T>
	T max(const T* data, int n) {
		T largest = data[0];
		for (int i = 1; i < n; i++) {
			largest = data[i] > largest ? data[i] : largest;
		}
		return largest;
	}

	// min returns the smallest item in data
	//
	template<typename T>
	T min(const T* data, int n) {
		T smallest = data[0];
		for (int i = 1; i < n; i++) {
			smallest = data[i] < smallest ? data[i] : smallest;
		}
		return smallest;
	}

	// sum returns the sum of n items in data
	//    
	template<typename T>
	T sum(const T* data, int n) {
		T sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		return sum;
	}
	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n) {
		T sumup = sum(data, n);
		double aver = sumup / n;
		
		return aver;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		string temp;
		bool good;
		int i;
		getline(input, temp, ',');
		for (i = 0; i < n-1; i++) {
			getline(input, temp, ',');
			stringstream(temp) >> data[i];
			good = input.bad(); // checking if reading error occurs. returns true if error occurs, false otherwise.
		}
		 // last one isn't ',' but '\n'
		input >> data[i];
		good = input.bad();
		

		return !good; // or input.bad();
	}
	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char* name, const T* data, int n) {
		cout.setf(ios::right);
		cout.width(DES_WIDTH);
		cout << name;
		for (int i = 0; i < n; i++){
		cout.width(COLUMN_WIDTH);
		cout << data[i];
		}
		cout << endl;
	}
	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,...

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif