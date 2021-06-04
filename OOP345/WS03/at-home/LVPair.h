// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.09.25
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef LVPAIR_H__
#define LVPAIR_H__

#include <iostream>

namespace sdds {
	
	template <typename L, typename V>
	class LVPair {
		L label;//
		V val; // VALUE
	public:
		LVPair() : label{ }, val{ } {}
		LVPair(const L& aa, const V& bb) {
			//if (aa != nullptr)
				label = aa;
				val = bb;
		}
		const L& key() const { return label; }
		const V& value() const { return val; }
		virtual void display(std::ostream& os) const { os << label << ": " << val << std::endl; }
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V inV; // *** need an initialization outside the scope before use ***
		static size_t minWidth; // *** need an initialization outside the scope before use ***
	public:
		SummableLVPair() { }
		SummableLVPair(const L& lbl, const V& val2) : LVPair<L, V>(lbl, val2) {
			
			if (lbl.size() >= minWidth) minWidth = lbl.size() + 1;
			
		}
		static const V& getInitialValue() {return inV;}

		V sum(const L& lbl, const V& val2) const {
			if (LVPair<L,V>::key() == lbl) return val2 + LVPair<L, V>::value();
			else return val2; // not returning current object??
		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minWidth);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};
	// !!!!!!!!!!! IMPORTANT, why I was lost within unresolved symbol linkage errors. 
	// Static variables originally should be initialized in either .cpp file. 
	// In this case within a template, these should be initialized outside the scope(class) explicitly specifying the scope.
	template<typename L, typename V>
	V SummableLVPair<L, V>::inV = 0;

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::minWidth = 0;
	
	// specializations
	// All done with scope specification
	
	template <>
	std::string SummableLVPair<std::string, std::string>::inV = "";
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& val2) const {
		if (LVPair<std::string, std::string>::key() == lbl) {
			if (val2 == "") return LVPair<std::string, std::string>::value();
			else return  val2 + ", " + LVPair<std::string, std::string>::value();
		}
		else return LVPair<std::string, std::string>::value();	
	}
	template <>
	int SummableLVPair<std::string, int>::inV = 0;

}
#endif
