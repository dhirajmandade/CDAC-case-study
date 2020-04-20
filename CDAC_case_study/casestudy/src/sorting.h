/*
 * sorting.h
 *
 *  Created on: 20-Apr-2020
 *      Author: sunbeam
 */

#ifndef SORTING_H_
#define SORTING_H_
#include <iostream>
using namespace std;
#include <string>

bool sort_rankA(student s1, student s2)
{
	return s1.getrankA() < s2.getrankA() ? true:false;

}

bool sort_rankB(student s1, student s2)
{
	return s1.getrankB() < s2.getrankB() ? true:false;

}

bool sort_rankC(student s1, student s2)
{
	return s1.getrankC() < s2.getrankC() ? true:false;

}


#endif /* SORTING_H_ */
