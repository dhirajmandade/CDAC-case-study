#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
#include "preferences.h"
preferences::preferences(){

}
preferences::preferences(int id,int preference,string course_name,string center_id){
	this->id=id;
	this->preference=preference;
	this->course_name=course_name;
	this->center_id=center_id;
}
int preferences::getid(){
	return id;

}
void preferences::setid(int id){
	this->id=id;
}
int preferences::get_preferences(){
	return preference;
}
void preferences::set_preferences(int preference){
	this->preference=preference;
}
string preferences::getcourse_name(){
	return course_name;
}
void preferences::setcourse_name(string course_name){
	this->course_name=course_name;
}
string preferences::getcenter_id(){
	return center_id;
}
void preferences::setcenter_id(string center_id){
	this->center_id=center_id;
}
void preferences::accept(){
	cout<<"ENTER PREFERENCES"<<endl;
	/*cout<<"Enter Form no:";
	cin>>this->id;*/
	cout<<"Enter Pref no:";
	cin>>this->preference;
	cout<<"Enter Course name:";
	cin>>this->course_name;
	cout<<"Enter Center ID:";
	cin>>this->center_id;
}
void preferences::display(){
	cout<<"Form No:"<<this->getid()<<endl;
	cout<<"Pref No:"<<this->get_preferences()<<endl;
	cout<<"Course name:"<<this->getcourse_name()<<endl;
	cout<<"Center id:"<<this->getcenter_id()<<"\n"<<endl;



}
preferences::~preferences(){

}
