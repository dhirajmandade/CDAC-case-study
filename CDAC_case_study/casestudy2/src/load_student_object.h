/*
 * get_student_object.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#ifndef LOAD_STUDENT_OBJECT_H_
#define LOAD_STUDENT_OBJECT_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include "student.h"
vector<student>temp;

vector<student>load_students(){

	ifstream fp;

	string line;
	fp.open("../students.csv");

	while(getline(fp,line)){
		stringstream str(line);
		string tokens[13];
			for(int i=0;i<13;i++)
				getline(str,tokens[i],',');
			student s(stoi(tokens[0]),tokens[1],stoi(tokens[2]),stoi(tokens[3]),stoi(tokens[4]),tokens[5],stod(tokens[6]),tokens[7],tokens[8],tokens[9],tokens[10],tokens[11],tokens[12]);
			temp.push_back(s);
			//c++;
	}
	return temp;

}

#endif /* LOAD_STUDENT_OBJECT_H_ */
