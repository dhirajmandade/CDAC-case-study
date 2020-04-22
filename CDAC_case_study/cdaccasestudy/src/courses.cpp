/*
 * courses.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "courses.h"
#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "capacities.h"
using namespace std;
courses::courses() {
	// TODO Auto-generated constructor stub

}

courses::~courses() {
	// TODO Auto-generated destructor stub
}

int courses::getcourse_id(){
	return course_id;
}
void courses::setcourse_id(int course_id){
	this->course_id=course_id;
}
string courses::getcourse_name(){
	return course_name;
}
void courses::setcourse_name(string course_name){
	this->course_name=course_name;
}
string courses::getfees(){
	return fees;
}
void courses::setfees(string fees){
	this->fees=fees;
}
string courses::getsection(){
	return section;

}
void courses::setsection(string section){
	this->section=section;
}
void courses::display(){
	cout<<"Course ID:"<<this->getcourse_id()<<endl;
	cout<<"Course Name:"<<this->getcourse_name()<<endl;
	cout<<"Fees:"<<this->getfees()<<endl;
	cout<<"Section:"<<this->getsection()<<endl;
	cout<<"\n"<<endl;
}
void courses::display_eligibility(){

	for(unsigned int i=0;i<temp_eligibility.size();i++){
		cout<<" -";
		temp_eligibility[i].display();
	}
}
vector<Eligibilities>courses::geteligibility(){
	return temp_eligibility;
}
void courses::seteligibility(vector<Eligibilities>& eligibility){
	this->temp_eligibility=temp_eligibility;
}
void courses::display_capacities(vector<capacities>& cap){
	map<string,int>::iterator itr=center_caps.begin();
	while(itr!=center_caps.end())
	{
		cap[itr->second].display();
		itr++;
	}
}


