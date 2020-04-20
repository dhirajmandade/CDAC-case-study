/*
 * round1_Allocation.h
 *
 *  Created on: 20-Apr-2020
 *      Author: sunbeam
 */

#ifndef ROUND1_ALLOCATION_H_
#define ROUND1_ALLOCATION_H_

void allocate_first_round(){


	vector<student>::iterator st=students.begin();
	vector<courses>::iterator  co=course.begin();
	//vector<centers>::iterator ct=cent.begin();
	vector<Eligibilities>::iterator el=eligibility.begin();
	vector<capacities>::iterator cp=cap.begin();
	vector<preferences>::iterator pf=pref.begin();

	int pref_no=1;
	int count=0;
	while(pref_no<11){


		sort(students.begin(),students.end(),sort_rankA);
		st=students.begin();
		while(st!=students.end()){
			if(st->getrankA()!=-1){
				if(st->getalloc_pref()=="0"){
					pf=pref.begin();
					while(pf!=pref.end()){
						if(pf->get_preferences()==to_string(pref_no)){
							if(pf->getid()==st->getid()){
								el=eligibility.begin();
								while(el!=eligibility.end()){
									if(el->getcourse_name()==pf->getcourse_name()){
										if(el->getdegree()==st->getdegree()){
											co=course.begin();
											while(co!=course.end()){
												if(co->getsection()=="A"){
													if(pf->getcourse_name()==co->getcourse_name()){
														cp=cap.begin();
														while(cp!=cap.end()){
															if(pf->getcourse_name()==cp->getcourse_name()){
																if(cp->getfilled_capacity()!=cp->getcapacity()){

																	count++;

																	st->setalloc_pref(pf->get_preferences());
																	st->setcourse_name(pf->getcourse_name());
																	st->setcenter_id(cp->getcenter_id());
																	cp->setcapacity(to_string(1+stoi(cp->getfilled_capacity())));

																}

															}
															cp++;
														}
													}
												}
												co++;
											}
										}

									}
									el++;
								}

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
			if(st->getrankA()!=-1){
				if(st->getalloc_pref()=="0"){
					pf=pref.begin();
					while(pf!=pref.end()){
						if(pf->get_preferences()==to_string(pref_no)){
							if(pf->getid()==st->getid()){
								el=eligibility.begin();
								while(el!=eligibility.end()){
									if(el->getcourse_name()==pf->getcourse_name()){
										if(el->getdegree()==st->getdegree()){
											co=course.begin();
											while(co!=course.end()){
												if(co->getsection()=="B"){
													if(pf->getcourse_name()==co->getcourse_name()){
														cp=cap.begin();
														while(cp!=cap.end()){
															if(pf->getcourse_name()==cp->getcourse_name()){
																if(cp->getfilled_capacity()!=cp->getcapacity()){

																	count++;

																	st->setalloc_pref(pf->get_preferences());
																	st->setcourse_name(pf->getcourse_name());
																	st->setcenter_id(cp->getcenter_id());
																	cp->setcapacity(to_string(1+stoi(cp->getfilled_capacity())));

																}

															}
															cp++;
														}
													}
												}
												co++;
											}
										}

									}
									el++;
								}

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
			if(st->getrankA()!=-1){
				if(st->getalloc_pref()=="0"){
					pf=pref.begin();
					while(pf!=pref.end()){
						if(pf->get_preferences()==to_string(pref_no)){
							if(pf->getid()==st->getid()){
								el=eligibility.begin();
								while(el!=eligibility.end()){
									if(el->getcourse_name()==pf->getcourse_name()){
										if(el->getdegree()==st->getdegree()){
											co=course.begin();
											while(co!=course.end()){
												if(co->getsection()=="C"){
													if(pf->getcourse_name()==co->getcourse_name()){
														cp=cap.begin();
														while(cp!=cap.end()){
															if(pf->getcourse_name()==cp->getcourse_name()){
																if(cp->getfilled_capacity()!=cp->getcapacity()){

																	count++;

																	st->setalloc_pref(pf->get_preferences());
																	st->setcourse_name(pf->getcourse_name());
																	st->setcenter_id(cp->getcenter_id());
																	cp->setcapacity(to_string(1+stoi(cp->getfilled_capacity())));

																}

															}
															cp++;
														}
													}
												}
												co++;
											}
										}

									}
									el++;
								}

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
