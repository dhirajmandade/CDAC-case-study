/*
 * centers.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "centers.h"
#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
centers::centers() {
	// TODO Auto-generated constructor stub

}

centers::~centers() {
	// TODO Auto-generated destructor stub
}
string centers::getcenter_id(){
	return center_id;
}
void centers::setcenter_id(string center_id){
	this->center_id=center_id;
}
string centers::getcenter_name(){
	return center_name;
}
void centers::setcenter_name(string center_name){
	this->center_name=center_name;
}
string centers::getaddress(){
	return address;
}
void centers::setaddress(string address){
	this->address=address;
}
string centers::getcoordinator(){
	return coordinator;
}
void centers::setcoordinator(string coordinator){
	this->coordinator=coordinator;
}
string centers::getpassword(){
	return password;
}
void centers::setpassword(string password){
	this->password=password;
}
void centers::display(){

	cout<<"Center Id:"<<this->getcenter_id()<<endl;
	cout<<"Center Name:"<<this->getcenter_name()<<endl;
	cout<<"Address:"<<this->getaddress()<<endl;
	cout<<"Coordinator:"<<this->getcoordinator()<<endl;
	cout<<"Password:"<<this->getpassword()<<endl;
	cout<<"\n"<<endl;

}
void centers::display_centers_capacities(vector<capacities>& cap){
	map<string,int>::iterator itr=course_caps.begin();
		while(itr!=course_caps.end())
		{
			cap[itr->second].display();
			itr++;
		}
}
