#include "Bread.h"

Bread::Bread() {
	price = 4.50;
}

Bread::~Bread() {
}

string Bread::ToString() {
	stringstream ss;
	
	ss << breadVariety << " bread" << BakedGood::ToString();
	string s = ss.str();

	return s;
}

double Bread::GetDiscountedPrice(int quantity) {
	return price * (quantity - quantity / 3);
}