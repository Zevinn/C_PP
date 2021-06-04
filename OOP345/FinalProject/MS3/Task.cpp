// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Task.h"

using namespace std;

Task::Task(const string& record) : Item(record)
{
	m_pNextTask = nullptr;
}

void Task::runProcess(ostream & out)
{ 
	if (!m_orders.empty()) {
		if (!m_orders.back().getItemFillState(this->getName())) {
			m_orders.back().fillItem(*this, out);
			
		}
	}
}

bool Task::moveTask()
{
	if (m_orders.empty()) return false;
	else if (m_orders.back().getItemFillState(this->getName())) {
		
		if (m_pNextTask != nullptr) {
			*m_pNextTask += move(m_orders.back());
			m_orders.pop_back();
		}
		return true;
	} 
	else return false;
}

void Task::setNextTask(Task & theTask)
{
	m_pNextTask = move(&theTask);
}

bool Task::getCompleted(CustomerOrder & Order)
{
	if (m_orders.empty()) return false;
	if (m_orders.back().getOrderFillState()) {
		Order = move(m_orders.back());
		m_orders.pop_back();
		return true;
	}
	else return false;
}

void Task::validate(ostream & out)
{
	out << this->getName() + " --> ";
	if (m_pNextTask != nullptr) {
		out << m_pNextTask->getName();
	}
	else out << "END OF LINE";
	out << endl;
}

Task & Task::operator+=(CustomerOrder && newOne)
{
	m_orders.push_front(move(newOne));
	return *this;
}
