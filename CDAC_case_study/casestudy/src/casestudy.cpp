#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "student.h"
#include "preferences.h"
#include "capacities.h"
#include "Eligibilities.h"
#include "courses.h"

#include "load_capacity_obj.h"
#include "load_pref_obj.h"
#include "load_student_object.h"
#include "load_center_obj.h"
#include "load_eligibility_obj.h"
#include "load_course_obj.h"
#include "sorting.h"


using namespace std;
vector<student>students=load_students();
vector<preferences>pref=load_preferences(students);
vector<centers>cent=load_centers();
vector<courses>course=load_courses();
vector<capacities>cap=load_capacities(course,cent);
vector<Eligibilities>eligibility=load_eligibilities(course);
#include "round1_Allocation.h"
#include "round1_csv.h"
int main(){
	unsigned int i;

	//vector<student>students=load_students();
	/*for(i=0;i<students.size();i++)
		students[i].display();*/

/*
	vector<preferences>pref=load_preferences(students);
	for(i=0;i<students.size();i++){
			students[i].display();
			students[i].display_pref();
	}*/


	/*vector<capacities>cap=load_capacities();
	for(i=0;i<cap.size();i++)
				cap[i].display();*/

	//vector<centers>cent=load_centers();
	/*for(i=0;i<cent.size();i++)
		cent[i].display();*/


	//vector<courses>course=load_courses();
		/*for(i=0;i<course.size();i++)
					course[i].display();*/


	/*vector<Eligibilities>eligibility=load_eligibilities(course);
	for(i=0;i<course.size();i++){
			course[i].display();
			course[i].display_eligibility();
	}*/

	/*vector<centers>cent=load_centers();
	vector<courses>course=load_courses();

	vector<capacities>cap=load_capacities(course,cent);
	for(i=0;i<course.size();i++){
				course[i].display();
				course[i].display_capacities(cap);
	}


	for(i=0;i<cent.size();i++){
			cent[i].display();
			cent[i].display_capacities(cap);
	}*/

	/*sort(students.begin(),students.end(),sort_rankA);

	sort(students.begin(),students.end(),sort_rankB);

	sort(students.begin(),students.end(),sort_rankC);
	*/
		/*for(i=0;i<students.size();i++)
			students[i].display();*/

	allocate_first_round();
	round1_csv();
	for(i=0;i<students.size();i++)
				students[i].display();

	return 0;
}
