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
using namespace std;
AdmissionSystem::AdmissionSystem(){

}

void AdmissionSystem::load_students(){

	ifstream fp;

	string line;

	fp.open("../newstudents.csv");
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

	}
	fp.close();


}

void AdmissionSystem::load_preferences(){

	ifstream fin;
	preferences p;
	fin.open("../newpreferences.csv");
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

	}
	fin.close();


}

void AdmissionSystem::load_capacities(){
	ifstream fp;

	fp.open("../newcapacities.csv");
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

	}
	fp.close();


}

void AdmissionSystem::load_centers(){
	ifstream fp;

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

	}
	fp.close();


}


void AdmissionSystem::load_courses(){

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

	}

	fp.close();


}
void AdmissionSystem::load_eligibilities(){

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

	}
	fp.close();


}

void AdmissionSystem::load_degree(){

	ifstream fp("../degrees.txt");
	string line;
	while(getline(fp,line)){
		degree.push_back(line);

	}
	fp.close();


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
void AdmissionSystem::find_eligibility(string degree,double min_marks){
	unsigned i,j;
	cout<<"\n ---courses according to your eligibility---\n"<<endl;
	for(i=0;i<course.size();i++){
		for(j=0;j<course[i].temp_eligibility.size();j++){
			if(course[i].temp_eligibility[j].getdegree()== degree && course[i].temp_eligibility[j].getmin_marks() < min_marks)
				course[i].display();
		}
	}
}
void AdmissionSystem::load_pref_with_stu(){
	systemobj.load_students();


	ifstream fin;
	preferences p;
	fin.open("../newpreferences.csv");
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

	}
	fin.close();


}
void AdmissionSystem::load_eli_with_co(){
	//systemobj.load_courses();
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

	}
	fp.close();


}
void AdmissionSystem::load_cap_with_cent_and_co(){
	/*systemobj.load_courses();
	systemobj.load_centers();*/
	ifstream fp;

	fp.open("../newcapacities.csv");
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

	}
	fp.close();


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
	cout<<"\n---Centers---\n"<<endl;
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
void AdmissionSystem::display_degree(){
	for(unsigned i=0;i<degree.size();i++){
		cout<<i+1<<"."<<degree[i]<<endl;
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
		//course[i].display();
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
void AdmissionSystem::display_centers_with_courses(){
	cout<<endl;
	for(unsigned i=0;i<cent.size();i++){
		cent[i].display_center_and_course(cap);
		cout<<endl;
	}
}
void AdmissionSystem::display_paid_students(){
	for(unsigned i=0;i<students.size();i++){
		if(students[i].getalloc_pref()>0 && students[i].getpayment()>0)
			students[i].display();
	}
}
void AdmissionSystem::display_prn_generated_students(){
	int sr_no=1;
	double coursefees;
	string prn,s1,s2,s3;
	cout<<"\nList of reported students:"<<endl;

	for(unsigned x=0;x<systemobj.students.size();x++){
		if(systemobj.students[x].getreported()=="Reported")
		{
			courses *c=systemobj.find_course(systemobj.students[x].getcourse_name());
			coursefees=stod(c->getfees());
			if(systemobj.students[x].getpayment()==(coursefees)){
				s1=systemobj.students[x].getcourse_name();
				s2=systemobj.students[x].getcenter_id();
				s3=to_string(sr_no);
				prn=s1+"_"+s2+"_"+s3;
				systemobj.students[x].set_prn(prn);
				systemobj.save_students_csv();
				systemobj.students[x].display();
				sr_no++;

			}
		}
	}
}
void AdmissionSystem::display_students_with_prn(string co,string cen){
	cout<<"\nList of allocated students:"<<endl;
	for(unsigned i=0;i<students.size();i++){
		if(students[i].getcenter_id()==cen && students[i].getcourse_name()==co && students[i].get_prn()!="NA")
			students[i].display();
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
bool AdmissionSystem::sort_preferences(preferences p1,preferences p2){
	return p1.getid()<p2.getid();
}
bool AdmissionSystem::sort_BY_name(student s1,student s2){
	return s1.getname() < s2.getname();

}
bool AdmissionSystem::sort_BY_course_name(student s1,student s2){
	return s1.getcourse_name() < s2.getcourse_name();
}
bool AdmissionSystem::sort_BY_center_id(student s1,student s2){
	return s1.getcenter_id() < s2.getcenter_id();
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
		}
	}
	for(i=0;i<students.size();i++){
		students[i].setalloc_pref(0);
		students[i].setcenter_id("NA");
		students[i].setcourse_name("NA");
	}

	for(i=0;i<cap.size();i++){
		cap[i].setfilled_capacity(0);
	}
	round1_allocation();
}


void AdmissionSystem::save_students_csv(){
	//systemobj.load_students();
	ofstream fp("../newstudents.csv");
	for(unsigned i=0;i<students.size();i++){
		fp<<students[i].getid()<<","<<students[i].getname()<<","<<students[i].getrankA()<<","<<students[i].getrankB()<<","<<students[i].getrankC()
										<<","<<students[i].getdegree()<<","<<students[i].getdegree_marks()<<","<<students[i].getalloc_pref()<<","<<students[i].getcourse_name()
										<<","<<students[i].getcenter_id()<<","<<students[i].getpayment()<<","<<students[i].getreported()<<","<<students[i].get_prn()<<endl;

	}
	fp.close();
}
void  AdmissionSystem::save_preferences_csv(){
	ofstream fp("../newpreferences.csv");
	for(unsigned i=0;i<pref.size();i++){
		fp<<pref[i].getid()<<","<<pref[i].get_preferences()<<","<<pref[i].getcourse_name()<<","<<pref[i].getcenter_id()<<endl;

	}
	fp.close();
}

AdmissionSystem::~AdmissionSystem(){

}
