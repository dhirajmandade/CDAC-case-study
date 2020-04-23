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
#include "main_menu.h"
#include "student_menu.h"
#include "admin_menu.h"
#include "coordinator_menu.h"
using namespace std;


int main(){
	//===============================================================//
							systemobj.load_eligibilities();
							systemobj.load_eli_with_co();
							systemobj.load_capacities();
							systemobj.load_courses();
							systemobj.load_pref_with_stu();
							systemobj.load_cap_with_cent_and_co();
	//================================================================//

	int choice;
	while((choice=main_menu_choice())!=EXIT){
		switch(choice){
		case STUDENT:
		{
			cout<<"New User or Existing User(N/E)";
			char ch;
			cin>>ch;
			if(ch=='N' || ch=='n'){
				student obj;
				//obj.setid(systemobj.students.size()+1);
				obj.accept();
				systemobj.students.push_back(obj);
			}
			else{
				cout<<"Log In as student"<<endl;
				int form_no;
				string name;
				cout<<"Enter Form Number: ";
				cin>>form_no;
				cout<<"\nEnter Name: ";
				cin>>name;
				for(unsigned i=0;i<systemobj.students.size();i++){
					if((systemobj.students[i].getid()==form_no) && (systemobj.students[i].getname()==name)){
						while((choice=student_menu_choice())!=exit1){
							switch(choice){
							case List_courses_as_per_eligi:
							{
								for(unsigned j=0;j<systemobj.eligibility.size();j++){
									if(systemobj.eligibility[j].getdegree()==systemobj.students[i].getdegree()){
										cout<<"-"<<systemobj.eligibility[j].getcourse_name()<<endl;
									}
								}
							}
							break;
							case List_centers:
							{
								for(unsigned k=0;k<systemobj.eligibility.size();k++){
									if(systemobj.eligibility[k].getdegree()==systemobj.students[i].getdegree()){
										for(unsigned l=0;l<systemobj.cap.size();l++){
											if(systemobj.cap[l].getcourse_name()==systemobj.eligibility[k].getcourse_name()){
												cout<<systemobj.eligibility[k].getcourse_name()<<"-"<<systemobj.cap[l].getcenter_id()<<endl;
											}
										}
									}
								}
								break;
							case Give_pref:
							{
								preferences p;
								for(unsigned m=0;m<systemobj.eligibility.size();m++){
									if(systemobj.eligibility[m].getdegree()==systemobj.students[i].getdegree()){
										for(unsigned n=0;n<systemobj.cap.size();n++){
											if(systemobj.cap[n].getcourse_name()==systemobj.eligibility[m].getcourse_name()){

												cout<<systemobj.eligibility[m].getcourse_name()<<"-"<<systemobj.cap[n].getcenter_id()<<endl;

											}
										}
									}

								}
								cout<<"\nYou are eligible for above courses at perticular centers"<<endl;
								p.accept();
								systemobj.pref.push_back(p);
							}
							break;
							case See_allocated_center_course:
							{
								cout<<"Allocated Course: "<<systemobj.students[i].getcourse_name()<<endl;
								cout<<"Allocated center: "<<systemobj.students[i].getcenter_id()<<endl;
							}
								break;
							case Update_payment:
							{
								if(systemobj.students[i].getcenter_id()!="NA"){
									cout<<"payment for 11800 is processed"<<endl;
									systemobj.students[i].setpayment(11800);
								}
							}
								break;
							}
							}
						}
					}


				}
			}
			break;


		}
		}


	}
	return 0;
}
