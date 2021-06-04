// Name: Min Woo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include "LineManager.h"

using namespace std;
/*so basically you have to loop for each line in the file. 
Grab the line with getline. There will be two tokens to extract. 
You have to extract each, find the corresponding Task object for both of them 
based on the strings you have extracted 
(compare the string read to the name of each task object 
in the assembly line vector until you find a match).
Once you do that, you have to set the first task object's
(the task object corresponding to the first token read) 
NEXT TASK pointer to be equal to the second task object
(that is, the second task object corresponding to the second token read). 
Now for that line the has one token...simply set the NEXT TASK of 
the task object associated with name read from the file to nullptr.*/
LineManager::LineManager(const string& filename, vector<Task*>& allTasks, vector<CustomerOrder>& Orders)
{
	ifstream file(filename);
	m_cntCustomerOrder = 0;
	string temp, f, s; // temporary string to extract a line by a line, First task and Second task
	size_t index = 0;
	while (!file.eof() && index != string::npos) {
		getline(file, temp, '\n');
		index = temp.find('|');
		if (index != string::npos) { // until last line of the file content
			f = temp.substr(0, index);
			temp.erase(0, index + 1);
			s = temp;
			for (size_t i = 0; i < allTasks.size(); i++) {
				if (allTasks[i]->getName() == f) {
					for (size_t x = 0; x < allTasks.size(); x++) {
						if (allTasks[x]->getName() == s) allTasks[i]->setNextTask(*allTasks[x]);
						if (m_cntCustomerOrder == 0) m_cntCustomerOrder = i;
					}
				}	
			}
		}
		else { // Do I need this part?
			f = temp;
			for (Task* tasks : allTasks) {
				if (tasks->getName() == f) {
					Task* t = nullptr;
					tasks->setNextTask(*t);
				}
			}
		}
	}
	file.close();

	for (size_t i = 0; i < Orders.size(); i++) {
		ToBeFilled.push_front(move(Orders[i]));
	}
	AssemblyLine = allTasks;
}

bool LineManager::run(ostream & out)
{
// move the last 'CustomerOrder' object onto the starting point of the 'Assembly Line' ...?
	
	if (!ToBeFilled.empty()) {
		*AssemblyLine[m_cntCustomerOrder] += move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}
	for (Task* a : AssemblyLine) { // run one cycle of Task porcess
		a->runProcess(out);
	}
	for (Task* a : AssemblyLine) { //
		CustomerOrder temp;
		a->moveTask();
		if (a->getCompleted(temp)) Completed.push_back(move(temp));
	}
	return m_cntCustomerOrder == Completed.size() ? true : false;
	 // if Completed deque got the full number of the CustomerOrders defined in first place
}

void LineManager::displayCompleted(ostream & out) const
{
	for_each(Completed.begin(), Completed.end(), [&out](auto& c) { c.display(out); });
}

void LineManager::validateTasks() const
{
	for (Task* t : AssemblyLine) t->validate(cout);
}
