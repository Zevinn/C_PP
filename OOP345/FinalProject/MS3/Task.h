// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Item.h"

using namespace std;

class Task : public Item {
	deque<CustomerOrder> m_orders;
	Task* m_pNextTask;
public:
	Task(const string&);
	
	//Any copy and move functions are deleted ----
	Task(const Task&) = delete;
	Task& operator=(const Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;
	//--------------------------------------------

	void runProcess(ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(ostream&);
	Task& operator+=(CustomerOrder&&);

};