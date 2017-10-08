/*CS 303 Assignment 3 C++ HashTables
 Aparna Nagaraj
 April 5th 2017
 */
//hashmain
#include "Hash.hpp"
#include "HashLin.hpp"
#include "HashQuad.hpp"
#include "HashDouble.hpp"
#include <iostream>
#include <vector>
#include <string>


using namespace std;
/* Description:*/

int main(){

	int i = 0; //number of element in table must be less than 10
	//int array[11] = {};
	int htbl[11] = {};
	
	string numbers;

	HashLin linear;
	HashQuad quad;
	HashDouble dble;
	
	Hash * hashLinear = &linear;
	Hash * hashQuad = &quad;
	Hash * hashDouble = &dble;

	cout << "Hash Tables"<<"\n";
	cout<< "Please enter non-negative integers, followed by -1: " << "\n";
	
	//cin>>numbers;

	//cin>>htbl[0];

	while(std::cin >> htbl[i]){
		if(htbl[i] == -1){break;}
		i++; 
	}  //add integers to this array

	cout<<"Inputs: " << "\n"; 
	for (int z = 0; z<i; z++){
			cout<<">"<<htbl[z]<<"\n";
		}
		
	cout<<"\n";	
	cout<<"\n";
	cout<<"Hash Table with Linear Probing"<< "\n";
	cout<<"\n";

	for (int z = 0; z<=i; z++){
		hashLinear ->insert(htbl[z]);
	}
	
	hashLinear ->print(11);
	
	cout<<"\n";
	cout<<"\n";
	cout<<"Hash Table with Quadratic Probing"<< "\n";
	cout<<"\n";
	
	for (int z = 0; z<=i; z++){
		hashQuad ->insert(htbl[z]);
	}
	
	hashQuad ->print(11);
	
	cout<<"\n";
	cout<<"\n";
	cout<<"Hash Table with Double Hashing"<<"\n";
	cout<<"\n";
	
	for (int z = 0; z<=i; z++){
		hashDouble ->insert(htbl[z]);
	}
	
	hashDouble ->print(11);
	
	cout<<"\n";
	cout<<"\n";
}