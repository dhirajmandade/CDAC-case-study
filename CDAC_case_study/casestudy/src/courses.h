/*
 * courses.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef COURSES_H_
#define COURSES_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Eligibilities.h"
#include "capacities.h"
using namespace std;
class courses {
	int course_id;
	string course_name,fees,section;
public:
	vector<Eligibilities>temp_eligibility;
	map<string,int>center_caps;
public:
	courses();
	virtual ~courses();
	int getcourse_id();
	void setcourse_id(int course_id);
	string getcourse_name();
	void setcourse_name(string course_name);
	string getfees();
	void setfees(string fees);
	string getsection();
	void setsection(string section);
	void display();
	void display_eligibility();
	vector<Eligibilities>geteligibility();
	void seteligibility(vector<Eligibilities>& eligibility);
	void display_capacities(vector<capacities>& cap);

};

#endif /* COURSES_H_ */
