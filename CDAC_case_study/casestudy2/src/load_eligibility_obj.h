/*
 * load_eligibility_obj.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef LOAD_ELIGIBILITY_OBJ_H_
#define LOAD_ELIGIBILITY_OBJ_H_
#include "load_eligibility_obj.h"
#include "Eligibilities.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "courses.h"
using namespace std;
vector<Eligibilities>eligibility;
courses* find_courses(vector<courses>& course,string course_name)
{
	unsigned i;
	for(i=0;i<course.size();i++){
		if(course[i].getcourse_name()==course_name)
			return &course[i];
	}
	return NULL;
}
vector<Eligibilities>load_eligibilities(vector<courses>& course){

	ifstream fp;
	fp.open("../eligibilities.csv");
	string line;
	Eligibilities e;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		e.setcourse_name(temp);

		getline(str,temp,',');
		e.setdegree(temp);

		getline(str,temp,',');
		e.setmin_marks(stod(temp));

		courses *c=find_courses(course,e.getcourse_name());

		c->eligibility.push_back(e);
	}
	return eligibility;
}



#endif /* LOAD_ELIGIBILITY_OBJ_H_ */
