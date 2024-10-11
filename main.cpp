#include<Windows.h>
#include"func.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\t------------------------\n" <<
		"\t| ������� \"���� ������\" |\n" <<
		"\t------------------------\n\n";
	print_assortment();
	print_help();

	char continuing = 'n';

	do { // ���� ������� � �������
		std::vector<Product> purchases = get_stock();
		char command{};
		do { // ���� ����� ������
			std::cout << "������� �������: ";
			std::cin >> command;

			if (command == 'c' || command == 'C') { // ��������� ���-�� �������� � �������
				unsigned short product_id, product_quantity;
				do {
					std::cout << "������� ����� ��������: ";
					std::cin >> product_id;
				} while (product_id >= purchases.size());
				std::cout << "������� ������ ���������� ������ �������� [" <<
					purchases[product_id].name << "]: ";
				std::cin >> purchases[product_id].quantity;
			}
			else if (command == 'h' || command == 'H') { print_help(); }
			else if (command == 'a' || command == 'A') { print_assortment(); }
		} while (command != 'b' && command != 'B');

		for (int i = 0; i < purchases.size(); i++) {// ��������� ����
			if (purchases[i].quantity > 0) {
				double result_overall_price, overall_price = 0;
				std::cout << " |\t\t\t\t\t-------\t\t\t\t\t\t|\n |\t\t\t\t\t| ��� |" <<
					"\t\t\t\t\t\t|\n | \t\t\t\t\t-------\t\t\t\t\t\t|\n" <<
					" |\t������������\t\t���-��\t�����\t\t������\t\t�����\t\t|\n";
				for (int j = 0; j < purchases.size(); j++) {
					if (purchases[j].quantity > 0) {
						purchases[j].calculate();
						overall_price += purchases[j].result_price;
						std::cout << " |\t" << purchases[j].name <<
							"\t\t" << purchases[j].quantity << " ��." <<
							"\t" << purchases[j].native_result_price << " ���." <<
							"\t" << purchases[j].discounted << "���." <<
							"\t\t" << purchases[j].result_price << "���.\t|\n";
					}
				}
				bool is_all_tea = true;
				for (int j = 7; j < 11; j++) {
					if (purchases[j].quantity == 0) { is_all_tea = false; }
				}
				result_overall_price = overall_price;
				if (is_all_tea) { result_overall_price = discount("all_tea", result_overall_price, 1); }
				result_overall_price = discount("all", result_overall_price, 1);
				std::cout << " |\t�����\t\t\t\t\t\t" << overall_price << "\t\t" << result_overall_price << "\t\t|\n";
				break;
			}
		}
		std::cout << "���������� ������� � ��������? (y/n) ";
		std::cin >> continuing;
	} while (continuing == 'y' || continuing == 'Y');

	return 0;
}