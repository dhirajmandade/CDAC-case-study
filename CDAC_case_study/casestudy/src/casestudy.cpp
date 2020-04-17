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


int main(){
	unsigned int i;
	vector<student>students=load_students();


	/*for(i=0;i<students.size();i++)
		students[i].display();
*/

	//save_students(students);
	vector<preferences>pref=load_preferences();
	/*for(i=0;i<pref.size();i++)
			pref[i].display();
	 */
	vector<capacities>cap=load_capacities();

	/*for(i=0;i<cap.size();i++)
				cap[i].display();*/

	vector<centers>cent=load_centers();
	/*for(i=0;i<cent.size();i++)
		cent[i].display();*/

	vector<Eligibilities>eligibility=load_eligibilities();
	/*for(i=0;i<eligibility.size();i++)
			eligibility[i].display();*/

	vector<courses>course=load_courses();
	for(i=0;i<course.size();i++)
				course[i].display();
	return 0;
}
