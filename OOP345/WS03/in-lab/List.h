// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.09.25
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#pragma once
#include <iostream>

namespace sdds {

	template <typename T, size_t N>
	class List {
		T list[N];
		size_t num = 0; // the current number of the array
	public:
		size_t size() const { return num; }
		const T& operator[](size_t i) const { return list[i]; }
		void operator+=(const T& tt) {
			if (num < N) list[num++] = tt;
		}


	};

}
