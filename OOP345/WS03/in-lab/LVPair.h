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
		L label;
		V val; // VALUE
	public:
		LVPair() : label{ }, val{ } {}
		LVPair(const L& aa, const V& bb) : label{ aa }, val{ bb } {
			//if (aa != nullptr)
				//label = aa;
				//val = bb;
		}
		const L& key() const { return label; }
		const V& value() const { return val; }
		void display(std::ostream& os) const { os << label << " : " << val << std::endl; }
	};
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair) {
		pair.display(os);
		return os;
		}

}
#endif
