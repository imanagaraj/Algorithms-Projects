//Hash.cpp
/*CS 303 Assignment 3 C++ HashTables
 Aparna Nagaraj
 April 5th 2017
 */
#include <iostream>
#include <vector>
#include <string>
#include "Hash.hpp"
using namespace std;

/* Description:*/

void Hash::init(int size){
	
	for(int i=0; i<= size; ++i){
		hashtable[i] = -1;
	}

	//cout<<"constructed"<<"\n"; 
}

Hash::Hash(){
	hashtable.resize(11);
	init(11);
}

void Hash::print(int size){
	for(int i=0; i< size; ++i){
		if(hashtable[i] == -1 || hashtable[i] == 0){

			cout<<i<<" "<< "\n";
		}

		else{cout<<i<<" "<< hashtable[i]<< "\n";}
	}
}


/*
void Hash::insert(int num, vector<int> hashtable){
	
	int index = num % 11; //find the index
	if(hashtable[index] == -1){
		hashtable[index] = num;
	}
	 //else collision - do nothing in this function

}
*/