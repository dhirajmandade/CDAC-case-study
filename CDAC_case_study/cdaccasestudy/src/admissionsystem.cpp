/*
 * admissionsystem.cpp
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */

#include "admissionsystyem.h"
#include<vector>

#include <algorithm>
AdmissionSystem systemobj;
AdmissionSystem::AdmissionSystem(){

}

void AdmissionSystem::load_students(){

	ifstream fp;

	string line;
	int c=0;
	fp.open("../04_students_1st_install_paid.csv");
	if(!fp) {
		perror("failed to open file");
	}
	while(getline(fp,line)){

		stringstream str(line);
		string tokens[13];
		for(int i=0;i<13;i++)
			getline(str,tokens[i],',');
		student s(stoi(tokens[0]),tokens[1],stoi(tokens[2]),stoi(tokens[3]),stoi(tokens[4]),tokens[5],stod(tokens[6]),stoi(tokens[7]),tokens[8],tokens[9],stod(tokens[10]),tokens[11],tokens[12]);
		students.push_back(s);
		c++;
	}
	fp.close();
	cout << "students loaded: " << c << endl;

}

void AdmissionSystem::load_preferences(){
	int c=0;
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
		p.set_preferences(stoi(temp));

		getline(str,temp,',');
		p.setcourse_name(temp);

		getline(str,temp,',');
		p.setcenter_id(temp);
		pref.push_back(p);
		c++;
	}
	fin.close();

	cout << "Preferences loaded: " << c << endl;
}

void AdmissionSystem::load_capacities(){
	ifstream fp;
	int count=0;
	fp.open("../capacities.csv");
	string line;
	capacities c;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		c.setcenter_id(temp);

		getline(str,temp,',');
		c.setcourse_name(temp);

		getline(str,temp,',');
		c.setcapacity(stoi(temp));

		getline(str,temp,',');
		c.setfilled_capacity(stoi(temp));

		cap.push_back(c);
		count++;
	}
	fp.close();

	cout << "capacities loaded: " << count << endl;
}

void AdmissionSystem::load_centers(){
	ifstream fp;
	int count=0;
	fp.open("../centers.csv");
	string line;
	centers c;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		c.setcenter_id(temp);

		getline(str,temp,',');
		c.setcenter_name(temp);

		getline(str,temp,',');
		c.setaddress(temp);

		getline(str,temp,',');
		c.setcoordinator(temp);

		getline(str,temp,',');
		c.setpassword(temp);

		cent.push_back(c);
		count++;
	}
	fp.close();

	cout << "centers loaded: " << count << endl;
}


void AdmissionSystem::load_courses(){
	int c=0;
	ifstream fp;
	fp.open("../courses.csv");
	string line;
	courses c1;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		c1.setcourse_id(stoi(temp));

		getline(str,temp,',');
		c1.setcourse_name(temp);


		getline(str,temp,',');
		c1.setfees(temp);

		getline(str,temp,',');
		c1.setsection(temp);

		course.push_back(c1);
		c++;
	}

	fp.close();

	cout << "courses loaded: " << c << endl;
}
void AdmissionSystem::load_eligibilities(){
	int c=0;
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

		eligibility.push_back(e);
		c++;
	}
	fp.close();
	cout << "eligibilities loaded: " << c << endl;

}

