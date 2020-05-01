/*
 * preferences.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef PREFERENCES_H_
#define PREFERENCES_H_
#include <string>
using namespace std;
class preferences
{
	int id;
	int preference;
	string course_name,center_id;
public:
	preferences();
	preferences(int id,int preference,string course_name,string center_id);
	int getid();
	void setid(int id);
	int get_preferences();
	void set_preferences(int preference);
	string getcourse_name();
	void setcourse_name(string course_name);
	string getcenter_id();
	void setcenter_id(string center_id);
	void accept();
	void display();
	virtual ~preferences();


};

#endif /* PREFERENCES_H_ */
