/*
 * capacities.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "capacities.h"
#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
capacities::capacities() {
	// TODO Auto-generated constructor stub

}




string capacities::getcenter_id(){
	return center_id;
}
void capacities::setcenter_id(string center_id){
	this->center_id=center_id;
}
string capacities::getcourse_name(){
	return course_name;

}
void capacities::setcourse_name(string course_name){
	this->course_name=course_name;
}
int capacities::getcapacity(){
	return capacity;
}
void capacities::setcapacity(int capacity){
	this->capacity=capacity;
}
int capacities::getfilled_capacity(){
	return filled_capacity;
}
void capacities::setfilled_capacity(int filled_capacity){
	this->filled_capacity=filled_capacity;
}
void capacities::display(){
	cout<<"Center ID:"<<this->getcenter_id()<<endl;
	cout<<"Course Name:"<<this->getcourse_name()<<endl;
	cout<<"Capacity:"<<this->getcapacity()<<endl;
	cout<<"filled capacity:"<<getfilled_capacity()<<endl;
	cout<<"\n"<<endl;
}
void capacities::display_centerandcourse(){
	cout<<getcourse_name()<<endl;
}
capacities::~capacities(){

}