student* AdmissionSystem::find_students(int id)
{
	unsigned i;
	for(i=0;i<students.size();i++){
		if(students[i].getid()==id)
			return &students[i];
	}
	return NULL;
}
courses*  AdmissionSystem::find_course(string course_name){
	unsigned i;
	for(i=0;i<course.size();i++)
	{
		if(course[i].getcourse_name()==course_name)
			return &course[i];
	}
	return NULL;
}
centers*  AdmissionSystem::find_centers(string center_id){
	unsigned i;
	for(i=0;i<cent.size();i++)
	{
		if(cent[i].getcenter_id()==center_id)
			return &cent[i];
	}
	return NULL;
}
void AdmissionSystem::load_pref_with_stu(){
	systemobj.load_students();

	int c=0;
	ifstream fin;
	preferences p;
	fin.open("../01_preferences.csv");
	string line;
	while(getline(fin,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		p.setid(stoi(temp));

		getline(str,temp,',');
		p.set_preferences(stoi(temp));

		getline(str,temp,',');
		p.setcourse_name(temp);

		getline(str,temp,',');
		p.setcenter_id(temp);


		student *s=find_students(p.getid());

		s->temp_pref.push_back(p);
		c++;
	}
	fin.close();

	cout << "Preferences loaded: " << c << endl;
}
void AdmissionSystem::load_eli_with_co(){
	systemobj.load_courses();
	ifstream fp;
	int count=0;
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

		courses *c=find_course(e.getcourse_name());

		c->temp_eligibility.push_back(e);
		count++;
	}
	fp.close();

	cout << "eligibilities loaded: " << count << endl;
}
void AdmissionSystem::load_cap_with_cent_and_co(){
	systemobj.load_courses();
	systemobj.load_centers();
	ifstream fp;
	int count=0;
	fp.open("../03_capacities.csv");
	string line;
	capacities c;
	while(getline(fp,line)){
		stringstream str(line);
		string temp;

		getline(str,temp,',');
		c.setcenter_id(temp);

		getline(str,temp,',');
		c.setcourse_name(temp);

		getline(str,temp,',');
		c.setcapacity(stoi(temp));

		getline(str,temp,',');
		c.setfilled_capacity(stoi(temp));

		cap.push_back(c);
		courses *cptr=find_course(c.getcourse_name());
		cptr->center_caps[c.getcenter_id()]=cap.size()-1;

		centers *cpptr=find_centers(c.getcenter_id());
		cpptr->course_caps[c.getcourse_name()]=cap.size()-1;
		count++;
	}
	fp.close();

	cout << "capacities loaded: " << count << endl;
}

void AdmissionSystem::display_students(){
	for(unsigned i=0;i<students.size();i++){
		students[i].display();
	}
}
void AdmissionSystem::display_preferences(){
	for(unsigned i=0;i<pref.size();i++){
		pref[i].display();
	}
}
void AdmissionSystem::display_courses(){
	for(unsigned i=0;i<course.size();i++){
		course[i].display();
	}
}
void AdmissionSystem::display_centers(){
	for(unsigned i=0;i<cent.size();i++){
		cent[i].display();
	}
}
void AdmissionSystem::display_eligibilities(){
	for(unsigned i=0;i<eligibility.size();i++){
		eligibility[i].display();
	}
}
void AdmissionSystem::display_capacities(){
	for(unsigned i=0;i<cap.size();i++){
		cap[i].display();
	}
}
void AdmissionSystem::display_studentswith_preference(){
	for(unsigned i=0;i<students.size();i++){
		//students[i].display();
		students[i].display_pref();
	}
}
void AdmissionSystem::display_courseswith_eligibility(){
	for(unsigned i=0;i<course.size();i++){
		course[i].display();
		course[i].display_eligibility();
	}
}
void AdmissionSystem::display_courseswith_capacity(){
	for(unsigned i=0;i<course.size();i++){
		course[i].display();
		course[i].display_capacities(cap);
	}
}
void AdmissionSystem::display_centerswith_capacity(){
	for(unsigned i=0;i<cent.size();i++){
		cent[i].display();
		cent[i].display_capacities(cap);
	}
}
bool AdmissionSystem::sort_rankA(student s1,student s2){
	return s1.getrankA()<s2.getrankA();
}
bool AdmissionSystem::sort_rankB(student s1,student s2){
	return s1.getrankB()<s2.getrankB();
}
bool AdmissionSystem::sort_rankC(student s1,student s2){
	return s1.getrankC()<s2.getrankC();
}

