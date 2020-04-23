/*
 * student.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */
#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
#include "student.h"
#include "preferences.h"
student::student() {
	this->id=0;
	this->name="xyz";
	this->rank_a=0;
	this->rank_b=0;
	this->rank_c=0;
	this->degree="BE";
	this->degree_marks=90.0;
	this->course_name="DAC";
	this->center_id="SIP";
	this->payment=0.0;
	this->reported="";
	this->prn="";
	this->alloc_pref=0;




}
student::student(int id,string name,int rank_a,int rank_b,int rank_c,string degree,double degree_marks,int alloc_pref,string course_name,string center_id,double payment,string reported,string prn){
	this->id=id;
	this->name=name;
	this->rank_a=rank_a;
	this->rank_b=rank_b;
	this->rank_c=rank_c;
	this->degree=degree;
	this->degree_marks=degree_marks;
	this->course_name=course_name;
	this->alloc_pref=alloc_pref;
	this->center_id=center_id;
	this->payment=payment;
	this->reported=reported;
	this->prn=prn;


}
student::~student() {
	// TODO Auto-generated destructor stub
}
int student::getid(){
	return id;
}
void student::setid(int id){
	this->id=id;
}
string student::getname(){
	return name;
}
void student::setname(string name){
	this->name=name;
}
int student::getrankA(){
	return rank_a;
}
void student::setrankA(int rank_a){
	this->rank_a=rank_a;
}
int student::getrankB(){
	return rank_b;
}
void student::setrankB(int rank_b){
	this->rank_b=rank_b;
}
int student::getrankC(){
	return rank_c;
}
void student::setrankC(int rank_c){
	this->rank_c=rank_c;
}
string student::getdegree(){
	return degree;
}
void student::setdegree(string degrees){
	this->degree=degree;
}
double student::getdegree_marks(){
	return degree_marks;
}
void student::setdegree_marks(double degree_marks){
	this->degree_marks=degree_marks;
}
string student::getcourse_name(){
	return course_name;
}
void student::setcourse_name(string course_name){
	this->course_name=course_name;
}
string student::getcenter_id(){
	return center_id;

}
void student::setcenter_id(string center_id){
	this->center_id=center_id;
}
double student::getpayment(){
	return payment;
}
void student::setpayment(double payment){
	this->payment=payment;
}
string student::getreported(){
	return reported;
}

void student::setreported(string reported){
	this->reported=reported;
}
string student::get_prn(){
	return prn;
}
void student::set_prn(string prn){
	this->prn=prn;
}
int student::getalloc_pref(){
	return alloc_pref;
}
void student::setalloc_pref(int alloc_pref){
	this->alloc_pref=alloc_pref;
}
vector<preferences>student::getpref(){
	return temp_pref;
}
void student::setpref(vector<preferences>& pref){
	this->temp_pref=temp_pref;
}
void student::accept(){
	cout<<"Enter details of students"<<endl;
	cout<<"enter form no:";
	cin>>this->id;
	cout<<"Enter name";
	cin>>this->name;
	cout<<"Rank A:";
	cin>>this->rank_a;
	cout<<"Rank B:";
	cin>>this->rank_b;
	cout<<"Rank C:";
	cin>>this->rank_c;
	cout<<"Enter degree:";
	cin>>this->degree;
	cout<<"Enter degree marks:";
	cin>>this->degree_marks;
	this->alloc_pref=0;
	this->course_name="NA";
	this->center_id="NA";
	this->payment=0;
	this->reported="0";
	this->prn="NA";

}
void student::display(){
	cout<<"form no:"<<id<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"rank A:"<<rank_a<<endl;
	cout<<"rank B:"<<rank_b<<endl;
	cout<<"rank C:"<<rank_c<<endl;
	cout<<"Dregree:"<<degree<<endl;
	cout<<"Degree marks:"<<degree_marks<<endl;
	cout<<"allocatedb Preferences:"<<alloc_pref<<endl;
	cout<<"course name:"<<course_name<<endl;
	cout<<"center id:"<<center_id<<endl;
	cout<<"payment:"<<payment<<endl;
	cout<<"reported status:"<<reported<<endl;
	cout<<"PRN:"<<prn<<endl;

	//cout<<"\n------------------------------------------------------------------------\n";
	cout<<"\n"<<endl;
}
void student::display_pref()
{
	cout<<"form no:"<<id<<endl;
		cout<<"name:"<<name<<endl;
		cout<<"rank A:"<<rank_a<<endl;
		cout<<"rank B:"<<rank_b<<endl;
		cout<<"rank C:"<<rank_c<<endl;
		cout<<"Dregree:"<<degree<<endl;
		cout<<"Degree marks:"<<degree_marks<<endl;
		cout<<"allocatedb Preferences:"<<alloc_pref<<endl;
		cout<<"course name:"<<course_name<<endl;
		cout<<"center id:"<<center_id<<endl;
		cout<<"payment:"<<payment<<endl;
		cout<<"reported status:"<<reported<<endl;
		cout<<"PRN:"<<prn<<endl;
	for(unsigned int i=0;i<temp_pref.size();i++){
		cout<<" -";
		temp_pref[i].display();
	}
}
