#pragma once
#include "BakedGood.h"

class Cake: public BakedGood
{
public:
	Cake();
	~Cake();

	virtual string ToString();
	virtual double GetDiscountedPrice(int quantity) = 0;
	string flavor;
	string frosting;
};

