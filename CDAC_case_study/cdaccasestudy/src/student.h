/*
 * student.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <vector>
#include "preferences.h"
using namespace std;
class student {
private:
	int id;
	string name;
	int rank_a,rank_b,rank_c;
	string degree;
	double degree_marks;
	string course_name;
	string center_id;
	double payment;
	string reported,prn;
	int alloc_pref;
public:
	vector<preferences>temp_pref;


public:
	student();
	student(int id,string name,int rank_a,int rank_b,int rank_c,string degree,double degree_marks,int alloc_pref,string course_name,string center_id,double payment,string reported,string prn);
	virtual ~student();
	int getid();
	void setid(int id);
	string getname();
	void setname(string name);
	int getrankA();
	void setrankA(int rank_a);
	int getrankB();
	void setrankB(int rank_b);
	int getrankC();
	void setrankC(int rank_c);
	string getdegree();
	void setdegree(string degrees);
	double getdegree_marks();
	void setdegree_marks(double degree_marks);
	string getcourse_name();
	void setcourse_name(string course_name);
	string getcenter_id();
	void setcenter_id(string center_id);
	double getpayment();
	void setpayment(double payment);
	string getreported();
	void setreported(string reported);
	string get_prn();
	void set_prn(string prn);
	int getalloc_pref();
	void setalloc_pref(int alloc_pref);
	vector<preferences>getpref();
	void setpref(vector<preferences>& pref);
	void accept();
	void display();
	void display_pref();


};

#endif /* STUDENT_H_ */
