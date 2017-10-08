/*CS 303 Assignment 3 C++ HashTables
 Aparna Nagaraj
 April 5th 2017
 */
//HashQuad.cpp
#include <iostream>
#include <vector>
#include "Hash.hpp"
#include "HashQuad.hpp"

using namespace std;
/* Description:*/

void HashQuad::insert(int num){
	
	bool isPrime = true; //table size is 11 so table sixe is prime
	int collisionNum = 0;
	int count = 0;
	int index = num % 11;

	while(hashtable[index] != -1 && count<6){ //collision
		
		index += 2 * ++collisionNum -1; //probing
		count++;
		if(index >= 11){index -= 11;}\


	}

	if (count>=6){
		cout << num << " could not be inserted into the table"<< "\n";
		cout<< "\n";
	}

	if(hashtable[index] == -1){  // try the new index insert if open
		hashtable[index] = num;
	}

	// else {
	// 	cout << num << " could not be inserted into the table"<< "\n";
	// }
}


//HOW TO STOP IF CANNOT BE INSERTED???
