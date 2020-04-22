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


#include "admissionsystyem.h"
using namespace std;


int main(){

/*systemobj.load_eli_with_co();
systemobj.display_courseswith_eligibility();*/


/*systemobj.load_pref_with_stu();
systemobj.display_studentswith_preference();*/

	/*systemobj.load_courses();
	systemobj.display_courses();*/

/*systemobj.load_cap_with_cent_and_co();
systemobj.display_centerswith_capacity();
systemobj.display_courseswith_capacity();*/
	systemobj.load_pref_with_stu();
	systemobj.load_cap_with_cent_and_co();
systemobj.round2_allocation();
systemobj.display_studentswith_preference();
//systemobj.display_students();
	return 0;
}
