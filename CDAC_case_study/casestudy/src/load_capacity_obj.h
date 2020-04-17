/*
 * get_capacity_obj.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef LOAD_CAPACITY_OBJ_H_
#define LOAD_CAPACITY_OBJ_H_
#include "capacities.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<capacities>temp_cap;
vector<capacities>load_capacities(){
	ifstream fp;
	fp.open("../capacities.csv");
	string line;
	capacities c;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		c.setcenter_id(temp);

		getline(str,temp,',');
		c.setcourse_name(temp);

		getline(str,temp,',');
		c.setcapacity(temp);

		getline(str,temp,',');
		c.setfilled_capacity(temp);

		temp_cap.push_back(c);
	}
	return temp_cap;
}


#endif /* LOAD_CAPACITY_OBJ_H_ */