void AdmissionSystem::round1_allocation(){
	//systemobj.load_students();
	unsigned i,j;
	unsigned count=0;
	for(i=0;i<10;i++){

		sort(students.begin(),students.end(),sort_rankA);

		for(j=0;j<students.size();j++){

			if(students[j].temp_pref.size()>i){

				if(students[j].getrankA()!=-1 && students[j].getalloc_pref()==0 && students[j].getpayment()>=0){
					courses *c=find_course(students[j].temp_pref[i].getcourse_name());
					if(c->getsection()=="A"){
						centers *c1=find_centers(students[j].temp_pref[i].getcenter_id());
						int index=c1->course_caps[students[j].temp_pref[i].getcourse_name()];
						if(cap[index].getcapacity()!=cap[index].getfilled_capacity()){
							count++;
							int filled=cap[index].getfilled_capacity();
							int preference=students[j].temp_pref[i].get_preferences();
							string id=students[j].temp_pref[i].getcenter_id();
							string cname=students[j].temp_pref[i].getcourse_name();

							students[j].setalloc_pref(preference);
							students[j].setcenter_id(id);
							students[j].setcourse_name(cname);
							cap[index].setfilled_capacity(filled+1);


						}
					}
				}
			}
		}
		sort(students.begin(),students.end(),sort_rankB);
		for(j=0;j<students.size();j++){
			if(students[j].temp_pref.size()>i){
				if(students[j].getrankB()!=-1 && students[j].getalloc_pref()==0 && students[j].getpayment()>=0){
					courses *c=find_course(students[j].temp_pref[i].getcourse_name());
					if(c->getsection()=="B"){
						centers *c1=find_centers(students[j].temp_pref[i].getcenter_id());
						int index=c1->course_caps[students[j].temp_pref[i].getcourse_name()];
						if(cap[index].getcapacity()!=cap[index].getfilled_capacity()){
							count++;
							int filled=cap[index].getfilled_capacity();
							int preference=students[j].temp_pref[i].get_preferences();
							string id=students[j].temp_pref[i].getcenter_id();
							string cname=students[j].temp_pref[i].getcourse_name();

							students[j].setalloc_pref(preference);
							students[j].setcenter_id(id);
							students[j].setcourse_name(cname);
							cap[index].setfilled_capacity(filled+1);


						}
					}
				}
			}
		}

		sort(students.begin(),students.end(),sort_rankC);
		for(j=0;j<students.size();j++){
			if(students[j].temp_pref.size()>i){
				if(students[j].getrankC()!=-1 && students[j].getalloc_pref()==0 && students[j].getpayment()>=0){
					courses *c=find_course(students[j].temp_pref[i].getcourse_name());
					if(c->getsection()=="C"){
						centers *c1=find_centers(students[j].temp_pref[i].getcenter_id());
						int index=c1->course_caps[students[j].temp_pref[i].getcourse_name()];
						if(cap[index].getcapacity()!=cap[index].getfilled_capacity()){
							count++;
							int filled=cap[index].getfilled_capacity();
							int preference=students[j].temp_pref[i].get_preferences();
							string id=students[j].temp_pref[i].getcenter_id();
							string cname=students[j].temp_pref[i].getcourse_name();

							students[j].setalloc_pref(preference);
							students[j].setcenter_id(id);
							students[j].setcourse_name(cname);
							cap[index].setfilled_capacity(filled+1);


						}
					}
				}
			}
		}
	}
	cout<<count<<endl;
}

void AdmissionSystem::round2_allocation(){
	unsigned i;
	for(i=0;i<students.size();i++){
		if(students[i].getalloc_pref()>0 && students[i].getpayment()==0){
			students[i].setpayment(-1);

			students[i].setalloc_pref(0);
			students[i].setcenter_id("NA");
			students[i].setcourse_name("NA");
		}
	}
	for(i=0;i<cap.size();i++){
		cap[i].setfilled_capacity(0);
	}
	round1_allocation();
}





AdmissionSystem::~AdmissionSystem(){

}
