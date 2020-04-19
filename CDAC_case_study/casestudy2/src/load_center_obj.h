/*
 * get_center_obj.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef LOAD_CENTER_OBJ_H_
#define LOAD_CENTER_OBJ_H_
#include "centers.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<centers>temp_center;
vector<centers>load_centers(){
	ifstream fp;
	fp.open("../centers.csv");
	string line;
	centers c;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		c.setcenter_id(temp);

		getline(str,temp,',');
		c.setcenter_name(temp);

		getline(str,temp,',');
		c.setaddress(temp);

		getline(str,temp,',');
		c.setcoordinator(temp);

		getline(str,temp,',');
		c.setpassword(temp);

		temp_center.push_back(c);
	}
	return temp_center;
}



#endif /* LOAD_CENTER_OBJ_H_ */
