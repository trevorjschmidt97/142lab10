#pragma once
#include "Cake.h"

class LayerCake: public Cake
{
public:
	LayerCake();
	~LayerCake();

	string ToString();
	int numOfLayers;
	double GetDiscountedPrice(int quantity);
};

