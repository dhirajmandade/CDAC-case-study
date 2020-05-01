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
	//systemobj.load_students();
	systemobj.load_courses();
	systemobj.load_centers();
	//systemobj.load_capacities();
	systemobj.load_degree();
	//systemobj.load_eligibilities();
	systemobj.load_eli_with_co();
	systemobj.load_pref_with_stu();
	systemobj.load_cap_with_cent_and_co();






	int choice;
	while((choice=main_menu_choice())!=EXIT){
		switch(choice){
		case STUDENT:
		{
			systemobj.load_eligibilities();
			systemobj.load_capacities();
			cout<<"New User or Existing User(N/E): ";
			char ch;
			cin>>ch;
			if(ch=='N' || ch=='n'){
				cout<<"\nEnter following details:"<<endl;
				int size,degree;

				systemobj.load_degree();
				size=systemobj.students.size();

				string name;
				double degree_marks;

				cout<<"Enter your name: ";
				cin>>name;
				systemobj.display_degree();
				cout<<"choose your degree option: "<<endl;
				cin>>degree;
				cout<<"Enter degree percentage: ";
				cin>>degree_marks;
				student obj((size+1),name,-1,-1,-1,systemobj.degree[degree-1],degree_marks,0,"NA","NA",0,"0","NA");
				systemobj.students.push_back(obj);
				systemobj.save_students_csv();
				systemobj.display_students();

			}
			else{
				cout<<"---Log In as student---"<<endl;
				int form_no;
				string name;
				cout<<"\nEnter Form Number: ";
				cin>>form_no;
				cout<<"\nEnter Name: ";
				cin>>name;
				for(unsigned i=0;i<systemobj.students.size();i++){
					if((systemobj.students[i].getid()==form_no) && (systemobj.students[i].getname()==name)){
						while((choice=student_menu_choice())!=exit1){
							switch(choice){
							case List_courses_as_per_eligi:
							{

								student *s=systemobj.find_students(systemobj.students[i].getid());
								systemobj.find_eligibility(s->getdegree(),s->getdegree_marks());

							}
							break;
							case List_centers:
							{

								systemobj.display_centers();
							}
							break;
							case Give_pref:
							{
								cout<<"\nAll courses:"<<endl;
								systemobj.display_centers_with_courses();
								cout<<"\nyou are eligible for following courses:"<<endl;
								student *s=systemobj.find_students(systemobj.students[i].getid());
								systemobj.find_eligibility(s->getdegree(),s->getdegree_marks());

								int n;
								cout<<"Enter number of preferences you want to enter: ";
								cin>>n;
								cout<<"\nEnter your preferences :"<<endl;
								for(unsigned i=0;i<n;i++){

									string course_name,center_id;

									cout<<"\nEnter course name: ";
									cin>>course_name;
									cout<<"\nEnter Center id: ";
									cin>>center_id;
									preferences p(s->getid(),i+1,course_name,center_id);
									s->temp_pref.push_back(p);
									systemobj.pref.push_back(p);
									systemobj.save_preferences_csv();
								}
								cout<<"\nPreferences added Successfully"<<endl;
								sort(systemobj.pref.begin(),systemobj.pref.end(),systemobj.sort_preferences);
								systemobj.display_preferences();

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
								double paid,payment;
								student *s=systemobj.find_students(systemobj.students[i].getid());
								paid=s->getpayment();
								cout<<"paid fees:\t"<<paid<<endl;
								if(paid==0){
									cout<<"\nPay your first installment of Rs.11800"<<endl;
									cout<<"Enter amount: ";
									cin>>payment;
									s->setpayment(11800);
									systemobj.save_students_csv();
								}
								if(paid==11800){
									cout<<"\nPay your second installment:"<<endl;
									cout<<"Enter amount: ";
									cin>>payment;
									s->setpayment(payment+paid);
									systemobj.save_students_csv();
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
		case ADMIN:
		{
			cout<<"---Log In as Admin---"<<endl;
			string username,password;
			cout<<"\nEnter Username: ";
			cin>>username;
			cout<<"\nEnter Password: ";
			cin>>password;
			if(username=="admin" && password=="admin"){
				cout<<endl;
				while((choice=admin_menu_choice())!=Exit){
					switch(choice)
					{
					case List_courses_and_elig:
					{
						cout<<"\n---List of courses along with eligibility---\n"<<endl;
						systemobj.display_courseswith_eligibility();
					}
					break;
					case List_cent_and_cap:
					{
						cout<<"\n---List of centers along with capacity---\n"<<endl;
						systemobj.display_centerswith_capacity();
					}
					break;
					case List_students:
					{

						systemobj.display_students();
					}
					break;
					case Update_ranks:
					{
						cout<<"Enter details of student:"<<endl;
						int form_no,rankA,rankB,rankC;
						cout<<"Enter Form Number: ";
						cin>>form_no;
						student *s=systemobj.find_students(form_no);
						cout<<"\nEnter Rank A: ";
						cin>>rankA;
						cout<<"\nEnter Rank B: ";
						cin>>rankB;
						cout<<"\nEnter Rank C: ";
						cin>>rankC;
						s->setrankA(rankA);
						s->setrankB(rankB);
						s->setrankC(rankC);
						systemobj.save_students_csv();
						cout<<"\nRanks updated successfully"<<endl;

					}
					break;
					case Allocate_round1:

					{
						systemobj.round1_allocation();
						systemobj.display_studentswith_preference();
					}
					break;
					case Allocate_round2:
					{

						systemobj.round2_allocation();
						systemobj.display_students();
					}
					break;
					case List_allocated_students:

						cout<<"1.sort by course name"<<endl<<"2.sort by center id"<<endl<<"3.sort by name"<<endl;
						int n;
						cout<<"Enter choice: ";
						cin>>n;
						if (n==1){
							sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_course_name);
							for(unsigned i=0;i<systemobj.students.size();i++)
							{
								if(systemobj.students[i].getalloc_pref()>0)
								{
									systemobj.students[i].display();
								}
							}
						}
						if(n==2){
							sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_center_id);
							for(unsigned i=0;i<systemobj.students.size();i++)
							{
								if(systemobj.students[i].getalloc_pref()>0)
								{
									systemobj.students[i].display();
								}
							}
						}
						else
							sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_name);
						for(unsigned i=0;i<systemobj.students.size();i++)
						{
							if(systemobj.students[i].getalloc_pref()>0)
							{
								systemobj.students[i].display();
							}
						}
						break;
					case List_paid_students:

						sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_course_name);
						sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_center_id);
						sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_name);
						cout<<endl;
						systemobj.display_paid_students();
						break;
					case List_reported_students:
					{
						cout<<endl;
						for(unsigned i=0;i<systemobj.students.size();i++){
							if(systemobj.students[i].getreported()!="0"){
								systemobj.students[i].display();
							}
						}
					}
					break;
					case Generate_PRN:
					{
						sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_course_name);
						sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_center_id);
						sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_name);
						cout<<endl;
						systemobj.display_prn_generated_students();
					}

					break;
					case List_students_with_prn:
					{

						for(unsigned i=0;i<systemobj.students.size();i++){
							if(systemobj.students[i].get_prn()!="NA")
								systemobj.students[i].display();
						}
					}
					break;


					}
				}
			}

		}
		break;

		case CENTER_CORDINATOR:
		{

			cout<<"\n---Log In Center cordinator---\n"<<endl;
			string Id,password;
			cout<<"\nEnter username: ";
			cin>>Id;
			cout<<"\nEnter password: ";
			cin>>password;
			for(unsigned h=0;h<systemobj.cent.size();h++){
				if((systemobj.cent[h].getcenter_id()==Id) && (systemobj.cent[h].getpassword()==password)){

					while((choice=coordinator_menu_choice())!=Exit2)
					{
						switch(choice)
						{
						case List_courses:
							cout<<"\n---List of courses at this center---\n"<<endl;
							for(unsigned j=0;j<systemobj.cap.size();j++){
								if(systemobj.cent[h].getcenter_id()==systemobj.cap[j].getcenter_id()){
									cout<<"-"<<systemobj.cap[j].getcourse_name()<<endl;
								}
							}
							break;
						case List_stud:
						{
							string name;
							cout<<"\nEnter course name: ";
							cin>>name;
							sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_name);
							for(unsigned i=0;i<systemobj.students.size();i++){
								if(systemobj.students[i].getcenter_id()==systemobj.cent[h].getcenter_id()){
									systemobj.students[i].display();
								}
							}
						}
						break;
						case Update_reported_status:
						{

							cout<<"\nEnter form number: ";
							int no;
							cin>>no;
							for(unsigned a=0;a<systemobj.students.size();a++){
								if(systemobj.students[a].getid()==no){
									if(systemobj.students[a].getcenter_id()==systemobj.cent[h].getcenter_id()){
										if(systemobj.students[a].getreported()=="0"){
											systemobj.students[a].setreported("Reported");

											systemobj.save_students_csv();
											systemobj.students[a].display();
										}
										else
											cout<<"\nStudent not allocated to this center"<<endl;
									}

								}
							}
						}
						break;
						case List_admitted_students:
						{
							cout<<"\nEnter course name: ";
							string cname;
							cin>>cname;
							for(unsigned b=0;b<systemobj.students.size();b++){
								if(systemobj.students[b].getcenter_id()==systemobj.cent[h].getcenter_id()){
									if(systemobj.students[b].getcourse_name()==cname && systemobj.students[b].get_prn()!="NA"){
										sort(systemobj.students.begin(),systemobj.students.end(),systemobj.sort_BY_name);
										systemobj.students[b].display();
									}
								}
							}
						}
						break;
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
