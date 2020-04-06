#include "CupCake.h"

CupCake::CupCake() {
	price = 1.95;
}

CupCake::~CupCake() {
}

string CupCake::ToString() {
	stringstream ss;

	ss << flavor << " cupcake with " << frosting << " frosting and " << sprinkleColor << " sprinkles" << BakedGood::ToString();
	string s = ss.str();
	return s;
}

double CupCake::GetDiscountedPrice(int quantity) {
	double totalPrice = price * quantity;

	if (quantity >= 4) {
		totalPrice = totalPrice - (quantity * .40);
	}
	else if (quantity >= 2) {
		totalPrice = totalPrice - (quantity * .30);
	}
	
	return totalPrice;
}