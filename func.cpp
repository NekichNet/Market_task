#include"func.h"

std::vector<Product> get_stock() {
	return std::vector<Product>{
		Product{ "Сок \"Яблоко\"", 159.99 },
		Product{ "Cок \"Апельсин\"", 169.99 },
		Product{ "Сок \"Абрикос\"", 184.99 },
		Product{ "Сок \"Груша\"", 149.99 },
		Product{ "Томатный сок", 209.99 },
		Product{ "Луковый сок", 139.99 },
		Product{ "Огуречный сок", 174.99 },
		Product{ "Чесночный чай", 68.99 },
		Product{ "Петрушевый чай", 49.99 }
	};
}

void print_assortment() {
	std::vector<Product> stock = get_stock();
	std::cout << std::endl;
	for (int i = 0; i < stock.size(); i++) {
		std::cout << " | " << i << ".\t" << stock[i].name << " - " << stock[i].price_for_each << " руб.\t\t|\n";
	}
	std::cout << std::endl;
}