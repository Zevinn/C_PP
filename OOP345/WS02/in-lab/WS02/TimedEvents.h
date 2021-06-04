// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.09.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <chrono>

namespace sdds {

		const int maxRec = 7; // outside the class?
	class TimedEvents {
		unsigned int records; // the number of records currently
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		struct {
			std::string evtName;
			std::string units;
			std::chrono::steady_clock::duration dur;
		} Rec[maxRec]; // Give a way to access to the structure. 

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, sdds::TimedEvents&);
	
	};


}