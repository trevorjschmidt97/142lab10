#pragma once
#include "BakedGood.h"


class Bread : public BakedGood
{
public:
	Bread();
	~Bread();

	string ToString();
	string breadVariety;

	double GetDiscountedPrice(int quantity);
};

