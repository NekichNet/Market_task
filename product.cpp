#include"product.h"

double discount(std::string name, double price, unsigned short quantity) {
	if (name == "���������� ���" && quantity == 3) {
		return 0.95 * price;
	}
	else if (name == "������� ���") {
		return price - quantity / 4 * (price / quantity);
	}
	else if (name == "all" && price > 800.0) {
		return 0.87 * price;
	}
	else {
		return price;
	}
}