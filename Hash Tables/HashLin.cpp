//HashLin.cpp
#include <iostream>
#include <vector>
#include "Hash.hpp"
#include "HashLin.hpp"

using namespace std;

void HashLin::insert(int num){
	
	int index = num % 11;
	//int linIndex = collision + 1; //linear probing index

	while(hashtable[index] != -1){
		index = (index + 1) % 11;
	}

	if(hashtable[index] == -1){  // try the new index insert if open
		hashtable[index] = num;
	}

	else{

		cout<< num << " could not be inserted into the table";
	}
}


