#include"func.h"

std::vector<Product> get_stock() {
	return std::vector<Product>{
		Product{ "��� \"������\"", 159.99 },
		Product{ "C�� \"��������\"", 169.99 },
		Product{ "��� \"�������\"", 184.99 },
		Product{ "��� \"�����\"", 149.99 },
		Product{ "�������� ���", 209.99 },
		Product{ "������� ���", 139.99 },
		Product{ "��������� ���", 174.99 },
		Product{ "��������� ���", 68.99 },
		Product{ "���������� ���", 49.99 }
	};
}

void print_assortment() {
	std::vector<Product> stock = get_stock();
	std::cout << std::endl;
	for (int i = 0; i < stock.size(); i++) {
		std::cout << " | " << i << ".\t" << stock[i].name << " - " << stock[i].price_for_each << " ���.\t\t|\n";
	}
	std::cout << std::endl;
}