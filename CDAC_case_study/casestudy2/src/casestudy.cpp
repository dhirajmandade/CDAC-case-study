#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
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
using namespace std;
//vector<centers>cent=load_centers();
//vector<courses>course=load_courses();
int main(){
	unsigned int i;
	vector<student>students=load_students();


	/*for(i=0;i<students.size();i++)
		students[i].display();
*/

	//save_students(students);
	/*vector<preferences>pref=load_preferences(students);
	for(i=0;i<students.size();i++){
			students[i].display();
			students[i].display_pref();
	}*/



	/*for(i=0;i<cap.size();i++)
				cap[i].display();*/

	vector<centers>cent=load_centers();
	/*for(i=0;i<cent.size();i++)
		cent[i].display();*/
	vector<courses>course=load_courses();
		/*for(i=0;i<course.size();i++)
					course[i].display();*/


	vector<Eligibilities>eligibility=load_eligibilities(course);
	/*for(i=0;i<course.size();i++){
			course[i].display();
			course[i].display_eligibility();
	}*/

	vector<capacities>cap=load_capacities(course,cent);
	for(i=0;i<course.size();i++){
				course[i].display();
				course[i].display_course_capacities(cap);

		}

	for(i=0;i<cent.size();i++){
			cent[i].display();
			//cent[i].display_centers_capacities(cap);
	}
	return 0;
}
