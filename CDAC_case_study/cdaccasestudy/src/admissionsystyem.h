/*
 * admissionsystyem.h
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */

#ifndef ADMISSIONSYSTYEM_H_
#define ADMISSIONSYSTYEM_H_


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


#include "student.h"
#include "preferences.h"
#include "capacities.h"
#include "Eligibilities.h"
#include "courses.h"
#include "centers.h"

class AdmissionSystem{
public:
	vector<student>students;
	vector<preferences>pref;
	vector<centers>cent;
	vector<courses>course;
	vector<capacities>cap;
	vector<Eligibilities>eligibility;
	vector<string>degree;

public:
	AdmissionSystem();

	void load_students();
	void load_preferences();
	void load_capacities();
	void load_centers();
	void load_courses();
	void load_eligibilities();
	void load_degree();



	void load_pref_with_stu();
	void load_eli_with_co();
	void load_cap_with_cent_and_co();

	courses* find_course(string course_name);
	centers* find_centers(string center_id);
	student* find_students(int id);
	void find_eligibility(string degree,double min_marks);



	void display_students();
	void display_preferences();
	void display_courses();
	void display_centers();
	void display_eligibilities();
	void display_capacities();
	void display_degree();
	void display_studentswith_preference();
	void display_courseswith_eligibility();
	void display_courseswith_capacity();
	void display_centerswith_capacity();
	void display_centers_with_courses();

	void display_paid_students();
	void display_prn_generated_students();
	void display_students_with_prn(string co,string cen);

	static bool sort_rankA(student s1,student s2);
	static bool sort_rankB(student s1,student s2);
	static bool sort_rankC(student s1,student s2);
	static bool sort_preferences(preferences p1,preferences p2);
	static bool sort_BY_name(student s1,student s2);
	static bool sort_BY_course_name(student s1,student s2);
	static bool sort_BY_center_id(student s1,student s2);

	void round1_allocation();
	void round2_allocation();
	void save_students_csv();
	void save_preferences_csv();
	void save_capacity_csv();

	~AdmissionSystem();

};

extern AdmissionSystem systemobj;


#endif /* ADMISSIONSYSTYEM_H_ */
