#pragma once
#include<iostream>

double discount(std::string name, double price, unsigned short quantity);
struct Product {
	std::string name;
	double price_for_each;
	unsigned short quantity = 0;
	double discounted = 0;
	double native_result_price = 0;
	double result_price = 0;
	void calculate() {
		native_result_price = price_for_each * quantity;
		result_price = discount(name, native_result_price, quantity);
		discounted = native_result_price - result_price;
	}
};