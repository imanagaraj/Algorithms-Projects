/*CS 303 Assignment 3 C++ HashTables
 Aparna Nagaraj
 April 5th 2017
 */
//HashQuad.cpp
#include <iostream>
#include <vector>
#include "Hash.hpp"
#include "HashDouble.hpp"

using namespace std;
/* Description:*/


void HashDouble::insert(int num){

	int index = num % 11;
	//cout<<"index " <<index<< "\n";
	int step = 7 - (num % 7);
	//cout<<"step " <<index<< "\n";

	//int linIndex = collision + 1; //linear probing index

	while(hashtable[index] != -1){
		//cout<<"step " <<index<< "\n";
		index += step;
		
		if(index >= 11){
			index -= 11;
		}
	}
 		
	if(hashtable[index] == -1){  // try the new index insert if open
		hashtable[index] = num;
	}

	else{
		cout << num << " could not be inserted into the table";
	}
}
