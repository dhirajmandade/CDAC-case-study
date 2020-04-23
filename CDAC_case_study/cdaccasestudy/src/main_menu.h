/*
 * main_menu.h
 *
 *  Created on: 23-Apr-2020
 *      Author: sunbeam
 */

#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include <iostream>
using namespace std;
#include "student_menu.h"
#include "admin_menu.h"
#include "coordinator_menu.h"

enum {EXIT,STUDENT,ADMIN,CENTER_CORDINATOR};

int main_menu_choice()
{
	int choice;
	cout<<"0.EXIT"<<endl;
	cout<<"1.STUDENT"<<endl;
	cout<<"2.ADMIN"<<endl;
	cout<<"3.CENTER COORDINATOR"<<endl;
	cout<<"Enter choice: ";
	cin>>choice;
	cout<<endl;
	return choice;
}



#endif /* MAIN_MENU_H_ */
