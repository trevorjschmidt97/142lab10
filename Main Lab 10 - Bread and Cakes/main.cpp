//Trevor Schmidt - Main Lab 10 - Section 4 - trevorjschmidt97@gmail.com

#include "CupCake.h"
#include "LayerCake.h"
#include "Bread.h"

void ToStringFunction(vector<BakedGood*> pointerVector) {
	for (unsigned int i = 0; i < pointerVector.size(); ++i) {
		cout << pointerVector.at(i)->ToString() << endl;
	}
}

int main() {
	vector<BakedGood*> pointerVector;
	string userInput = "none";
	string bakedGoodInput = "none";
	int quantityInput = 0;
	string breadVarietyInput = "none";
	string flavorInput = "none";
	string frostingInput = "none";
	int numOfLayersInput = 0;
	string sprinkleColorInput = "none";

	cout << "**Bread and Cakes Bakery**" << endl << endl;

	// USER INPUT WHILE LOOP************************************************************************
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	while (userInput != "done") {
		cout << "Sub-order: ";
		getline(cin, userInput);
		stringstream ss(userInput);

		ss >> bakedGoodInput;

		//IF BREAD, PROCEED TO GET breadVariety, AND QUANTITY
		if (bakedGoodInput == "Bread") {
			ss >> breadVarietyInput >> quantityInput;
			for (int i = 0; i < quantityInput; ++i) {
				Bread* bread = new Bread;
				bread->breadVariety = breadVarietyInput;
				pointerVector.push_back(bread);
			}
		}

		//IF CUPCAKE, PROCEED TO GET flavor, frosting, sprinkleColor, AND QUANTITY
		if (bakedGoodInput == "Cupcake") {
			ss >> flavorInput >> frostingInput >> sprinkleColorInput >> quantityInput;
			for (int i = 0; i < quantityInput; ++i) {
				CupCake* cupcake = new CupCake;
				cupcake->flavor = flavorInput;
				cupcake->frosting = frostingInput;
				cupcake->sprinkleColor = sprinkleColorInput;
				if (frostingInput == "cream-cheese") {
					cupcake->price = cupcake->price + .20; // Add $.20 if CupCake has Cream-Cheese Frosting
				}
				pointerVector.push_back(cupcake);
			}
		}

		//IF LAYERCAKE, PROCEED TO GET flavor, frosting, numOfLayers, AND QUANTITY
		else if (bakedGoodInput == "Layer-cake") {
			ss >> flavorInput >> frostingInput >> numOfLayersInput >> quantityInput;
			for (int i = 0; i < quantityInput; ++i) {
				LayerCake* layercake = new LayerCake;
				layercake->flavor = flavorInput;
				layercake->frosting = frostingInput;
				layercake->numOfLayers = numOfLayersInput;
				if (frostingInput == "cream-cheese") {
					layercake->price = layercake->price + (1 * numOfLayersInput); //Add $1.00 per layer if LayerCake has Cream-Cheese Frosting
				}
				if (numOfLayersInput > 1) {
					for (int i = 0; i < numOfLayersInput - 1; ++i) {
						layercake->price = layercake->price + 3; //Add $3.00 per layer beyond 1
					}
				}
				pointerVector.push_back(layercake);
			}
		}
	}
	cout << endl;
	
	// CALLS TO FUNCTION THAT PRINTS OUT ALL ORDER COMBINATIONS*************************************
	cout << "Order Confirmations:" << endl;
	ToStringFunction(pointerVector);
	cout << endl;

	//PRINTS INVOICE********************************************************************************
	int totalQuantity = 0;
	double totalCost = 0.0;

	cout << "Invoice: " << endl;
	cout << setw(75) << left << "Baked Good" << setw(9) << right << "Quantity" << setw(9) << right << "Total" << endl;

	for (unsigned int i = 0; i < pointerVector.size(); ++i) {
		string uniqueGood = pointerVector.at(i)->ToString();
		int quantityGood = 1;

		for (unsigned int j = i + 1; j < pointerVector.size(); ++j) {
			if (pointerVector.at(j)->ToString() == uniqueGood) {
				++quantityGood;
				pointerVector.erase(pointerVector.begin() + j);
				--j;
			}
		}

		totalQuantity = totalQuantity + quantityGood;
		totalCost = totalCost  + pointerVector.at(i)->GetDiscountedPrice(quantityGood);

		cout << setw(75) << left << uniqueGood << setw(9) << right
   		     << quantityGood << setw(9) << right << fixed << setprecision(2) << pointerVector.at(i)->GetDiscountedPrice(quantityGood) << endl;
	}

	cout << setw(75) << left << "Totals" << setw(9) << right << totalQuantity 
		 << setw(9) << right << fixed << setprecision(2) << totalCost << endl;


	cout << "Good Bye" << endl;

	system("pause");
	return 0;
}