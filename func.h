#pragma once
#include<vector>
#include"product.h"

std::vector<Product> get_stock();
void print_assortment();

inline void print_help() {
	std::cout
		<< "\nh - ������� ������ �������\n"
		<< "a - ������� ����������� ��������\n"
		<< "� - �������� ���������� ������ � ��������\n"
		<< "b - �������� ������ � �������\n\n";
};