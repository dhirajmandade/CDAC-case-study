/*
 * admin_menu.h
 *
 *  Created on: 23-Apr-2020
 *      Author: sunbeam
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef ADMIN_MENU_H_
#define ADMIN_MENU_H_

enum{Exit,List_courses_and_elig,List_cent_and_cap,List_students,Update_ranks,Allocate_round1,Allocate_round2,
List_allocated_students,List_paid_students,List_reported_students,Generate_PRN,List_students_with_prn};


int admin_menu_choice()
{
	int choice;
	cout<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"1.List courses & eligibilities"<<endl;
	cout<<"2.List centers & capacities"<<endl;
	cout<<"3.List students"<<endl;
	cout<<"4.Update student ranks"<<endl;
	cout<<"5.Allocate centers (Round 1)"<<endl;
	cout<<"6.Allocate centers (Round 2)"<<endl;
	cout<<"7.List allocated students"<<endl;
	cout<<"8.List paid students"<<endl;
	cout<<"9.List reported (at center) students"<<endl;
	cout<<"10.Generate PRN"<<endl;
	cout<<"11.List admitted students (with PRN) for given center"<<endl;
	cout<<"\nEnter choice: ";
	cin>>choice;
	return choice;
}
#endif /* ADMIN_MENU_H_ */
