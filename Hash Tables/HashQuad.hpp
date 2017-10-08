//HashQuad.hpp
#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP
#include "Hash.hpp"

class HashQuad : public Hash{
	bool isPrime;
	bool isFull;
public:
	void insert(int num);
};
#endif 