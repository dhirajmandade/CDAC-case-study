/*
 * round1_csv.h
 *
 *  Created on: 21-Apr-2020
 *      Author: sunbeam
 */

#ifndef ROUND1_CSV_H_
#define ROUND1_CSV_H_


void round1_csv(){
	ofstream fp("students_after_round_1.csv");
	for(size_t i=0;i<students.size();i++){
		fp<<students[i].getid()<<",";
		fp<<students[i].getname()<<",";
		fp<<students[i].getrankA()<<",";
		fp<<students[i].getrankB()<<",";
		fp<<students[i].getrankC()<<",";
		fp<<students[i].getdegree()<<",";
		fp<<students[i].getdegree_marks()<<",";
		fp<<students[i].getalloc_pref()<<",";
		fp<<students[i].getcourse_name()<<",";
		fp<<students[i].getcenter_id()<<",";
		fp<<students[i].getpayment()<<",";
		fp<<students[i].getreported()<<",";
		fp<<students[i].get_prn()<<endl;
	}
	fp.close();
}

void capacity_after_round1()
{
	ofstream fp("capacity_after_round1.csv");
	for(size_t i=0;i<cap.size();i++){
		fp<<cap[i].getcenter_id()<<",";
		fp<<cap[i].getcourse_name()<<",";
		fp<<cap[i].getcapacity()<<",";
		fp<<cap[i].getfilled_capacity()<<endl;

	}
	fp.close();
}

#endif /* ROUND1_CSV_H_ */
