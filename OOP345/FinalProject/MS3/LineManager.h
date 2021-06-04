// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include "Task.h"
#include "CustomerOrder.h"

using namespace std;

class LineManager {
	vector<Task*> AssemblyLine;
	deque<CustomerOrder> ToBeFilled;
	deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
public:
	LineManager(const string&, vector<Task*>&, vector<CustomerOrder>&);
	bool run(ostream&);
	void displayCompleted(ostream&) const;
	void validateTasks() const;

};

