/*
 * Eligibilities.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef ELIGIBILITIES_H_
#define ELIGIBILITIES_H_
#include <iostream>
#include <string>
using namespace std;
class Eligibilities {
	string course_name,degree;
	double min_marks;
public:
	Eligibilities();
	virtual ~Eligibilities();
	string getcourse_name();
	void setcourse_name(string course_name);
	string getdegree();
	void setdegree(string degree);
	double getmin_marks();
	void setmin_marks(double min_marks);
	void display();

};

#endif /* ELIGIBILITIES_H_ */
