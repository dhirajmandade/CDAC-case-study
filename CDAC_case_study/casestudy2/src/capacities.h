/*
 * capacities.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef CAPACITIES_H_
#define CAPACITIES_H_
#include <string>
using namespace std;


class capacities {
	string center_id,course_name;
	string capacity,filled_capacity;

public:
	capacities();
	string getcenter_id();
	void setcenter_id(string center_id);
	string getcourse_name();
	void setcourse_name(string course_name);
	string getcapacity();
	void setcapacity(string capacity);
	string getfilled_capacity();
	void setfilled_capacity(string filled_capacity);
	void display();
	virtual ~capacities();
};

#endif /* CAPACITIES_H_ */
