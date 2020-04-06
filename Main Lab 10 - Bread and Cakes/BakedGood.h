#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class BakedGood
{
public:
	BakedGood();
	~BakedGood();

	virtual string ToString();
	virtual double GetDiscountedPrice(int quantity) = 0;
	double price;
};

