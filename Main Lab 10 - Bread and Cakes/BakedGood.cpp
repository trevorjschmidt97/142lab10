#include "BakedGood.h"

BakedGood::BakedGood() {
}

BakedGood::~BakedGood() {
}

string BakedGood::ToString() {
	stringstream out;

	out << " ($" << fixed << setprecision(2) << price << ")";
	return out.str();
};

