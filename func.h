#pragma once
#include<vector>
#include"product.h"

std::vector<Product> get_stock();
void print_assortment();

inline void print_help() {
	std::cout
		<< "\nh - Вывести список комманд\n"
		<< "a - Вывести ассортимент магазина\n"
		<< "с - Изменить количество товара в магазине\n"
		<< "b - Оплатить товары в корзине\n\n";
};