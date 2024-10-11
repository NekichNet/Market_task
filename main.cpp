#include<Windows.h>
#include"func.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\t------------------------\n" <<
		"\t| Магазин \"Соки Никиты\" |\n" <<
		"\t------------------------\n\n";
	print_assortment();
	print_help();

	char continuing = 'n';

	do { // Цикл заходов в магазин
		std::vector<Product> purchases = get_stock();
		char command{};
		do { // Цикл ввода команд
			std::cout << "Введите команду: ";
			std::cin >> command;

			if (command == 'c' || command == 'C') { // Изменение кол-ва продукта в корзине
				unsigned short product_id, product_quantity;
				do {
					std::cout << "Введите номер продукта: ";
					std::cin >> product_id;
				} while (product_id >= purchases.size());
				std::cout << "Введите нужное количество литров продукта [" <<
					purchases[product_id].name << "]: ";
				std::cin >> purchases[product_id].quantity;
			}
			else if (command == 'h' || command == 'H') { print_help(); }
			else if (command == 'a' || command == 'A') { print_assortment(); }
		} while (command != 'b' && command != 'B');

		for (int i = 0; i < purchases.size(); i++) {// Выведение чека
			if (purchases[i].quantity > 0) {
				double result_overall_price, overall_price = 0;
				std::cout << " |\t\t\t\t\t-------\t\t\t\t\t\t|\n |\t\t\t\t\t| ЧЕК |" <<
					"\t\t\t\t\t\t|\n | \t\t\t\t\t-------\t\t\t\t\t\t|\n" <<
					" |\tНАИМЕНОВАНИЕ\t\tКОЛ-ВО\tСУММА\t\tСКИДКА\t\tИТОГО\t\t|\n";
				for (int j = 0; j < purchases.size(); j++) {
					if (purchases[j].quantity > 0) {
						purchases[j].calculate();
						overall_price += purchases[j].result_price;
						std::cout << " |\t" << purchases[j].name <<
							"\t\t" << purchases[j].quantity << " шт." <<
							"\t" << purchases[j].native_result_price << " руб." <<
							"\t" << purchases[j].discounted << "руб." <<
							"\t\t" << purchases[j].result_price << "руб.\t|\n";
					}
				}
				bool is_all_tea = true;
				for (int j = 7; j < 11; j++) {
					if (purchases[j].quantity == 0) { is_all_tea = false; }
				}
				result_overall_price = overall_price;
				if (is_all_tea) { result_overall_price = discount("all_tea", result_overall_price, 1); }
				result_overall_price = discount("all", result_overall_price, 1);
				std::cout << " |\tИТОГО\t\t\t\t\t\t" << overall_price << "\t\t" << result_overall_price << "\t\t|\n";
				break;
			}
		}
		std::cout << "Продолжите покупки в магазине? (y/n) ";
		std::cin >> continuing;
	} while (continuing == 'y' || continuing == 'Y');

	return 0;
}