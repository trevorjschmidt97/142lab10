#include "LayerCake.h"

LayerCake::LayerCake() {
	price = 9.00;
}

LayerCake::~LayerCake() {
}

string LayerCake::ToString() {
	stringstream ss;

	ss << numOfLayers << "-layer " << flavor << " cake with " << frosting << " frosting" << BakedGood::ToString();
	string s = ss.str();

	return s;
}

double LayerCake::GetDiscountedPrice(int quantity) {
	double totalPrice = price * quantity;
	if (quantity >= 3) {
		totalPrice = totalPrice - (quantity * 2.00);
	}

	return totalPrice;
}