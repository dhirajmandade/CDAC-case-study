/*
 * student_menu.h
 *
 *  Created on: 23-Apr-2020
 *      Author: sunbeam
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef STUDENT_MENU_H_
#define STUDENT_MENU_H_

enum{exit1,List_courses_as_per_eligi,List_centers,Give_pref,See_allocated_center_course,Update_payment};

int student_menu_choice(){
	int choice;
	cout<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"1.List courses (as per eligibility)"<<endl;
	cout<<"2.List centers"<<endl;
	cout<<"3.Give preferences"<<endl;
	cout<<"4.See allocated center/course"<<endl;
	cout<<"5.Update payment details"<<endl;
	cout<<"Enter choice: ";
	cin>>choice;
	cout<<endl;
	return choice;
}

#endif /* STUDENT_MENU_H_ */
