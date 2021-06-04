// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.09.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "TimedEvents.h"


using namespace std;

namespace sdds
{
	TimedEvents::TimedEvents() : records{ 0 }, start {}, end{}
	{
	}

	void TimedEvents::startClock()
	{
		start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		end = std::chrono::steady_clock::now();
	}
	
	void TimedEvents::recordEvent(const char * s_name)
	{
		static int count = 0;
		Rec[count].evtName = s_name;
		Rec[count].units = "nanoseconds";
		Rec[count].dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		count++;
		records++;
	}
	
	
	
	std::ostream& operator<<(std::ostream & out, TimedEvents & te)
	{
		out << "--------------------------" << endl;
		out << "Execution Times:" << endl;
		out << "--------------------------" << endl;
		for (size_t i = 0; i < te.records; i++) {
			out << left << setw(20) << te.Rec[i].evtName
				<< right << setw(12) << std::chrono::duration_cast<std::chrono::nanoseconds>(te.Rec[i].dur).count()
				<< ' ' << te.Rec[i].units << endl;
		}
		out << "--------------------------" << endl;
		return out;
	}


}
