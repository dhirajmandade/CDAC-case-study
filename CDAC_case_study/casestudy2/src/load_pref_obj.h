/*
 * get_pref_obj.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef LOAD_PREF_OBJ_H_
#define LOAD_PREF_OBJ_H_
#include "preferences.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "student.h"
using namespace std;
vector<preferences>pref;
student* find_students(vector<student>& students,int id)
{
	unsigned i;
	for(i=0;i<students.size();i++){
		if(students[i].getid()==id)
			return &students[i];
	}
	return NULL;
}
vector<preferences>load_preferences(vector<student>& students){

	ifstream fin;
	preferences p;
	fin.open("../preferences.csv");
	string line;
	while(getline(fin,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		p.setid(stoi(temp));

		getline(str,temp,',');
		p.set_preferences(temp);

		getline(str,temp,',');
		p.setcourse_name(temp);

		getline(str,temp,',');
		p.setcenter_id(temp);


		student *s=find_students(students,p.getid());

		s->pref.push_back(p);
	}
	return pref;
}




#endif /* LOAD_PREF_OBJ_H_ */
