/*
 * load_course_obj.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef LOAD_COURSE_OBJ_H_
#define LOAD_COURSE_OBJ_H_
#include "courses.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<courses>temp_courses;

vector<courses> load_courses(){
	ifstream fp;
	fp.open("../courses.csv");
	string line;
	courses c1;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		c1.setcourse_id(stoi(temp));

		getline(str,temp,',');
		c1.setcourse_name(temp);


		getline(str,temp,',');
		c1.setfees(temp);

		getline(str,temp,',');
		c1.setsection(temp);

		temp_courses.push_back(c1);
	}
	return temp_courses;
}

#endif /* LOAD_COURSE_OBJ_H_ */
