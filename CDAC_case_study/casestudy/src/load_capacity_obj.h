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
#include "centers.h"
#include "courses.h"
using namespace std;
vector<capacities>temp_cap;
courses* find_course(vector<courses>& course,string course_name){
	unsigned i;
	for(i=0;i<course.size();i++)
	{
		if(course[i].getcourse_name()==course_name)
			return &course[i];
	}
	return NULL;
}
centers* find_centers(vector<centers>& cent,string center_id){
	unsigned i;
		for(i=0;i<cent.size();i++)
		{
			if(cent[i].getcenter_id()==center_id)
				return &cent[i];
		}
		return NULL;
}
vector<capacities>load_capacities(vector<courses>& course,vector<centers>& cent){
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
		courses *cptr=find_course(course,c.getcourse_name());
		cptr->center_caps[c.getcenter_id()]=temp_cap.size()-1;

		centers *cpptr=find_centers(cent,c.getcenter_id());
		cpptr->course_caps[c.getcourse_name()]=temp_cap.size()-1;
	}
	return temp_cap;
}
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
