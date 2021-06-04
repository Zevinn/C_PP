// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.09.25
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef LIST_H__
#define LIST_H__


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
			// check if list has hit the number of maximum space, if not, it stores the value in the current number and get the next space ready.
			if (num < N) list[num++] = tt; 
		}


	};

	template <typename L, typename V, typename T, size_t N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			 // to store label values in a V object
			V sumUp = T::getInitialValue();

			for (size_t i = 0; i < (*this).size(); i++) {
				if(label == (*this)[i].key())
				sumUp = (*this)[i].sum(label, sumUp);
			}
			return sumUp;
		}

	};

}
#endif // !LIST_H__