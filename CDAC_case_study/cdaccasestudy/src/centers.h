/*
 * centers.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef CENTERS_H_
#define CENTERS_H_
#include <string>
#include <map>
#include <vector>
#include "capacities.h"
using namespace std;
class centers {
	string center_id,center_name,address,coordinator,password;
public:
	map<string,int>course_caps;
public:
	centers();
	virtual ~centers();
	string getcenter_id();
	void setcenter_id(string center_id);
	string getcenter_name();
	void setcenter_name(string center_name);
	string getaddress();
	void setaddress(string address);
	string getcoordinator();
	void setcoordinator(string coordinator);
	string getpassword();
	void setpassword(string password);
	void display();
	void display_capacities(vector<capacities>& cap);
};

#endif /* CENTERS_H_ */
