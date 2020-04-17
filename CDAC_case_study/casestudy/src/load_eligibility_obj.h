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
using namespace std;
vector<Eligibilities>temp_eligibility;
vector<Eligibilities>load_eligibilities(){

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

		temp_eligibility.push_back(e);
	}
	return temp_eligibility;
}



#endif /* LOAD_ELIGIBILITY_OBJ_H_ */
