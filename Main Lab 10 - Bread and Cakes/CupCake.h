#pragma once
#include "Cake.h"

class CupCake: public Cake
{
public:
	CupCake();
	~CupCake();

	string ToString();
	string sprinkleColor;
	double GetDiscountedPrice(int quantity);
};

