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
using namespace std;
vector<preferences>temp_pref;
vector<preferences>load_preferences(){

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

		temp_pref.push_back(p);
	}
	return temp_pref;
}




#endif /* LOAD_PREF_OBJ_H_ */
