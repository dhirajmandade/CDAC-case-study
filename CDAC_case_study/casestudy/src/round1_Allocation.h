/*
 * round1_Allocation.h
 *
 *  Created on: 21-Apr-2020
 *      Author: sunbeam
 */

#ifndef ROUND1_ALLOCATION_H_
#define ROUND1_ALLOCATION_H_
void first_round_allocation(){

	vector<student>::iterator st;
	vector<courses>::iterator  co;;
	vector<capacities>::iterator cp;
	vector<preferences>::iterator pf;

	int pref_no=1;
	int count=0;
	while(pref_no<11){
		sort(students.begin(),students.end(),sort_rankA);
		st=students.begin();
		while(st!=students.end()){
			if(st->getrankA()!=-1){
				if(st->getalloc_pref()=="NA"){
					pf=pref.begin();
					while(pf!=pref.end()){
						if(pf->get_preferences()==to_string(pref_no) && pf->getid()==st->getid()){
							co=course.begin();
							while(co!=course.end()){
								if(co->getsection()=="A" && pf->getcourse_name()==co->getcourse_name()){
									cp=cap.begin();
									while(cp!=cap.end()){
										if(pf->getcenter_id()==cp->getcenter_id() && pf->getcourse_name()==cp->getcourse_name() && cp->getfilled_capacity()!=cp->getcapacity()){
											count++;
											st->setalloc_pref(pf->get_preferences());
											st->setcourse_name(pf->getcourse_name());
											st->setcenter_id(cp->getcenter_id());
											cp->setfilled_capacity(to_string(1+stoi(cp->getfilled_capacity())));

										}
										cp++;
									}
								}
								co++;
							}
						}
						pf++;
					}
				}
			}
			st++;
		}


		sort(students.begin(),students.end(),sort_rankB);
		st=students.begin();
		while(st!=students.end()){
			if(st->getrankB()!=-1){
				if(st->getalloc_pref()=="NA"){
					pf=pref.begin();
					while(pf!=pref.end()){
						if(pf->get_preferences()==to_string(pref_no) && pf->getid()==st->getid()){
							co=course.begin();
							while(co!=course.end()){
								if(co->getsection()=="B" && pf->getcourse_name()==co->getcourse_name()){
									cp=cap.begin();
									while(cp!=cap.end()){
										if(pf->getcenter_id()==cp->getcenter_id() && pf->getcourse_name()==cp->getcourse_name() && cp->getfilled_capacity()!=cp->getcapacity()){
											count++;
											st->setalloc_pref(pf->get_preferences());
											st->setcourse_name(pf->getcourse_name());
											st->setcenter_id(cp->getcenter_id());
											cp->setfilled_capacity(to_string(1+stoi(cp->getfilled_capacity())));

										}
										cp++;
									}
								}
								co++;
							}
						}
						pf++;
					}
				}
			}
			st++;
		}


		sort(students.begin(),students.end(),sort_rankC);
		st=students.begin();
		while(st!=students.end()){
			if(st->getrankC()!=-1){
				if(st->getalloc_pref()=="NA"){
					pf=pref.begin();
					while(pf!=pref.end()){
						if(pf->get_preferences()==to_string(pref_no) && pf->getid()==st->getid()){
							co=course.begin();
							while(co!=course.end()){
								if(co->getsection()=="C" && pf->getcourse_name()==co->getcourse_name()){
									cp=cap.begin();
									while(cp!=cap.end()){
										if(pf->getcenter_id()==cp->getcenter_id() && pf->getcourse_name()==cp->getcourse_name() && cp->getfilled_capacity()!=cp->getcapacity()){
											count++;
											st->setalloc_pref(pf->get_preferences());
											st->setcourse_name(pf->getcourse_name());
											st->setcenter_id(cp->getcenter_id());
											cp->setfilled_capacity(to_string(1+stoi(cp->getfilled_capacity())));

										}
										cp++;
									}
								}
								co++;
							}
						}
						pf++;
					}
				}
			}
			st++;
		}
		pref_no++;
	}
}






#endif /* ROUND1_ALLOCATION_H_ */
