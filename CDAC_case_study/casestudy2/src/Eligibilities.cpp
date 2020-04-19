/*
 * Eligibilities.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "Eligibilities.h"
#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
Eligibilities::Eligibilities() {
	// TODO Auto-generated constructor stub

}

Eligibilities::~Eligibilities() {
	// TODO Auto-generated destructor stub
}

string Eligibilities::getcourse_name(){
	return course_name;

}
void Eligibilities::setcourse_name(string course_name){
	this->course_name=course_name;
}
string Eligibilities::getdegree(){
	return degree;
}
void Eligibilities::setdegree(string degree){
	this->degree=degree;
}
double Eligibilities::getmin_marks(){
	return min_marks;
}
void Eligibilities::setmin_marks(double min_marks){
	this->min_marks=min_marks;
}
void Eligibilities::display(){
	cout<<"course name:"<<this->getcourse_name()<<endl;
	cout<<"Degree:"<<this->getdegree()<<endl;
	cout<<"min marks:"<<this->getmin_marks()<<endl;
	cout<<"\n"<<endl;

}
