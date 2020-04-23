/*
 * coordinator_menu.h
 *
 *  Created on: 23-Apr-2020
 *      Author: sunbeam
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef COORDINATOR_MENU_H_
#define COORDINATOR_MENU_H_

enum{Exit2,List_courses,List_stud,Updated_reported_status,List_admitted_students};

int coordinator_menu_choice()
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.List courses (of that center)"<<endl;
	cout<<"2.List students (allocated to that center)"<<endl;
	cout<<"3.Update reported status"<<endl;
	cout<<"4.List admitted students (with PRN)"<<endl;
	cout<<"Enter choice: ";
	cin>>choice;
	cout<<endl;
	return choice;
}


#endif /* COORDINATOR_MENU_H_ */
