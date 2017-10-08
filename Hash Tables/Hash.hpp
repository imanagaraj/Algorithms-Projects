#ifndef HASH_HPP
#define HASH_HPP
#include <vector>

using namespace std;

class Hash {
public:
	vector<int> hashtable;
	void init(int size); // init method listing w/vector parameter
	void print(int size);
	virtual void insert(int num) = 0;
	//Hash(int size);
	Hash();
};

#endif 