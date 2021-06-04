// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "Movie.h"
#include "Book.h"

using namespace std;
namespace sdds {

	template <typename T>
	class Collection {
		string coll_name;
		T * collec;
		size_t t_size;
		void(*obs)(const Collection<T>&, const T&);
	public:
		Collection(string name) {
			coll_name = name;
			collec = nullptr;
			t_size = 0;
			obs = nullptr;
		}
		Collection(const Collection& src) = delete;
		Collection(Collection&&) = delete;
		//Collection& operator=(const Collection&) = delete;
		//Collection& operator=(Collection&&) = delete;
		~Collection() {
			delete[] collec;
			collec = nullptr;
			--t_size;
		}
		const string& name() const {
			return coll_name;
		}
		size_t size() const {
			return t_size;
		}
		void setObserver(void(*observer)(const Collection<T>&, const T&)) {
			obs = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool found = false;
			for (auto i = 0u; i < size(); i++) {
				if (collec[i].title() == item.title()) found = true;
			}
			if (!found) {
				T* temp = new T[size() + 1];
				for (auto i = 0u; i < size(); i++) {
					temp[i] = collec[i];
				}
				delete[] collec;
				temp[size()] = item;
				collec = temp;
				t_size++;
				temp = nullptr;
				if (obs != nullptr) obs(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			
			if (idx >= this->size()) throw std::out_of_range("Bad index [" + to_string(idx) + "]. Collection has [" + to_string(size()) + "] items.");
			else return collec[idx];	
		}

		T* operator[](std::string m_title) const {
			size_t index = this->size() + 1;
			for (auto i = 0u; i < size(); i++) {
				if (collec[i].title() == m_title) index = i;
			}
			if (index > size()) return nullptr;
			else return &collec[index];
		}
	};

	template<typename T>
	ostream & operator<<(ostream& out, const Collection<T>& src) {
		for (auto i = 0u; i < src.size(); i++) {
			out << src[i];
		}
		return out;
	}

}

#endif