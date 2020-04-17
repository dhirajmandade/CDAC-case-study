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
using namespace std;
class courses {
	int course_id;
	string course_name,fees,section;
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
};

#endif /* COURSES_H_ */
